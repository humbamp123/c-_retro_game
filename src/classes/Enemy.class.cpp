/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:06:10 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 11:54:18 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"
#include <unistd.h>

Enemy::Enemy(void) : Character(10, 84, 0, 0, 1, 190, 200, 140, 150, 15, 'X') {
#ifdef FT_DEBUG
  std::cout << "Enemy constructor Called" << std::endl;
#endif
}

Enemy::Enemy(Enemy const &src) : Character(src) {
  #ifdef FT_DEBUG
    std::cout << "Enemy copy constructor called" << std::endl;
  #endif
}

Enemy &Enemy::operator=(Enemy const &rhs) {
  Character::operator=(rhs);
  std::cout << "Enemy '=' operator called" << std::endl;
  return (*this);
}

Enemy::~Enemy(void) { std::cout << "Enemy destructor Called" << std::endl; }

void Enemy::spawn(void) {
  if (this->_level == 1) {
    this->_x = this->_maxX - 2;
    this->_y = (arc4random() % (this->_maxY - 2)) + 1;
    this->_xDirection = -1;
    this->_yDirection = 0;
  } else if (this->_level == 2) {
    this->_x = 1;
    this->_y = (arc4random() % (this->_maxY - 2)) + 1;
    this->_xDirection = 1;
    this->_yDirection = 0;
  } else if (this->_level == 3) {
    this->_x = (arc4random() % (this->_maxX - 2)) + 1;
    this->_y = this->_maxY - 2;
    this->_xDirection = 0;
    this->_yDirection = -1;
  } else {
    this->_x = (arc4random() % (this->_maxX - 2)) + 1;
    this->_y = 1;
    this->_xDirection = 0;
    this->_yDirection = 1;
  }
  putSprite();
}

int Enemy::getBounds(void) { return( this->_bounds); }

void Enemy::moveEnemy(void) {
  clearSprite();
  this->_x += this->_xDirection;
  this->_y += this->_yDirection;
  putSprite();
}
