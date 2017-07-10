/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:14:53 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 12:59:47 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <iostream>

#include "Enemy.class.hpp"

class Asteroids {
  Asteroids(void);

 public:
  Asteroids(int n, int xmax, int ymax);
  Asteroids(int xmax, int ymax);
  Asteroids(Asteroids const &src);
  Asteroids &operator=(Asteroids const &rhs);
  ~Asteroids(void);

  Enemy *getData(void) const;
  unsigned int getDataSize(void) const;
  void update(void);

 private:
  Enemy *_asteroidField;
  unsigned int _size;
};

#endif
