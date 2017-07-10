/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:04:39 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 14:17:58 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include <iostream>
#include "Character.class.hpp"

class Enemy : virtual public Character {
 public:
  Enemy(void);
  Enemy(Enemy const &src);
  Enemy &operator=(Enemy const &rhs);
  ~Enemy(void);

  void moveEnemy();
  void spawn();
  int getBounds();
  void setStatus(bool status);
  bool getStatus();

 private:
  int _xDirection;
  int _yDirection;
  int _bounds;
  bool _status;
};

#endif
