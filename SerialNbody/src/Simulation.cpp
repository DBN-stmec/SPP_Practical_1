/*
 * Simulation.cpp
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 */

#include "Simulation.h"

#include "Body.h"  //Hinzugefügt
#include "Logger.h"
#include "Vec2.h"

namespace practical::nbody {

Simulation::Simulation(SimulationData data) : m_sim_data(std::move(data)) {
}

void Simulation::run() {
  for (unsigned int step = 0; step < m_sim_data.num_steps; ++step) {
    nextTimestep();
  }
}

void Simulation::nextTimestep() {
  // TODO implement N-body calculation according to the exercise sheet.
  // per timestep: Parallizing collision
  handleCollisions();                                   // update number of bodies
                  // Parallization
  for (int i = 0; i < m_sim_data.bodies.size(); i++) {  // Iteration durch alle bodies
    if (m_sim_data.bodies[i].mass() != 0) {
      for (int j = 0; j < m_sim_data.bodies.size(); j++) {
        if (i != j && m_sim_data.bodies[j].mass() != 0) {
          m_sim_data.bodies[i].applyForces(m_sim_data.bodies[j]);
        }
      }
    }
  }
  for (int k = 0; k < m_sim_data.bodies.size(); k++) {
    m_sim_data.bodies[k].update(m_sim_data.dt);
    m_sim_data.bodies[k].resetAcceleration();
  }
}

void Simulation::handleCollisions() {
  // TODO handle collision per timestep (before updating forces)
  for (int i = 0; i < m_sim_data.bodies.size(); i++) {
    for (int j = i+1; j < m_sim_data.bodies.size(); j++) {
      if (m_sim_data.bodies[i].distanceTo(m_sim_data.bodies[j]) < m_sim_data.distance && m_sim_data.bodies[i].mass() != 0 && m_sim_data.bodies[j].mass() != 0) {
          float mass = m_sim_data.bodies[i].mass() + m_sim_data.bodies[j].mass();
          m_sim_data.bodies[i].velocity() = ((m_sim_data.bodies[i].velocity().operator*(m_sim_data.bodies[i].mass())) +
                                                (m_sim_data.bodies[j].velocity().operator*(m_sim_data.bodies[j].mass()))).operator/(mass);
                                            
          m_sim_data.bodies[i].mass() = mass;
          m_sim_data.bodies[j].mass() = 0;
        
      }
    }
  }
}


const SimulationData& Simulation::simulationState() const {
  return m_sim_data;
}

Simulation::~Simulation() = default;

}  // namespace practical::nbody
