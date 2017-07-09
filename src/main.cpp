/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:25:13 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/08 18:10:32 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "classes/Player.class.hpp"
#include "classes/Enemy.class.hpp"

int main(void) {
  Player master;
  Player chief(master);
  Player masterchief;
  masterchief = chief;

  std::cout << masterchief.getX() << std::endl;
  std::cout << masterchief.getY() << std::endl;
  std::cout << masterchief.getHitPoints() << std::endl;
  std::cout << masterchief.getMaxHitPoints() << std::endl;
  std::cout << masterchief.getEnergyPoints() << std::endl;
  std::cout << masterchief.getMaxEnergyPoints() << std::endl;
  std::cout << masterchief.getAttackDamage() << std::endl;

  std::cout << "--------------------------" << std::endl;

  Enemy arbiter;
  Enemy elite(arbiter);
  Enemy halo;
  halo = elite;

  std::cout << halo.getX() << std::endl;
  std::cout << halo.getY() << std::endl;
  std::cout << halo.getHitPoints() << std::endl;
  std::cout << halo.getMaxHitPoints() << std::endl;
  std::cout << halo.getEnergyPoints() << std::endl;
  std::cout << halo.getMaxEnergyPoints() << std::endl;
  std::cout << halo.getAttackDamage() << std::endl;
	return (0);
}
