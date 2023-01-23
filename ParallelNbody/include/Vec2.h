/*
 * Vec.h
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 *
 *  2D Vector for simple arithmetic. Vec2f (Vector<float>) provided as typedef
 */

#ifndef VEC_H_
#define VEC_H_

#include <cassert>
#include <cmath>
#include <iostream>

namespace practical::nbody {

template <typename T>
class Vector {
 private:
  T m_data[2];

 public:
  Vector() = default;

  Vector(const T x, const T y) {
    m_data[0] = x;
    m_data[1] = y;
  }

  T& operator[](unsigned int n) {
    assert(n < 2);
    return m_data[n];
  }

  void reset(T value = T(0.0)) {
    m_data[0] = value;
    m_data[1] = value;
  }

  const T& operator[](unsigned int n) const {
    assert(n < 2);
    return m_data[n];
  }

  Vector<T> operator+(const Vector<T>& v) const {
    return {m_data[0] + v.m_data[0], m_data[1] + v.m_data[1]};
  }

  Vector<T>& operator+=(const Vector<T>& v) {
    m_data[0] += v.m_data[0];
    m_data[1] += v.m_data[1];
    return *this;
  }

  Vector<T> operator-(const Vector<T>& v) const {
    return {m_data[0] - v.m_data[0], m_data[1] - v.m_data[1]};
  }

  T operator*(const Vector<T>& v) const {
    return m_data[0] * v.m_data[0] + m_data[1] * v.m_data[1];
  }

  Vector<T> operator*(const T s) const {
    Vector<T> result(s * m_data[0], s * m_data[1]);
    return result;
  }

  Vector<T> operator/(const T s) const {
    assert(s != 0);
    Vector<T> result(m_data[0] / s, m_data[1] / s);
    return result;
  }

  Vector<T> operator+(const T s) const {
    Vector<T> result(m_data[0] + s, m_data[1] + s);
    return result;
  }

  T length(T eps = T(0.0)) const {
    return sqrt(*this * *this + eps);
  }

  T distance(const Vector<T>& other) const {
    const Vector<T> delta = *this - other;
    return std::sqrt(delta * delta);
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
  return os << "[" << vec[0] << ", " << vec[1] << "]";
}

using Vec2f = Vector<float>;

}  // namespace practical::nbody

#endif /* VEC_H_ */
