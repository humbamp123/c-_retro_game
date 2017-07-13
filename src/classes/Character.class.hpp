/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:45:42 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 22:48:26 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include <ncurses.h>
#include <iostream>

class Character {
 public:
  Character(int x, int y, int maxX, int maxY, unsigned int level,
            unsigned int hitPoints, unsigned int maxHitPoints,
            unsigned int energyPoints, unsigned int maxEnergyPoints,
            unsigned int attackDamage, char sprite, std::string spriteString);
  Character(void);
  Character(Character const &src);
  Character &operator=(Character const &rhs);
  ~Character(void);

  int getX(void);
  void setX(int x);
  int getY(void);
  void setY(int y);
  int getMaxX(void);
  int getMaxY(void);
  void setXYMax(int xmax, int ymax);
  void setSprite(int sprite);
  void setLevel(int level);
  unsigned int getHitPoints(void);
  unsigned int getMaxHitPoints(void);
  unsigned int getEnergyPoints(void);
  unsigned int getMaxEnergyPoints(void);
  unsigned int getAttackDamage(void);
  char getSprite(void);
  void clearSprite(void);
  void clearSpriteString(void);
  void putSprite(void);
  void putSpriteString(void);
  void putSpriteString(int initcolor, int color);
  void putSprite(int initcolor, int color);

 protected:
  int _x;
  int _y;
  int _maxX;
  int _maxY;
  unsigned int _level;
  unsigned int _hitPoints;
  unsigned int _maxHitPoints;
  unsigned int _energyPoints;
  unsigned int _maxEnergyPoints;
  unsigned int _attackDamage;
  char _sprite;
  std::string _spriteString;
};

#endif
