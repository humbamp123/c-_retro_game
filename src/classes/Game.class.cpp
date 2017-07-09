/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apineda <apineda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:53:16 by apineda           #+#    #+#             */
/*   Updated: 2017/07/08 17:22:25 by apineda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"

Game::Game() {
  WINDOW* wnd;
  wnd = initscr();
  cbreak(); //Allows user typed characters to be immediately available
  noecho(); // does not echo any characters grabbed by getch
  clear(); // clears the screen
  refresh();//must be used after any changes have been made
  keypad(wnd, true); // Allows keys to be interpreted for actions
  nodelay(wnd, true); // This diables stoping everything when using wgetch()
  curs_set(1); // Makes the cursor visible or invisible
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

Game::~Game(){
  endwin();
}


void Game::run() {
  move(5, 5); //moves the cursor to the specified y, x, position
  std::string text = "Hello world!";
  for(size_t i = 0; i < text.size(); i++) {
      addch(text[i]); // prints a character at the current cursor position and then advances one space
      addch(' ');
  }

  refresh(); //must be used after any changes have been made

  while(1);
}
