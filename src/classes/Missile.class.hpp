/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:11:56 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 14:13:58 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_H
# define MISSILE_H

class Missile : public player, public enemy {
 public:
  Missile(void);
  Missile(Missile const & src);
  Missile & operator=(Missile const &rhs);
  ~Missile(void);
 private:
};

#endif
