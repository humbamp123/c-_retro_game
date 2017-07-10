/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Space.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 21:25:44 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/07/09 22:46:15 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACE_H
#define SPACE_H

#include "Star.class.hpp"

class Space {
 public:
  Space(void);
  Space(int n, int xMax, int yMax);
  Space(Space const &src);
  Space &operator=(Space const &rhs);
  ~Space(void);

  Star *getData(void) const;
  unsigned int getDataSize(void) const;
  void update(void);

 private:
  Star *_starField;
  unsigned int _size;
};

#endif
