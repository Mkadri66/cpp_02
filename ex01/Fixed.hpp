/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:37:07 by mkadri            #+#    #+#             */
/*   Updated: 2024/10/29 11:02:34 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
    
    private:
        static int const	_bits;
        int					_n;
    public:
        // Constructors & destructor
        Fixed();
        Fixed(int const n);
        Fixed(float const f);
        Fixed(Fixed const & fCpy);
        ~Fixed();
        
        //  Overload operator
        Fixed&	operator=(Fixed const & rhs);

        int		getRawBits() const;
        void	setRawBits(int const raw);
        float	toFloat() const ;
        int		toInt() const;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

#endif