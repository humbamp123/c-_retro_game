/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:50:22 by apineda           #+#    #+#             */
/*   Updated: 2017/07/08 17:24:48 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <string>
#include <ncurses.h>
#include <stdlib.h>
#include <iostream>

class Game
{
public:
  Game();
  Game(std::string name);
  Game& operator=(Game const &);
  ~Game();

  void run();

};


#endif