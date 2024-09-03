/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:29:58 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/03 20:36:35 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class   Fixed
{
    public:
        Fixed();
        ~Fixed();
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

    private:
        int                 value;
        static const int    eight;      

};

#endif
