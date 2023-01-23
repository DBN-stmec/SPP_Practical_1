/*
 * SimulationGUI.cpp
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 *
 */

#include "gui/SimulationGUI.h"

#include "Logger.h"
#include "SimGUIAdapter.h"
#include "ui_nbody.h"

#include <QElapsedTimer>
#include <QTimer>
#include <cmath>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>

namespace practical::nbody::ui {

SimulationGUI::SimulationGUI(SimGUIAdapter& nbody_sim)
    : QWidget(0),
      nbody_sim(nbody_sim),
      view(new Ui::MainView),
      frame_counter(0),
      time_start(0),
      mass_min(0.0),
      mass_factor(1.0) {
  view->setupUi(this);
  scene = new QGraphicsScene(view->graphics_view);
  // scene->setSceneRect(-0.01, -0.1, .050, .10);
  scene->setSceneRect(-0.1, -0.1, .4, .4);
  view->graphics_view->setScene(scene);

  view->button_stop->setEnabled(false);
  connect(view->button_stop, SIGNAL(clicked()), this, SLOT(stopComputation()));

  connect(view->button_start, SIGNAL(clicked()), this, SLOT(startComputation()));

  compute_timer = new QTimer(this);
  connect(compute_timer, SIGNAL(timeout()), this, SLOT(compute()));

  view->graphics_view->fitInView(scene->sceneRect(), Qt::KeepAspectRatioByExpanding);

  time     = new QElapsedTimer();
  pen_body = new QPen(Qt::white);
  pen_body->setCosmetic(true);
}

void SimulationGUI::addBody(float px, float py, float mass, float vx, float vy) {
  if (mass > 0.0) {
    const auto size_of_body = [&](float mass, float from, float to) {
      return std::min((to - from) * (mass - mass_min) / mass_factor + from, to);
    };
    const qreal size  = 0.08;  // sizeOfBody(mass, 0.06, 0.11);
    const qreal h     = 0.5 * size;
    const int cOffset = static_cast<int>(255.0f - size_of_body(mass, 0, 255));
    scene->addEllipse(px - h, py - h, size, size, *pen_body, QBrush(QColor(cOffset, 40, cOffset)));

    double length = std::sqrt(vx * vx + vy * vy);
    const qreal x1 = px;
    const qreal y1 = py;
    const qreal x2 = x1 + h * (vx / length);
    const qreal y2 = y1 + h * (vy / length);
    scene->addLine(x1, y1, x2, y2, *pen_body);
  } else {
    LOG_ERROR("Mass less or equal to zero.");
  }
}

void SimulationGUI::compute() {
  const auto visualize = [&]() {
    const auto& sim_data = nbody_sim.simulationState();
    const float n        = 1.0f / sim_data.scale;
    for (const auto& b_i : sim_data.bodies) {
      if (b_i.mass() != 0.0f) {
        const Vec2f pos = b_i.position() * n;
        const Vec2f& v  = b_i.velocity();
        addBody(pos[0], pos[1], b_i.mass(), v[0], v[1]);
      }
    }
  };

  nbody_sim.nextTimestep();
  scene->clear();
  visualize();
  scene->update();
  view->graphics_view->update();
  view->lcd_fps->display(frame_counter / static_cast<double>((time->elapsed() - time_start)) * 1000.0);
  view->lcd_timestep->display(++frame_counter);
}

void SimulationGUI::startComputation() {
  view->button_stop->setEnabled(true);
  view->button_start->setEnabled(false);
  view->lcd_timestep->display(frame_counter);
  time->start();
  time_start = time->restart();
  compute_timer->start(30);
}

void SimulationGUI::stopComputation() {
  view->button_stop->setEnabled(false);
  view->button_start->setEnabled(true);
  compute_timer->stop();
}

void SimulationGUI::init() {
  const auto setMass = [&](auto min, auto max) {
    mass_min    = min;
    mass_factor = max - min;
    if (std::fabs(mass_factor) < 0.0001) {
      mass_factor = 1.0;
    }
  };

  const auto& sim_data = nbody_sim.simulationState();
  const auto& [min_mass, max_mass] =
      std::minmax_element(std::begin(sim_data.bodies), std::end(sim_data.bodies),
                          [](const auto& b1, const auto& b2) { return b1.mass() < b2.mass(); });
  setMass(min_mass->mass(), max_mass->mass());
}

SimulationGUI::~SimulationGUI() {
  delete time;
}

} /* namespace practical */
