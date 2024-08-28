/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:08:08 by mbriand           #+#    #+#             */
/*   Updated: 2024/08/28 16:06:10 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
# define TEST_HPP

class Test
{
	public:
		char	a;
		int		b;
		Test(char c, int d);
		~Test(void);
		int yep = 9;
		void bar(void);
};




#endif