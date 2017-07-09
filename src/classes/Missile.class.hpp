/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:11:56 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 15:15:18 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H
# define MISSILE_H

#include "Player.class.hpp"
#include "Enemy.class.hpp"

class Missile : public Player, public Enemy {
 public:
  Missile(void);
  Missile(int x, int y);
  Missile(Missile const & src);
  Missile & operator=(Missile const &rhs);
  ~Missile(void);

  void update(void);
};

#endif
