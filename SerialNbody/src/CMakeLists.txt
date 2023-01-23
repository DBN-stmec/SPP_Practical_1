add_executable(spp-nbody-omp
  OmpPractical.cpp
  Body.cpp
  Simulation.cpp
  Config.cpp
  $<$<BOOL:${SPP_WITH_QT}>:gui/SimulationGUI.cpp ../include/gui/nbody.ui ../include/gui/SimulationGUI.h>
)

target_include_directories(spp-nbody-omp PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
)

target_link_libraries(spp-nbody-omp PUBLIC
  $<$<BOOL:${SPP_WITH_OPENMP}>:OpenMP::OpenMP_CXX>
  $<$<BOOL:${SPP_WITH_QT}>:Qt5::Core>
  $<$<BOOL:${SPP_WITH_QT}>:Qt5::Widgets>
  $<$<BOOL:${SPP_WITH_QT}>:Qt5::Gui>
)

target_compile_definitions(spp-nbody-omp PUBLIC
  LOG_LEVEL=${SPP_LOG_LEVEL}
  $<$<BOOL:${SPP_WITH_QT}>:SPP_WITH_QT>
  $<$<BOOL:${SPP_WITH_OPENMP}>:SPP_WITH_OPENMP>
)

target_compile_options(spp-nbody-omp PRIVATE
  -Wall
)

target_compile_options(spp-nbody-omp PUBLIC
  $<$<BOOL:${SPP_WITH_TSAN}>:-fsanitize=thread>
)

target_link_options(spp-nbody-omp PUBLIC
  $<$<BOOL:${SPP_WITH_TSAN}>:-fsanitize=thread>
)
