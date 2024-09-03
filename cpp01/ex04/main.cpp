/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:41:51 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/03 16:02:56 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int	errmsg(std::string msg)
{
	std::cout << msg << std::endl;
	return (1);
}

std::string	replace(std::string content, std::string str1, std::string str2)
{
	size_t	pos;
	size_t	lens1;
	size_t	lens2;

	lens1 = str1.length();
	lens2 = str2.length();
	pos = 0;
	while (1)
	{
		if (content.substr(pos).find(str1) == std::string::npos)
			break ;
		pos += content.substr(pos).find(str1);
		content.erase(pos, lens1);
		content.insert(pos, str2);
		pos += lens2;
	}
	return (content);
}

int	main(int ac, char **av)
{
	std::string 		filename;
	std::string			replace_filename;
	std::string			content;
	std::stringstream	buffer;
	std::string 		str1;
	std::string 		str2;

	if (ac < 4 || ac > 4)
		return (errmsg("You have to pass three parameters to the program"));
	// Variable initialization
	filename = av[1];
	replace_filename = filename + ".replace";
	str1 = av[2];
	str2 = av[3];
	if (str1.empty())
		return (errmsg("The string to search cannot be an empty string"));
	// Open input file, get its value and replace it
	std::ifstream file(filename.c_str());
	if (!file)
		return (errmsg("error occurs during input file opening"));
	buffer << file.rdbuf();
	file.close();
	content = replace(buffer.str(), str1, str2);
	// Copy the content in the other file
	std::ofstream replace_file(replace_filename.c_str());
	if (!replace_file)
		return (errmsg("error occurs during replace_file opening"));
	replace_file << content;
	replace_file.close();
	return (0);
}
