/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:06:10 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 19:25:33 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy(void) : Character(10, 84, 0, 0, 1, 190, 200, 140, 150, 15, 'X') {
#ifdef FT_DEBUG
  std::cout << "Enemy constructor Called" << std::endl;
#endif
}

Enemy::Enemy(unsigned int xmax, unsigned int ymax) : Character(10, 84, 0, 0, 1, 190, 200, 140, 150, 15, 'X') {
  this->_maxX = xmax;
  this->_maxY = ymax;
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

void Enemy::moveEnemy(void) {
  this->_x += this->_xDirection;
  this->_y += this->_yDirection;
  std::cout << this->_x << std::endl;
  std::cout << this->_y << std::endl;
}
