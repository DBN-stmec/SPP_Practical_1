//============================================================================
// Name        : Practical Omp Task
// Author      : ahueck
// Version     : 1.0
// Description : Main entry point. In principle, nothing to be done here.
//============================================================================

#include "Config.h"
#include "Logger.h"
#include "PTime.h"
#include "Simulation.h"

#ifdef _OPENMP
#include <omp.h>
#endif

#ifdef SPP_WITH_QT
#include <gui/SimulationGUI.h>
#include <qapplication.h>
#endif

int main(int argc, char** argv) {
  using namespace practical::nbody;
  if (argc < 2) {
    LOG_INFO("Needs input file for simulation.");
    std::exit(EXIT_FAILURE);
  }

  const std::string file_in  = argv[1];
  const std::string file_out = [&]() -> std::string {
    if (argc > 2) {
      return argv[2];
    }
    return "";
  }();

  {
    if (file_in == "-g" && argc == 5) {
      const auto num_steps  = std::stoi(argv[3]);
      const auto num_bodies = std::stoi(argv[4]);
      const auto generated  = Config::randomGeneration(file_out, num_steps, num_bodies);
      if (!generated) {
        LOG_ERROR("Could not write randomized sim file to " << file_out);
        std::exit(EXIT_FAILURE);
      }
      std::exit(EXIT_SUCCESS);
    }
  }

#ifdef _OPENMP
  LOG_INFO("With OpenMP support compiled. Max. # threads: " << omp_get_max_threads());
#endif

  SimulationData sim_data;
  Config config(file_in, file_out);
  if (!config.read(sim_data)) {
    LOG_FATAL("Initializing data failed with file " << file_in);
    std::exit(EXIT_FAILURE);
  }

  LOG_MSG("Initializing data success");
  Simulation sim_driver(sim_data);
#ifdef SPP_WITH_QT
  QApplication app(argc, argv);
  ui::SimulationGUI view(sim_driver);
  view.init();
  view.show();
  return app.exec();
#else
  const auto start = time::now();
  sim_driver.run();
  const auto end = time::now();

  LOG_MSG("Time for simulation: " << time::diff(start, end) << "s");
  if (!file_out.empty() && !config.write(sim_driver.simulationState())) {
    LOG_INFO("Could not write sim data to file " << file_out);
  }

  return EXIT_SUCCESS;
#endif
}
