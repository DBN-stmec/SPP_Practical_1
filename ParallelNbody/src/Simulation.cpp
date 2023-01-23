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
  handleCollisions(); 
  int j;                                  // update number of bodies
#pragma omp parallel for private(j)                     // Parallization
  for (int i = 0; i < m_sim_data.bodies.size(); i++) {  // Iteration durch alle bodies
    if (m_sim_data.bodies[i].mass() != 0) {
      for (j = 0; j < m_sim_data.bodies.size(); j++) {
        if (i!=j &&m_sim_data.bodies[j].mass() != 0) {
          m_sim_data.bodies[i].applyForces(m_sim_data.bodies[j]);

        }  // another loop for update
      }
    }
  }
#pragma omp parallel for
      for (int k = 0; k < m_sim_data.bodies.size(); k++) {
        m_sim_data.bodies[k].update(m_sim_data.dt);
        m_sim_data.bodies[k].resetAcceleration();
      }
}

void Simulation::handleCollisions() {
  // TODO handle collision per timestep (before updating forces)

std::vector<std::pair<int,int>> collisionList;
std::pair<int,int> collisionIndices;
int j;
#pragma omp parallel for private(j)
  for (int i = 0; i < m_sim_data.bodies.size(); i++) {
     for (j = i+1; j < m_sim_data.bodies.size(); j++) {
      if (i!=j &&m_sim_data.bodies[i].distanceTo(m_sim_data.bodies[j]) < m_sim_data.distance) {
        #pragma omp critical
        {
          collisionIndices.first=i;
          collisionIndices.second=j;
          collisionList.push_back(collisionIndices);
        }
      }
    }
  }

for(int k = 0; k < collisionList.size(); k++){
  int body1 = collisionList[k].first;
  int body2 = collisionList[k].second;
  if(m_sim_data.bodies[body1].mass() != 0 && m_sim_data.bodies[body2].mass() != 0){
    
      float mass = m_sim_data.bodies[body1].mass() + m_sim_data.bodies[body2].mass();
          m_sim_data.bodies[body1].velocity() = ((m_sim_data.bodies[body1].velocity().operator*(m_sim_data.bodies[body1].mass())) +
                                                (m_sim_data.bodies[body2].velocity().operator*(m_sim_data.bodies[body2].mass()))).operator/(mass);
                                            
          m_sim_data.bodies[body1].mass() = mass;
          m_sim_data.bodies[body2].mass() = 0;
      }
    }
}


const SimulationData& Simulation::simulationState() const {
  return m_sim_data;
}

Simulation::~Simulation() = default;

}  // namespace practical::nbody
