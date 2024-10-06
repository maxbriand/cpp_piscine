/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:06:44 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/30 22:39:45 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <iostream>

typedef struct Date
{
	int	year;
	int	month;
	int day;

	bool operator<(const Date& other) const 
	{
        if (year != other.year) 
			return year < other.year;
        if (month != other.month) 
			return month < other.month;
        return day < other.day;
    }
} t_date ;

int	main(void)
{
	std::map<t_date, int> test;
	test[Date{-1, -1, -1}] = 49;

	std::cout << test[Date{1000, 02, 10}] << std::endl;
	test[Date{1000, 02, 10}] = 49;

	return (0);
}
