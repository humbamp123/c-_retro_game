/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:00:50 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 20:55:08 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(void) : Character(21, 42, 90, 100, 40, 50, 5, 'O') {
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
