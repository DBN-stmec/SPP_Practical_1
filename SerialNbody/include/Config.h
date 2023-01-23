/*
 * Config.h
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 *
 * Reads/Writes simulation files. Can also write randomly generated simulation files.
 */
#ifndef CONFIG_H_
#define CONFIG_H_

#include "SimulationData.h"

#include <vector>

namespace practical::nbody {

class Config {
 private:
  std::string m_file_in;
  std::string m_file_out;

 public:
  Config(const std::string& infile, const std::string& outfile);

  /**
   * Read simulation file and set the passed references to the content of the file
   * Uses variable "infile"
   */
  [[nodiscard]] bool read(SimulationData& sim_data) const;

  /**
   * Randomly generate content of a simulation and write to a file
   */
  [[nodiscard]] static bool randomGeneration(const std::string& file, unsigned num_steps, unsigned num_bodies);

  /**
   * Write simulation file with passed values
   * Uses variable "outfile"
   */
  [[nodiscard]] bool write(const SimulationData& data) const;
};

}  // namespace practical::nbody

#endif /* CONFIG_H_ */
