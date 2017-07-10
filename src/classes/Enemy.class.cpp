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

Enemy::Enemy(void)
    : Character(10, 84, 0, 0, 1, 190, 200, 140, 150, 15, 'X', "X") {
  this->_status = false;
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
  int random = arc4random() % 2;
  if (this->_level == 1) {
    this->_x = this->_maxX - 3 + arc4random() % 2;
    this->_y = (arc4random() % (this->_maxY - 4)) + 1;
    this->_xDirection = -1;
    this->_yDirection = 0;
  } else if (this->_level == 2) {
    this->_x = random ? (arc4random() % (this->_maxX - 2)) + 1
                      : this->_maxX - 3 + arc4random() % 2;
    this->_y =
        random ? this->_maxY - 2 : (arc4random() % (this->_maxY - 4)) + 1;
    this->_xDirection = random ? 0 : -1;
    this->_yDirection = random ? -1 : 0;
  } else if (this->_level == 3) {
    this->_x = rand() % 2 ? 2 : this->_maxX - 3 + arc4random() % 2;
    this->_y = (arc4random() % (this->_maxY - 4)) + 1;
    this->_xDirection = this->_x < 3 ? 1 : -1;
    this->_yDirection = 0;
  }
  putSprite();
}

void Enemy::setStatus(bool status) { this->_status = status; }

bool Enemy::getStatus(void) { return (this->_status); }

int Enemy::getBounds(void) { return (this->_bounds); }

void Enemy::moveEnemy(void) {
  clearSprite();
  this->_x += this->_xDirection;
  this->_y += this->_yDirection;
  putSprite();
}
