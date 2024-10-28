/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:59:40 by mkadri            #+#    #+#             */
/*   Updated: 2024/10/28 15:32:20 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>

class Fixed {
    
    private:
        int                 _value;
        static const int    _frac;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const &copy);
        Fixed   &operator=(Fixed const &copy);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

#endif