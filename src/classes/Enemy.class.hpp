/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:04:39 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 18:07:20 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_H
#define ENEMY_CLASS_H

#include <iostream>
#include "Character.class.hpp"

class Enemy : public Character {
 public:
  Enemy(void);
  Enemy(Enemy const &src);
  Enemy &operator=(Enemy const &rhs);
  ~Enemy(void);
};

#endif
