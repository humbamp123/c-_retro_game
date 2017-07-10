/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:50:22 by apineda           #+#    #+#             */
/*   Updated: 2017/07/09 17:21:35 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_H
#define GAME_CLASS_H

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "Asteroids.class.hpp"
#include "MissileRain.class.hpp"
#include "Player.class.hpp"

class Game {
 public:
  Game(void);
  Game(Game const& src);
  Game& operator=(Game const&);
  ~Game(void);

  WINDOW* wnd;
  WINDOW* text;
  void run();
  void screenCheck(Player& master);
  bool gameCollisions(Player& master, Asteroids& arbiters, MissileRain& bullets);
  private:
  int _xMax;
  int _yMax;
  int _scoreSize;
  unsigned int _score;
  unsigned int _maxScore;
  bool gameCollisions(Player& master, Asteroids& arbiters,
                      MissileRain& bullets);
  void fireMissiles(Player &master, Asteroids &arbiters,
                          MissileRain &bullets);
  int xMax;
  int yMax;
};

#endif
