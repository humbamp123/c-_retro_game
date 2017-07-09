/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MissileRain.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 14:54:25 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 15:03:55 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_RAIN
# define MISSILE_RAIN

class Missile {
 public:
  Missile(void);
  Missile(Missile const & src);
  Missile & operator=(Missile const &rhs);
  ~Missile(void);

  MissileRain *getData() const;
  unsigned int getDataSize() const;
  void update();
};

#endif
