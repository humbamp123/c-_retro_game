/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:11:56 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 22:46:38 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H
#define MISSILE_H

#include "Enemy.class.hpp"
#include "Player.class.hpp"

class Missile : public Player, public Enemy {
 public:
  Missile(void);
  Missile(Missile const &src);
  Missile &operator=(Missile const &rhs);
  ~Missile(void);

  void update(void);
  bool isFired(void);
  void setIsFired(bool);
  void setDirection(short direction);

 private:
  bool _isFired;
  short _direction;
};

#endif
