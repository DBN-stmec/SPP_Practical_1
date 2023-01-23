/*
 * PTime.h
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 *
 *  Function "now" used for accurate performance measurements
 *
 */

#ifndef PTIME_H_
#define PTIME_H_

#include <chrono>

namespace practical::nbody::time {

using time_point_t = decltype(std::chrono::high_resolution_clock::now());

inline time_point_t now() {
  using namespace std::chrono;
  const auto now = high_resolution_clock::now();
  return now;
}

inline double diff(const time_point_t& start, const time_point_t& end) {
  using namespace std::chrono;
  const auto time_span = duration_cast<duration<double>>(end - start);
  return time_span.count();
}

}  // namespace practical::nbody::time

#endif /* PTIME_H_ */
