/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:00:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 00:44:55 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(void) : Character(1, 1, 0, 0, 90, 100, 40, 50, 5, 'O') {
#ifdef FT_DEBUG
  std::cout << "Player constructor Called" << std::endl;
#endif
}

Player::Player(unsigned int max_y)
    : Character(1, 1, 0, 0, 90, 100, 40, 50, 5, 'O') {
  this->_exit_requested = false;
  this->_x = 1;
  this->_y = max_y / 2;
  putSprite();
#ifdef FT_DEBUG
  std::cout << "Player constructor Called" << std::endl;
#endif
}

Player::Player(Player const &src) : Character(src) {
  std::cout << "Player copy constructor called" << std::endl;
}

Player &Player::operator=(Player const &rhs) {
  Character::operator=(rhs);
  std::cout << "Player '=' operator called" << std::endl;
  return (*this);
}

Player::~Player(void) { std::cout << "Player destructor Called" << std::endl; }

bool Player::getExit() { return (this->_exit_requested); }

void Player::movePlayer(unsigned int in_char) {
  this->clearSprite();
  switch (in_char) {
    case 'q':
      this->_exit_requested = true;
      break;
    case KEY_UP:
    case 'w':
    case 'i':
      if (this->getY() > 0 + 1) this->setY(this->getY() - 1);
      break;
    case KEY_DOWN:
    case 's':
    case 'k':
      if (this->getY() < (int)this->_parentYMax - 2)
        this->setY(this->getY() + 1);
      break;
    case KEY_LEFT:
    case 'a':
    case 'j':
      if (this->getX() > 1) this->setX(this->getX() - 1);
      break;
    case KEY_RIGHT:
    case 'd':
    case 'l':
      if (this->getX() < (int)this->_parentXMax - 2)
        this->setX(this->getX() + 1);
      break;
    default:
      break;
  }
}
