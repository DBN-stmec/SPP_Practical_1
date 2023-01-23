cmake_minimum_required (VERSION 3.11)
project(spp-practical-omp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

option(SPP_WITH_QT "Build Project with Qt Gui." OFF)
option(SPP_WITH_OPENMP "Build Project with OpenMP support." OFF)
option(SPP_WITH_TSAN "Build with ThreadSanitizer race detector." OFF)

set(SPP_LOG_LEVEL 2 CACHE STRING "Granularity of logger. 3 is most verbose, 0 is least.")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

if(NOT CMAKE_BUILD_TYPE)
  # set default build type
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "" FORCE)
  message(STATUS "Building with debug mode (default)")
endif()

if(SPP_WITH_TSAN)
  message(STATUS "Compile with TSan requested: "
      "Use a Clang compiler with Tsan-support for libomp. "
      "Before execution also do \"export TSAN_OPTIONS='ignore_noninstrumented_modules=1'\"")
endif()

if(SPP_WITH_QT)
	find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)

	message(STATUS "Qt5 Gui support activated.")

	set(CMAKE_AUTOMOC ON)
	set(CMAKE_AUTOUIC ON)
	set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/include/gui)
else()
	message(STATUS "Qt Gui support NOT requested.")
endif()

if(SPP_WITH_OPENMP)
	find_package(OpenMP REQUIRED)
	message(STATUS "OpenMP support activated.")
else()
	message(STATUS "OpenMP support NOT requested.")
endif()

add_subdirectory(src)
