/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:53:16 by apineda           #+#    #+#             */
/*   Updated: 2017/07/09 21:37:29 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Asteroids.class.hpp"
#include "Enemy.class.hpp"
#include "MissileRain.class.hpp"
#include "Player.class.hpp"
#include "Space.class.hpp"

// #include <ncurses.h> #include <unistd.h> int main(int argc, char *argv[]) {
//   int parent_x, parent_y;
//   int score_size = 3;
//   initscr();
//   noecho();
//   curs_set(FALSE);   // get our maximum window dimensions
//   getmaxyx(stdscr,parent_y, parent_x); // set up initial windows
//   WINDOW *field =
// newwin(parent_y - score_size, parent_x, 0, 0);
// WINDOW *score =
//     newwin(score_size, parent_x, parent_y - score_size, 0);  // draw to our
// windows mvwprintw(field, 0, 0, "Field");
// mvwprintw(score, 0, 0, "Score");  //
// refresh each window wrefresh(field);
// wrefresh(score);
// sleep(5);  // clean up
// delwin(field);
// delwin(score);
// endwin();
// return 0;
// }

Game::Game() : _xMax(0), _yMax(0) {
  this->wnd = initscr();
  this->_scoreSize = 3;
  this->_score = 0;
  this->_maxScore = -1;
  cbreak();   // Allows user typed characters to be immediately available
  noecho();   // does not echo any characters grabbed by getch
  refresh();  // must be used after any changes have been made
  keypad(this->wnd, true);    // Allows keys to be interpreted for actions
  nodelay(this->wnd, true);   // This diables stoping everything when using wgetch()
  curs_set(0);          // Makes the cursor visible or invisible
  if (!has_colors()) {  // Macro to check if the terminal supports color
    endwin();
    std::cout << "Error: Terminal does not support color." << std::endl;
    exit(1);
  }
  // start_color(); // Allows color changes
  // init_pair(1, COLOR_BLACK, COLOR_CYAN); // Takes two colors into a number
  // wbkgd(wnd, COLOR_PAIR(1)); // sets the background color
}

Game::Game(Game const &src) { *this = src; }

Game &Game::operator=(Game const &) { return (*this); }

Game::~Game() { endwin(); }

// int main(int argc, char *argv[]) {
//   int parent_x, parent_y, new_x, new_y;
//   int score_size = 3;  // ...
//   draw_borders(field);
//   draw_borders(score);
//   while (1) {
//     getmaxyx(stdscr, new_y, new_x);
//     if (new_y != parent_y || new_x != parent_x) {
//       parent_x = new_x;
//       parent_y = new_y;
//       wresize(field, new_y - score_size, new_x);
//       wresize(score, score_size, new_x);
//       mvwin(score, new_y - score_size, 0);
//       wclear(stdscr);
//       wclear(field);
//       wclear(score);
//       draw_borders(field);
//       draw_borders(score);
//     }  // draw
//     mvwprintw(field, 1, 1, "Field");
//     mvwprintw(score, 1, 1, "Score");  // refresh each window
//     wrefresh(field);
//     wrefresh(score);
//   }  // ...
// }

void Game::screenCheck(Player &master, Asteroids &arbiters) {
  getmaxyx(this->wnd, this->_yMax, this->_xMax);
  if (master.getMaxX() != this->_yMax || master.getMaxY() != this->_xMax) {
    master.setXYMax(this->_xMax, this->_yMax - _scoreSize + 1);
    for (size_t i = 0; i < arbiters.getDataSize(); i++) {
      arbiters.getData()[i].setXYMax(this->_xMax, this->_yMax);
    }
    // wresize(this->wnd, 50, 175); //change screen size here
    wclear(this->wnd);
    // wclear(this->text);
    wattron(this->wnd, A_BOLD);   // Activates an atribute for the drawing, Bold in this case
    box(this->wnd, 0, 0);
    wattroff(this->wnd, A_BOLD);  // Deactivates an atribute for the drawing, Bold in this
                      // case
    wmove(this->wnd, this->_yMax - _scoreSize, 1);
    whline(this->wnd, '-', this->_xMax - 2);
    whline(this->wnd, '-', this->_xMax - 2);

    // wrefresh(this->text);
  }
  if (this->_score != this->_maxScore) {
    this->_maxScore = this->_score;
  }
  mvwprintw(this->wnd, this->_yMax - 2, 1, "Score : %d", this->_maxScore);
  wrefresh(this->wnd);
}

bool Game::gameCollisions(Player &master, Asteroids &arbiters,
                          MissileRain &bullets, MissileRain &lasers) {
  for (size_t i = 0; i < arbiters.getDataSize(); i++) {
    if (arbiters.getData()[i].getStatus()) {
      if (master.checkCollision(arbiters.getData()[i].getX(),
          arbiters.getData()[i].getY())
        || master.checkCollision(arbiters.getData()[i].getX() - 1,
          arbiters.getData()[i].getY())
        || master.checkCollision(arbiters.getData()[i].getX() + 1,
          arbiters.getData()[i].getY())) {
        endwin();
        return (1);
      } else {
        for (size_t j = 0; j < bullets.getDataSize(); j++) {
          if (bullets.getData()[j].isFired() &&
(bullets.getData()[j].checkCollision(arbiters.getData()[i].getX(), arbiters.getData()[i].getY())
|| bullets.getData()[j].checkCollision(arbiters.getData()[i].getX() + 1 , arbiters.getData()[i].getY())
|| bullets.getData()[j].checkCollision(arbiters.getData()[i].getX() - 1, arbiters.getData()[i].getY()))) {
            bullets.getData()[j].clearSprite();
            bullets.getData()[j].setIsFired(false);
            arbiters.getData()[i].clearSprite();
            arbiters.getData()[i].setStatus(false);
            this->_score += 1;
            if (this->_maxScore == 10)
              arbiters.getData()[i].setLevel();
            else if (this->_maxScore == 500)
              arbiters.getData()[i].setLevel();
          }
          else if (bullets.getData()[j].isFired() && bullets.getData()[j].getX() + 1 > this->_xMax - 2) {
            bullets.getData()[j].clearSprite();
            bullets.getData()[j].setIsFired(false);
          }
        }
      }
    }
  }
  for (size_t i = 0; i < lasers.getDataSize(); i++) {
    if (lasers.getData()[i].isFired()) {
      if (master.checkCollision(lasers.getData()[i].getX(), lasers.getData()[i].getY())
      || master.checkCollision(lasers.getData()[i].getX() + 1, lasers.getData()[i].getY())
      || master.checkCollision(lasers.getData()[i].getX() - 1, lasers.getData()[i].getY())) {
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
          if (lasers.getData()[j].isFired() == false) {
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
  int enemyAmount = 100;
  int bulletAmount = 30;
  getmaxyx(this->wnd, ymax, xmax);
  Player master(ymax);
  Asteroids arbiters(enemyAmount, xmax, ymax);
  MissileRain bullets(bulletAmount, 1);
  MissileRain lasers(bulletAmount, -2);
  Space stars(50, xmax, ymax);
  refresh();  // must be used after any changes have been made
  while (1) {
    screenCheck(master, arbiters);
    unsigned int in_char = wgetch(this->wnd);
    master.movePlayer(in_char);
    if (master.getExit() == true) break;
    fireMissiles(master, arbiters, bullets, lasers);
    if (gameCollisions(master, arbiters, bullets, lasers)) {
      break;
    }
    stars.update();
    arbiters.update();
    master.putSpriteString();
    refresh();
    usleep(30000);
  }
  delwin(wnd);
  endwin();
}

// move(5, 5); //moves the cursor to the specified y, x, position
// std::string text = "Hello world!";
// for(size_t i = 0; i < text.size(); i++) {
//     addch(text[i]); // prints a character at the current cursor position and
//     then advances one space addch(' ');
// }

// Player master;
// Player chief(master);
// Player masterchief;
// masterchief = chief;

// std::cout << masterchief.getX() << std::endl;
// std::cout << masterchief.getY() << std::endl;
// std::cout << masterchief.getHitPoints() << std::endl;
// std::cout << masterchief.getMaxHitPoints() << std::endl;
// std::cout << masterchief.getEnergyPoints() << std::endl;
// std::cout << masterchief.getMaxEnergyPoints() << std::endl;
// std::cout << masterchief.getAttackDamage() << std::endl;
// std::cout << masterchief.getSprite() << std::endl;

// std::cout << "--------------------------" << std::endl;

// Enemy arbiter;
// Enemy elite(arbiter);
// Enemy halo;
// halo = elite;

// std::cout << halo.getX() << std::endl;
// std::cout << halo.getY() << std::endl;
// std::cout << halo.getHitPoints() << std::endl;
// std::cout << halo.getMaxHitPoints() << std::endl;
// std::cout << halo.getEnergyPoints() << std::endl;
// std::cout << halo.getMaxEnergyPoints() << std::endl;
// std::cout << halo.getSprite() << std::endl;
