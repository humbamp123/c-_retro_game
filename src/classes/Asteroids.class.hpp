/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroids.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 12:14:53 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 12:26:16 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROIDS_H
# define ASTEROIDS_H

# include <iostream>

# include "Enemy.class.hpp"

class Asteroids {
  Asteroids(void);
 public:
  Asteroids(int n);
  Asteroids(Asteroids const & src);
  Asteroids & operator=(Asteroids const &rhs);
  ~Asteroids(void);
 private:
  Enemy *_asteroidField;
};

#endif
