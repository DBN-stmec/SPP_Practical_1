/*
 * SimulationGUI.h
 *
 *  Created on: Dec 15, 2014
 *      Author: ahueck
 *
 * GUI of the Nbody problem. No change is supposed to happen here.
 */

#ifndef SIMULATIONGUI_H_
#define SIMULATIONGUI_H_

#include <qwidget.h>

namespace Ui {
class MainView;
}

class QTimer;
class QGraphicsScene;
class QElapsedTimer;
class QPen;

namespace practical::nbody {

class SimGUIAdapter;

namespace ui {

class SimulationGUI : public QWidget {
  Q_OBJECT
 private:
  SimGUIAdapter& nbody_sim;
  Ui::MainView* view;
  QGraphicsScene* scene;
  QTimer* compute_timer;
  QElapsedTimer* time;
  QPen* pen_body;
  qint32 frame_counter;
  qint64 time_start;
  float mass_min;
  float mass_factor;

 public:
  SimulationGUI(SimGUIAdapter& nbody_sim);
  void init();
  ~SimulationGUI();

 private:
  void addBody(float px, float py, float mass, float vx = 0.0, float vy = 0.0);

 private slots:
  void startComputation();
  void stopComputation();
  void compute();
};

} /* namespace ui */
}  // namespace practical::nbody

#endif /* SIMULATIONGUI_H_ */
