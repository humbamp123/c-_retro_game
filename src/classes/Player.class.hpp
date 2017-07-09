/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:35:27 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 00:47:50 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <iostream>
#include "Character.class.hpp"

class Player : public Character {
 public:
  Player(void);
  Player(unsigned int max_y);
  Player(Player const &src);
  Player &operator=(Player const &rhs);
  ~Player(void);
  void movePlayer(unsigned int in_char);
  bool getExit();
  unsigned int getParentXMax();
  unsigned int getParentYMax();
  void setParentXYMax(unsigned int xmax, unsigned int ymax);

 private:
  bool _exit_requested;
  unsigned int _parentXMax;
  unsigned int _parentYMax;
};

#endif
