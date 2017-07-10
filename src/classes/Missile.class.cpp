/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:11:32 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 14:37:46 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missile.class.hpp"

Missile::Missile(void) : Character(0, 0, 0, 0, 0, 0, 0, 0, 0, 1, '-'),
                Player(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Missile::Missile(int x, int y) : Character(x, y, 0, 0, 0, 0, 0, 0, 0, 1, '-'),
                      Player(0) {
  putSprite();
}

Missile::Missile(Missile const & src) {
  *this = src;
}

Missile & Missile::operator=(Missile const &rhs) {
  Character::operator=(rhs);
  return (*this);
}

Missile::~Missile(void) {
  clearSprite();
}

void Missile::update(void) {
  clearSprite();
  this->_y += 1;
  putSprite();
}
