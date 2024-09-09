/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:31:03 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/08 21:25:57 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class   Fixed
{
    public:
							Fixed(void);
							Fixed(const Fixed& fixed_number);
							~Fixed(void);
        Fixed&  			operator=(const Fixed& fixed_number);
    public:
							Fixed(const int number);
							Fixed(const float number);
        int     			getRawBits(void) const;
        void    			setRawBits(int const raw);
		float 				toFloat(void) const;
		int 				toInt(void) const;
		Fixed				operator+(const Fixed& rn) const;
		Fixed				operator-(const Fixed& rn) const;
		Fixed				operator*(const Fixed& rn) const;
		Fixed				operator/(const Fixed& rn) const;
		bool				operator>(const Fixed& rn) const;
		bool				operator<(const Fixed& rn) const;
		bool				operator>=(const Fixed& rn) const;
		bool				operator<=(const Fixed& rn) const;
		bool				operator==(const Fixed& rn) const;
		bool				operator!=(const Fixed& rn) const;
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);
		static Fixed&		min(Fixed& fp1, Fixed& fp2);
		static const Fixed&	min(const Fixed& fp1, const Fixed& fp2);
		static Fixed&		max(Fixed& fp1, Fixed& fp2);
		static const Fixed&	max(const Fixed& fp1, const Fixed& fp2);

    private:
        int                 _fixed_point_number;
        static const int    _bits = 8;
};

std::ostream& operator<<(std::ostream& o, const Fixed& fixed_number);

#endif
