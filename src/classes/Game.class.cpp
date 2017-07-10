/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:53:16 by apineda           #+#    #+#             */
/*   Updated: 2017/07/09 18:27:25 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Asteroids.class.hpp"
#include "Enemy.class.hpp"
#include "MissileRain.class.hpp"
#include "Player.class.hpp"

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

void Game::screenCheck(Player &master) {
  getmaxyx(this->wnd, this->_yMax, this->_xMax);
  if (master.getMaxX() != this->_yMax || master.getMaxY() != this->_xMax) {
    master.setXYMax(this->_xMax, this->_yMax - _scoreSize + 1);
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
    wrefresh(this->wnd);
    // wrefresh(this->text);
  } else if (this->_score != this->_maxScore) {
    this->_maxScore = this->_score;

  }
}

bool Game::gameCollisions(Player &master, Asteroids &arbiters,
                          MissileRain &bullets) {
  for (size_t i = 0; i < arbiters.getDataSize(); i++) {
    if (arbiters.getData()[i].getStatus()) {
      if (master.checkCollision(arbiters.getData()[i].getX(), arbiters.getData()[i].getY())) {
        endwin();
        return (1);
      } else {
        for (size_t j = 0; j < bullets.getDataSize(); j++) {
          if (bullets.getData()[j].isFired()
          && (bullets.getData()[j].getX() + 1 > this->xMax
          || bullets.getData()[j].checkCollision(arbiters.getData()[i].getX(), arbiters.getData()[i].getY())
          || bullets.getData()[j].checkCollision(arbiters.getData()[i].getX() + 1 , arbiters.getData()[i].getY())
          || bullets.getData()[j].checkCollision(arbiters.getData()[i].getX() - 1, arbiters.getData()[i].getY()))) {
            bullets.getData()[j].clearSprite();
            bullets.getData()[j].setIsFired(false);
            arbiters.getData()[i].clearSprite();
            arbiters.getData()[i].setStatus(false);
          }
        }
      }
    }
  }
  return (0);
}

void Game::fireMissiles(Player &master, Asteroids &arbiters,
                          MissileRain &bullets) {
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
  // TODO : Enemy missiles

  for (size_t i = 0; i < bullets.getDataSize(); i++) {
    bullets.getData()[i].update();
  }
  (void)arbiters;
}

void Game::run() {
  unsigned int xmax;
  unsigned int ymax;
  int enemyAmount = 100;
  int bulletAmount = 30;
  getmaxyx(this->wnd, ymax, xmax);
  Player master(ymax);
  Asteroids arbiters(enemyAmount, xmax, ymax);
  MissileRain bullets(bulletAmount);
  refresh();  // must be used after any changes have been made
  while (1) {
    screenCheck(master);
    unsigned int in_char = wgetch(this->wnd);
    master.movePlayer(in_char);
    master.putSprite();
    fireMissiles(master, arbiters, bullets);
    if (gameCollisions(master, arbiters, bullets)) {
      break;
    }
    arbiters.update();
    refresh();
    if (master.getExit() == true) break;
    usleep(30000);
  }
  delwin(text);
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
