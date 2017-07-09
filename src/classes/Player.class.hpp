/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:35:27 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 16:40:57 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
 #define PLAYER_CLASS_H

class Player {
 public:
  Player(void);
  Player(Player const & src);
  Player & operator=(Player const &rhs);
  ~Player(void);


 private:
   unsigned int _x;
   unsigned int _y;
   unsigned int _hitPoints;
   unsigned int _maxHitPoints;
   unsigned int _energyPoints;
   unsigned int _maxEnergyPoints;
   unsigned int _AttackDamage;
};

#endif
