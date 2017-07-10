/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:00:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 22:49:27 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(void)
    : Character(1, 1, 0, 0, 0, 90, 100, 40, 50, 5, '0', "<0>") {}

Player::Player(unsigned int max_y)
    : Character(1, 1, 0, 0, 0, 90, 100, 40, 50, 5, 'O', "<0>") {
  this->_exit_requested = false;
  this->_x = 2;
  this->_y = max_y / 2;
  this->_fire = false;
  putSpriteString(6);
}

Player::Player(Player const &src) : Character(src) {}

Player &Player::operator=(Player const &rhs) {
  Character::operator=(rhs);
  return (*this);
}

Player::~Player(void) {}

bool Player::getExit(void) { return (this->_exit_requested); }

bool Player::getFire(void) { return (this->_fire); }

void Player::noFire(void) { this->_fire = false; }

void Player::movePlayer(unsigned int in_char) {
  this->clearSprite();
  switch (in_char) {
    case 'q':
    case 27:
      this->_exit_requested = true;
      break;
    case ' ':
      this->_fire = true;
      break;
    case KEY_UP:
    case 'w':
    case 'i':
      if (this->getY() > 0 + 1) this->setY(this->getY() - 1);
      break;
    case KEY_DOWN:
    case 's':
    case 'k':
      if (this->getY() < (int)this->_maxY - 2) this->setY(this->getY() + 1);
      break;
    case KEY_LEFT:
    case 'a':
    case 'j':
      if (this->getX() > 2) this->setX(this->getX() - 1);
      break;
    case KEY_RIGHT:
    case 'd':
    case 'l':
      if (this->getX() < (int)this->_maxX - 5) this->setX(this->getX() + 1);
      break;
    default:
      break;
  }
}

bool Player::checkCollision(int x, int y) {
  return (this->_x == x && this->_y == y);
}
