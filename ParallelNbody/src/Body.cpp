/*
 * Body.cpp
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 */

#include "Body.h"

#include "Logger.h"
#include "Vec2.h"

namespace practical::nbody {

Body::Body(const Vec2f& pos, const Vec2f& v, const float mass) : m_pos(pos), m_v(v), m_a(), m_mass(mass) {
}

void Body::update(float dt) {
  // TODO update Body's speed "v" and position "pos" based on acceleration and timestep dt  
    m_v   = m_v.operator+(m_a.operator*(dt));
    m_pos = m_pos.operator+(m_v.operator*(dt));
  
}

void Body::applyForces(const Body& other) {
  // TODO update Body's acceleration based on "other"
  static const float eps = 0.0001f;
  static const float G   = 6.673e-11f;
  Vec2f delta;  // Creat vector with 2 float entries
  float r, fac;

  delta = other.m_pos.operator-(m_pos);
  r   = sqrt(pow(delta[0], 2) + pow(delta[1], 2) + eps);  // distance between two bodies
  fac = 1 / pow(r, 3);
  
  m_a = m_a.operator+(delta.operator*(G * other.m_mass * fac));
  // ...
}

void Body::resetAcceleration() {
  m_a.reset();
}

const Vec2f& Body::position() const {
  return m_pos;
}

const Vec2f& Body::velocity() const {
  return m_v;
}

float Body::mass() const {
  return m_mass;
}

Vec2f& Body::velocity() {
  return m_v;
}

float& Body::mass() {
  return m_mass;
}

float Body::distanceTo(const Body& other) const {
  return m_pos.distance(other.m_pos);
}

std::ostream& operator<<(std::ostream& os, const Body& body) {
  const Vec2f& pos = body.position();
  const Vec2f& v   = body.velocity();
  os << "|p=(" << pos[0] << ", " << pos[1] << ") v=(" << v[0] << ", " << v[1] << ") m=" << body.mass() << "|";
  return os;
}

}  // namespace practical::nbody
