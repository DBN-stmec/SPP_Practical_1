/*
 * Simulation.h
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "SimGUIAdapter.h"
#include "SimulationData.h"

#include <vector>

namespace practical::nbody {

class Simulation final : public SimGUIAdapter {
 private:
  SimulationData m_sim_data;

 public:
  explicit Simulation(SimulationData data);

  /**
   * Run simulation "num_step" times
   */
  void run();

  /**
   * @see SimGUIAdapter.h
   * TODO needs to be completed
   */
  void nextTimestep() override;

  [[nodiscard]] const SimulationData& simulationState() const override;

  ~Simulation() override;

 private:
  /**
   * Handles collision between bodies before a time step
   * TODO Needs to be completed
   */
  void handleCollisions();
};

}  // namespace practical::nbody

#endif /* SIMULATION_H_ */
