/*
 * SimGUIAdapter.h
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 *
 *  Used to interface with the Qt GUI implementation.
 *  You are responsible to complete the methods in order to get a correct visualization.
 */

#ifndef SIMGUIADAPTER_H_
#define SIMGUIADAPTER_H_

#include "SimulationData.h"

namespace practical::nbody {

class SimGUIAdapter {
 public:
  /**
   * Calculates one timestep of the simulation. If GUI is used, it will call this method repeatedly to advance the
   * simulation.
   */
  virtual void nextTimestep() = 0;

  [[nodiscard]] virtual const SimulationData& simulationState() const = 0;

  virtual ~SimGUIAdapter() = default;
};

}  // namespace practical::nbody

#endif /* SIMGUIADAPTER_H_ */
