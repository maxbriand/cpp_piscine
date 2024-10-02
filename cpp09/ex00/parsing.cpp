/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:12:04 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/30 22:38:06 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "parsing.hpp"

// check if the file is correctly close in this case?
void	check_input_first_line(std::string buffer)
{
	size_t		i;
	int			j;

	i = 0;
	j = 0;
	while (j < 3)
	{
		if (j != 0 && !std::isspace(buffer[i]))
			{std::cerr << "Error: Add space between column categories!" << std::endl; exit (1);}			
		while (std::isspace(buffer[i]) && i < buffer.length())
			i++;
		if (j == 0 && !std::strncmp(buffer.c_str() + i, "date", 4))
			i += 4;
		else if (j == 1 && !std::strncmp(buffer.c_str() + i, "|", 1))
			i += 1;
		else if (j == 2 && !std::strncmp(buffer.c_str() + i, "value", 5))
			i += 5;
		else
			{std::cerr << "Error: Incorrect category element!" << std::endl; exit (1);}
		j++;
	}
}

// check if the lenght is correctly check creating input with line not long enough
void	check_and_get_all_input_lines(std::ifstream& file, std::map<t_date, int>& input)
{
	std::string buffer;
	int			j;
	int			i;

	j = 0;
	i = 0;
	k = 0;
	while (std::getline(file, buffer))
	{		
		while (std::isspace(buffer[i]) && i < buffer.length())
			i++;
		if (j == 0)
		{
			if (buffer.length() - i < 10)
				{input[t_date{-1, -1, -1}] = -1; continue;}			
			if (!std::isdigit(buffer[i]) || !std::isdigit(buffer[i+1]) || !std::isdigit(buffer[i+2]) \
				|| !std::isdigit(buffer[i+3]) || !std::isdigit(buffer[i+5]) || !std::isdigit(buffer[i+6]) \
				|| !std::isdigit(buffer[i+8]) || !std::isdigit(buffer[i+9]) || buffer[i + 4] != '-') \
				|| buffer[i+7] != '-';
				{input[t_date{-1, -1, -1}] = -1; continue;}			


		}
		i = 0;
		k++;
	}
	(void) input;
}

void	parsing(int ac, char **av, std::map<t_date, int>& input)
{
	std::string	buffer;
	
	if (ac > 2 || ac < 2)
		{std::cerr << "Error: Incorrect argument number!" << std::endl; exit (1);}
	std::ifstream file(av[1]);	
	if (!file.is_open())
		{std::cerr << "Error: File doesn't exist!" << std::endl; exit (1);}
	if (!std::getline(file, buffer))
		{std::cerr << "Error: Read file issue!" << std::endl; exit (1);}	
	check_input_first_line(buffer);
	check_and_get_all_input_lines(file, input);


	file.close();


}
