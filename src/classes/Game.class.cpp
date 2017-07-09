/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:53:16 by apineda           #+#    #+#             */
/*   Updated: 2017/07/08 21:06:29 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"
#include "Player.class.hpp"
#include "Game.class.hpp"

Game::Game() {
  wnd = initscr();
  cbreak(); //Allows user typed characters to be immediately available
  noecho(); // does not echo any characters grabbed by getch
  clear(); // clears the screen
  refresh();//must be used after any changes have been made
  keypad(wnd, true); // Allows keys to be interpreted for actions
  nodelay(wnd, true); // This diables stoping everything when using wgetch()
  curs_set(0); // Makes the cursor visible or invisible
  if(!has_colors()) //Macro to check if the terminal supports color
  {
      endwin();
      std::cout << "ERROR: Terminal does not support color." << std::endl;
      exit(1);
  }
  // start_color(); // Allows color changes
  // init_pair(1, COLOR_BLACK, COLOR_CYAN); // Takes two colors into a number
  // wbkgd(wnd, COLOR_PAIR(1)); // sets the background color
  attron(A_BOLD); //Activates an atribute for the drawing, Bold in this case
  box(wnd, 0, 0); //One way to draw a border
  attroff(A_BOLD); //Deactivates an atribute for the drawing, Bold in this case
}

Game &Game::operator=(Game const &) {
  return (*this);
}

Game::~Game(){
  endwin();
}


void Game::run() {
  Player master;
  refresh(); //must be used after any changes have been made
  int xmax;
  int ymax;
  getmaxyx(this->wnd, xmax, ymax);
  while(1) {
    // Enemy arbiter;
    master.setX(0);
    master.setY(0);

    for (int i = 0; i < ymax; i++) {
      master.clearSprite();
      master.setX(i);
      master.setY(5);
      usleep(100000);
      master.putSprite();
      refresh();
    }
  }
}

  // move(5, 5); //moves the cursor to the specified y, x, position
  // std::string text = "Hello world!";
  // for(size_t i = 0; i < text.size(); i++) {
  //     addch(text[i]); // prints a character at the current cursor position and then advances one space
  //     addch(' ');
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
