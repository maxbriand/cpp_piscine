/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:20:48 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/24 16:17:48 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <climits>
# include "colors.hpp"
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

	public:
		static void	convert(const char* str);
};

#endif
