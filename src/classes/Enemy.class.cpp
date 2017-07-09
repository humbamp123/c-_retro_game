/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:06:10 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 18:07:26 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"

Enemy::Enemy(void) : Character(10, 84, 190, 200, 140, 150, 15) {
  std::cout << "Enemy constructor Called" << std::endl;
}

Enemy::Enemy(Enemy const &src) : Character(src) {
  std::cout << "Enemy copy constructor called" << std::endl;
}

Enemy &Enemy::operator=(Enemy const &rhs) {
  Character::operator=(rhs);
  std::cout << "Enemy '=' operator called" << std::endl;
  return (*this);
}

Enemy::~Enemy(void) { std::cout << "Enemy destructor Called" << std::endl; }
