/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:35:27 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 18:02:56 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_H
#define PLAYER_CLASS_H

#include <iostream>
#include "Character.class.hpp"

class Player : public Character {
 public:
  Player(void);
  Player(Player const &src);
  Player &operator=(Player const &rhs);
  ~Player(void);
};

#endif
