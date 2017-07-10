/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:14:51 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 15:02:39 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroids.class.hpp"

Asteroids::Asteroids(void) : _size(0) {
  std::cout << "Asteroid Default Constructor called" << std::endl;
}

Asteroids::Asteroids(int n, int xmax, int ymax) : _size(n) {
  this->_asteroidField = new Enemy[n];
  for (int i = 0; i < n; i++) {
    this->_asteroidField[i].setXYMax(xmax, ymax);
  }
  // std::cout << "Asteroid Field Created" << std::endl;
}

Asteroids::Asteroids(Asteroids const &src) { *this = src; }

Asteroids &Asteroids::operator=(Asteroids const &rhs) {
  (void)rhs;
  return (*this);
}

Asteroids::~Asteroids(void) {
  delete[] this->_asteroidField;
  std::cout << "Asteroid Field Deleted" << std::endl;
}

Enemy *Asteroids::getData() const { return (_asteroidField); }

unsigned int Asteroids::getDataSize() const { return (_size); }

void Asteroids::update() {
  for (size_t i = 0; i < this->getDataSize(); i++) {
    if (this->_asteroidField[i].getStatus() == false && !(rand() % 100)) {
      this->_asteroidField[i].spawn();
      this->_asteroidField[i].setStatus(true);
    } else if (this->_asteroidField[i].getX() < 2) {
      this->_asteroidField[i].clearSprite();
      this->_asteroidField[i].setStatus(false);
      if (!(rand() % 100)) {
        this->_asteroidField[i].spawn();
        this->_asteroidField[i].setStatus(true);
      }
    } else if (this->_asteroidField[i].getStatus() == true)
      this->_asteroidField[i].moveEnemy();
  }
}
