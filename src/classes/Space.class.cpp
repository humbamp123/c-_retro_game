/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Space.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:25:28 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 22:46:09 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Space.class.hpp"

Space::Space(void) : _size(0) {}

Space::Space(int n, int xmax, int ymax) : _size(n) {
  this->_starField = new Star[n];
  for (int i = 0; i < n; i++) {
    this->_starField[i].setXYMax(xmax, ymax);
  }
}

Space::Space(Space const &src) { *this = src; }

Space &Space::operator=(Space const &rhs) {
  (void)rhs;
  return (*this);
}

Space::~Space(void) { delete[] this->_starField; }

Star *Space::getData() const { return (_starField); }

unsigned int Space::getDataSize() const { return (_size); }

void Space::update() {
  for (size_t i = 0; i < this->getDataSize(); i++) {
    if (this->_starField[i].getStatus() == false && !(rand() % 100)) {
      this->_starField[i].spawn();
      this->_starField[i].setStatus(true);
    } else if (this->_starField[i].getX() < 2) {
      this->_starField[i].clearSprite();
      this->_starField[i].setStatus(false);
      if (!(rand() % 100)) {
        this->_starField[i].spawn();
        this->_starField[i].setStatus(true);
      }
    } else if (this->_starField[i].getStatus() == true)
      this->_starField[i].moveStar();
  }
}
