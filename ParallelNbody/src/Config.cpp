/*
 * Config.cpp
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 */

#include "Config.h"
#include "Logger.h"

#include <fstream>
#include <iostream>
#include <random>

namespace practical::nbody {

Config::Config(const std::string& infile, const std::string& outfile) : m_file_in(infile), m_file_out(outfile) {
}

bool Config::read(SimulationData& sim_data) const {
  if (m_file_in.empty()) {
    LOG_INFO("Empty string for file path.");
    return false;
  }

  std::ifstream sim_file;
  sim_file.open(m_file_in.c_str());
  if (!sim_file.good()) {
    LOG_ERROR("Reading file '" << m_file_in << "' failed.");
    return false;
  }

  unsigned int num_bodies  = 0;
  unsigned int row_counter = 0;
  float mass               = 0.0f;
  Vec2f pos, v;

  sim_file >> sim_data.num_steps >> num_bodies >> sim_data.dt >> sim_data.scale >> sim_data.distance;
  sim_data.bodies.reserve(num_bodies);
  while (row_counter++ < num_bodies && sim_file >> pos[0] >> pos[1] >> v[0] >> v[1] >> mass) {
    sim_data.bodies.emplace_back(pos, v, mass);
  }
  sim_file.close();

  return true;
}

bool Config::randomGeneration(const std::string& file, unsigned num_steps, unsigned num_bodies) {
  static const float MAX_POS  = 2.0f;
  static const float MAX_V    = 0.25f;
  static const float MAX_MASS = 1.0f;
  static const float DELTA_T  = 0.01f;
  static const float SCALE    = 1.0f;
  static const float DIST     = 0.01f;

  std::ofstream sim_file;
  sim_file.open(file.c_str());
  if (!sim_file.good()) {
    LOG_ERROR("Writing to file '" << file << "' failed.");
    return false;
  }

  std::random_device random_device;
  std::mt19937 random_engine(random_device());
  std::uniform_real_distribution<float> distribution_0_1(0.f, 1.f);
  const auto rand_v = [&]() { return distribution_0_1(random_engine); };

  sim_file << num_steps << std::endl
           << num_bodies << std::endl
           << DELTA_T << std::endl
           << SCALE << std::endl
           << DIST << std::endl;
  for (int i = 0; i < num_bodies; ++i) {
    sim_file << (MAX_POS * rand_v()) - MAX_POS * 0.5f << " ";
    sim_file << (MAX_POS * rand_v()) - MAX_POS * 0.5f << " ";

    sim_file << 2.0f * MAX_V * rand_v() - MAX_V << " ";
    sim_file << 2.0f * MAX_V * rand_v() - MAX_V << " ";

    sim_file << MAX_MASS * std::max(rand_v(), 0.1f);
    sim_file << std::endl;
  }

  sim_file.close();

  return true;
}

bool Config::write(const SimulationData& sim_data) const {
  if (m_file_out.empty()) {
    LOG_INFO("Empty string for file path.");
    return false;
  }

  std::ofstream sim_file;
  sim_file.open(m_file_out.c_str());
  if (!sim_file.good()) {
    LOG_ERROR("Writing to file '" << m_file_out << "' failed.");
    return false;
  }
  sim_file << sim_data.num_steps << std::endl
           << sim_data.bodies.size() << std::endl
           << sim_data.dt << std::endl
           << sim_data.scale << std::endl;

  for (const auto& body : sim_data.bodies) {
    const Vec2f& pos = body.position();
    const Vec2f& v   = body.velocity();
    float mass       = body.mass();

    sim_file << pos[0] << " " << pos[1] << " " << v[0] << " " << v[1] << " " << mass << " " << sim_data.distance
             << std::endl;
  }

  sim_file.close();

  return true;
}

}  // namespace practical::nbody
