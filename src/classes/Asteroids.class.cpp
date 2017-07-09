/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:14:51 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 12:28:14 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroids.class.hpp"

Asteroids::Asteroids(void) {
  std::cout << "Asteroid Default Constructor called" << std::endl;
}

Asteroids::Asteroids(int n) {
  this->_asteroidField = new Enemy[n];
  std::cout << "Asteroid Field Created" << std::endl;
}

Asteroids::Asteroids(Asteroids const & src) {
  *this = src;
}

Asteroids & Asteroids::operator=(Asteroids const &rhs) {
  (void)rhs;
  return (*this);
}

Asteroids::~Asteroids(void) {
  delete [] this->_asteroidField;
  std::cout << "Asteroid Field Deleted" << std::endl;
}
