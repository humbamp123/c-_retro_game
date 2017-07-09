/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:11:56 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 14:34:54 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H
# define MISSILE_H

#include "Player.class.hpp"
#include "Enemy.class.hpp"

class Missile : public Player, public Enemy {
  Missile(void);
 public:
  Missile(int x, int y);
  Missile(Missile const & src);
  Missile & operator=(Missile const &rhs);
  ~Missile(void);

  void update(void);
};

#endif
