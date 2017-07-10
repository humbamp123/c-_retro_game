/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:11:32 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 19:58:14 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.class.hpp"

Missile::Missile(void)
    : Character(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, '-'), Player(0) {
  std::cout << "Default constructor called" << std::endl;
  this->_isFired = false;
}

// Missile::Missile(short direction)
//     : Character(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, '-'), Player(0) {
//   this->_isFired = false;
//   this->_direction = direction;
// }

Missile::Missile(Missile const &src) { *this = src; }

Missile &Missile::operator=(Missile const &rhs) {
  Character::operator=(rhs);
  return (*this);
}

Missile::~Missile(void) { clearSprite(); }

void Missile::update(void) {
  if (this->_isFired) {
    clearSprite();
    this->_x += this->_direction;
    putSprite();
  }
}

bool Missile::isFired(void) { return (this->_isFired); }

void Missile::setIsFired(bool b) { this->_isFired = b; }

void Missile::setDirection(short direction) { this->_direction = direction; }
