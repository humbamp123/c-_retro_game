/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Star.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:12:45 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 21:42:52 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STAR_H
# define STAR_H

# include "Character.class.hpp"

class Star : public Character {
 public:
  Star(void);
  Star(Star const & src);
  Star & operator=(Star const &rhs);
  ~Star(void);

  void spawn(void);
  void setStatus(bool status);
  bool getStatus(void);
  int getBounds(void);
  void moveStar(void);
 private:
  int _xDirection;
  bool _status;
  int _bounds;
};

#endif
