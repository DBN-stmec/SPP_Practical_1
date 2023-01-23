/*
 * SimulationData.h
 *
 *  Created on: Aug 23, 2022
 *      Author: ahueck
 */

#ifndef SIMULATIONDATA_H
#define SIMULATIONDATA_H

#include "Body.h"

#include <vector>

namespace practical::nbody {

struct SimulationData {
  std::vector<Body> bodies;
  /**
   * Time step
   */
  float dt;
  /**
   * Used to scale position variables to ~[-1, 1] in order to fit them into the GUI window
   */
  float scale;
  /**
   * Distance when bodies are supposed to collide
   */
  float distance;
  /**
   * Number of (time) steps for the simulation
   * Ignored when the GUI is active
   */
  unsigned int num_steps;
};

}  // namespace practical::nbody

#endif  // SIMULATIONDATA_H
