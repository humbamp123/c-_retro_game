/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:53:16 by apineda           #+#    #+#             */
/*   Updated: 2017/07/09 23:10:05 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Asteroids.class.hpp"
#include "Enemy.class.hpp"
#include "MissileRain.class.hpp"
#include "Player.class.hpp"
#include "Space.class.hpp"

Game::Game() : _xMax(0), _yMax(0) {
  this->wnd = initscr();
  this->_scoreSize = 3;
  this->_score = 0;
  this->_maxScore = -1;
  cbreak();
  noecho();
  refresh();
  keypad(this->wnd, true);
  nodelay(this->wnd, true);
  curs_set(0);
  if (!has_colors()) {
    endwin();
    std::cout << "Error: Terminal does not support color." << std::endl;
    exit(1);
  }
}

Game::Game(Game const &src) { *this = src; }

Game &Game::operator=(Game const &) { return (*this); }

Game::~Game() { endwin(); }

void Game::screenCheck(Player &master, Asteroids &arbiters, Space &stars, double elapsed_seconds) {
  getmaxyx(this->wnd, this->_yMax, this->_xMax);
  if (master.getMaxX() != this->_yMax || master.getMaxY() != this->_xMax) {
    master.setXYMax(this->_xMax, this->_yMax - _scoreSize + 1);
    for (size_t i = 0; i < arbiters.getDataSize(); i++) {
      arbiters.getData()[i].setXYMax(this->_xMax, this->_yMax);
      stars.getData()[i].setXYMax(this->_xMax, this->_yMax);
    }
    // wclear(this->wnd);
    wattron(this->wnd, A_BOLD);
    box(this->wnd, 0, 0);
    wattroff(this->wnd, A_BOLD);
    wmove(this->wnd, this->_yMax - _scoreSize, 1);
    whline(this->wnd, '-', this->_xMax - 2);
    whline(this->wnd, '-', this->_xMax - 2);
  }
  if (this->_score != this->_maxScore) {
    this->_maxScore = this->_score;
  }
  mvwprintw(this->wnd, this->_yMax - 2, 1, "Score : %d Time : %f", this->_maxScore, elapsed_seconds);
  wrefresh(this->wnd);
}

bool Game::gameCollisions(Player &master, Asteroids &arbiters,
                          MissileRain &bullets, MissileRain &lasers) {
  for (size_t i = 0; i < arbiters.getDataSize(); i++) {
    if (arbiters.getData()[i].getStatus()) {
      if (master.checkCollision(arbiters.getData()[i].getX(),
                                arbiters.getData()[i].getY()) ||
          master.checkCollision(arbiters.getData()[i].getX() - 1,
                                arbiters.getData()[i].getY()) ||
          master.checkCollision(arbiters.getData()[i].getX() + 1,
                                arbiters.getData()[i].getY())) {
        endwin();
        return (1);
      } else {
        for (size_t j = 0; j < bullets.getDataSize(); j++) {
          if (bullets.getData()[j].isFired() &&
              (bullets.getData()[j].checkCollision(
                   arbiters.getData()[i].getX(),
                   arbiters.getData()[i].getY()) ||
               bullets.getData()[j].checkCollision(
                   arbiters.getData()[i].getX() + 1,
                   arbiters.getData()[i].getY()) ||
               bullets.getData()[j].checkCollision(
                   arbiters.getData()[i].getX() - 1,
                   arbiters.getData()[i].getY()))) {
            bullets.getData()[j].clearSprite();
            bullets.getData()[j].setIsFired(false);
            arbiters.getData()[i].clearSprite();
            arbiters.getData()[i].setStatus(false);
            this->_score += 1;
            if (this->_maxScore > 10)
              arbiters.getData()[i].setLevel(2);
            else if (this->_maxScore > 500)
              arbiters.getData()[i].setLevel(3);
          } else if (bullets.getData()[j].isFired() &&
                     bullets.getData()[j].getX() + 1 > this->_xMax - 2) {
            bullets.getData()[j].clearSprite();
            bullets.getData()[j].setIsFired(false);
          }
        }
      }
    }
  }
  for (size_t i = 0; i < lasers.getDataSize(); i++) {
    if (lasers.getData()[i].isFired()) {
      if (master.checkCollision(lasers.getData()[i].getX(),
                                lasers.getData()[i].getY()) ||
          master.checkCollision(lasers.getData()[i].getX() + 1,
                                lasers.getData()[i].getY()) ||
          master.checkCollision(lasers.getData()[i].getX() - 1,
                                lasers.getData()[i].getY())) {
        endwin();
        return (1);
      }
    }
  }
  return (0);
}

void Game::fireMissiles(Player &master, Asteroids &arbiters,
                        MissileRain &bullets, MissileRain &lasers) {
  for (size_t i = 0; i < lasers.getDataSize(); i++) {
    if (lasers.getData()[i].isFired() && lasers.getData()[i].getX() < 3) {
      lasers.getData()[i].clearSprite();
      lasers.getData()[i].setIsFired(false);
    }
  }
  if (master.getFire()) {
    for (size_t i = 0; i < bullets.getDataSize(); i++) {
      if (bullets.getData()[i].isFired() == false) {
        bullets.getData()[i].setIsFired(true);
        bullets.getData()[i].setY(master.getY());
        bullets.getData()[i].setX(master.getX() + 1);
        break;
      }
    }
    master.noFire();
  }
  for (size_t i = 0; i < arbiters.getDataSize(); i++) {
    if (arbiters.getData()[i].getStatus()) {
      for (size_t j = 0; j < lasers.getDataSize(); j++) {
        if (lasers.getData()[j].isFired() == false && !(arc4random() % 500)) {
          lasers.getData()[j].setIsFired(true);
          lasers.getData()[j].setY(arbiters.getData()[i].getY());
          lasers.getData()[j].setX(arbiters.getData()[i].getX() - 1);
        }
      }
    }
  }
  for (size_t i = 0; i < bullets.getDataSize(); i++) {
    bullets.getData()[i].update();
    lasers.getData()[i].update();
  }
}

void Game::run() {
  unsigned int xmax;
  unsigned int ymax;
  std::chrono::time_point<std::chrono::system_clock> start, end;
  int enemyAmount = 100;
  int bulletAmount = 30;
  getmaxyx(this->wnd, ymax, xmax);
  Player master(ymax);
  Asteroids arbiters(enemyAmount, xmax, ymax);
  MissileRain bullets(bulletAmount, 1);
  MissileRain lasers(bulletAmount, -2);
  Space stars(100, xmax, ymax);
  std::chrono::duration<double> elapsed_seconds = std::chrono::system_clock::now() - std::chrono::system_clock::now();
  refresh();
  while (42) {
    start = std::chrono::system_clock::now();
    screenCheck(master, arbiters, stars, elapsed_seconds.count());
    unsigned int in_char = wgetch(this->wnd);
    master.movePlayer(in_char);
    if (master.getExit() == true) break;
    fireMissiles(master, arbiters, bullets, lasers);
    if (gameCollisions(master, arbiters, bullets, lasers)) break;
    stars.update();
    arbiters.update();
    master.putSpriteString(1, 6);
    refresh();
    usleep(30000);
    end = std::chrono::system_clock::now();
    elapsed_seconds += end - start;
  }
  // delwin(text);
  delwin(wnd);
  endwin();
}
