/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MissileRain.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:54:18 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 19:34:33 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MissileRain.class.hpp"

MissileRain::MissileRain(void) : _size(0) {
  // std::cout << "MissileRain Default Constructor called" << std::endl;
}

MissileRain::MissileRain(int n, short direction) : _size(n) {
  this->_missileField = new Missile[n];
  for (int i = 0; i < n; i++) {
    this->_missileField[i].setDirection(direction);
  }
  // std::cout << "MissileRain Field Created" << std::endl;
}

MissileRain::MissileRain(MissileRain const &src) { *this = src; }

MissileRain &MissileRain::operator=(MissileRain const &rhs) {
  (void)rhs;
  return (*this);
}

MissileRain::~MissileRain(void) {
  delete[] this->_missileField;
  std::cout << "MissileRain Field Deleted" << std::endl;
}

Missile *MissileRain::getData() const { return (_missileField); }

unsigned int MissileRain::getDataSize() const { return (_size); }

void MissileRain::update() {}
