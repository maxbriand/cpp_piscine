/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:29:58 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/06 17:36:38 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class   Fixed
{
    public:
                Fixed(void);
                Fixed(const Fixed& number);
                ~Fixed(void);
        Fixed&  operator=(const Fixed& number);
    public:
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                 _number;
        static const int    _bits = 8;

};

#endif
