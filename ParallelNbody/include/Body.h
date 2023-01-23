/*
 * Body.h
 *
 *  Created on: Dec 15, 2014
 *  Updated on: Aug 23, 2022
 *      Author: ahueck
 */

#ifndef BODY_H_
#define BODY_H_

#include "Vec2.h"

#include <iostream>

namespace practical::nbody {

class Body {
 private:
  Vec2f m_pos;
  Vec2f m_v;
  Vec2f m_a;
  float m_mass;

 public:
  Body(const Vec2f& pos, const Vec2f& v, float mass);
  void update(float dt);
  void applyForces(const Body& other);
  void resetAcceleration();
  [[nodiscard]] Vec2f& velocity();
  [[nodiscard]] float& mass();
  [[nodiscard]] const Vec2f& position() const;
  [[nodiscard]] const Vec2f& velocity() const;
  [[nodiscard]] float mass() const;
  [[nodiscard]] float distanceTo(const Body& other) const;
};

std::ostream& operator<<(std::ostream& os, const Body& body);

}  // namespace practical::nbody

#endif /* BODY_H_ */
