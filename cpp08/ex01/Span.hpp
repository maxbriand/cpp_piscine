/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:22:09 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/27 14:01:15 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdarg>
# include <stdexcept>
# include <iterator>

class Span
{
    private:
        unsigned int        _N;
        std::vector <int>   _int_vector;
    public:
        Span(unsigned int N);
        void        addNumbers(int* begin, int* end);
        void        addNumber(int i);
        int         shortestSpan();
        int         longestSpan();
    public:
        Span(void);
        ~Span();
        Span(const Span& src);
        Span& operator=(const Span& src);
};

#endif