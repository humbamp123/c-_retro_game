/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MissileRain.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:54:18 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 14:59:33 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Missile::Missile(void) : _size(0) {
  std::cout << "Missile Default Constructor called" << std::endl;
}

Missile::Missile(int n, int xmax, int ymax) : _size(n) {
  this->_missileField = new Enemy[n];
  std::cout << "Missile Field Created" << std::endl;
}

Missile::Missile(Missile const & src) {
  *this = src;
}

Missile & Missile::operator=(Missile const &rhs) {
  (void)rhs;
  return (*this);
}

Missile::~Missile(void) {
  delete [] this->_missileField;
  std::cout << "Missile Field Deleted" << std::endl;
}

MissileRain *Missile::getData() const { return (_missileField); }

unsigned int Missile::getDataSize() const { return (_size); }

void Missile::update() {
}
