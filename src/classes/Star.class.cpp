/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:12:41 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 21:46:13 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Star.class.hpp"

Star::Star(void) : Character(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '.', ".") {
  this->_status = false;
}

Star::Star(Star const &src) : Character(src) {}

Star &Star::operator=(Star const &rhs) {
  Character::operator=(rhs);
  return (*this);
}

Star::~Star(void) {}

void Star::spawn(void) {
  this->_x = this->_maxX - 3 + arc4random() % 2;
  this->_y = (arc4random() % (this->_maxY - 4)) + 1;
  this->_xDirection = -1;
}

void Star::setStatus(bool status) { this->_status = status; }

bool Star::getStatus(void) { return (this->_status); }

int Star::getBounds(void) { return (this->_bounds); }

void Star::moveStar(void) {
  clearSprite();
  this->_x += this->_xDirection;
  putSprite();
}
