/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:45:42 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 18:02:28 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_H
#define CHARACTER_CLASS_H

#include <iostream>

class Character {
 public:
  Character(unsigned int x, unsigned int y, unsigned int hitPoints,
            unsigned int maxHitPoints, unsigned int energyPoints,
            unsigned int maxEnergyPoints, unsigned int attackDamage);
  Character(void);
  Character(Character const &src);
  Character &operator=(Character const &rhs);
  ~Character(void);

  unsigned int getX(void);
  unsigned int getY(void);
  unsigned int getHitPoints(void);
  unsigned int getMaxHitPoints(void);
  unsigned int getEnergyPoints(void);
  unsigned int getMaxEnergyPoints(void);
  unsigned int getAttackDamage(void);

 protected:
  unsigned int _x;
  unsigned int _y;
  unsigned int _hitPoints;
  unsigned int _maxHitPoints;
  unsigned int _energyPoints;
  unsigned int _maxEnergyPoints;
  unsigned int _attackDamage;
};

#endif