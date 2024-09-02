/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:41:51 by mbriand           #+#    #+#             */
/*   Updated: 2024/09/02 17:00:47 by mbriand          ###   ########.fr       */
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

// TRY PROGRAM WITH EMPTY STR1 AND STR2
std::string	replace(std::string content, std::string str1, std::string str2)
{
	size_t	strpos;
	size_t	len;

	len = str1.length();
	while (1)
	{
		strpos = content.find(str1);
		if (strpos == std::string::npos)
			break ;
		content.erase(strpos, len);
		// add new string
		std::cout << content << std::endl;
	}
	(void) str2;	
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
	// Open input file, get its value and replace it
	std::ifstream file(filename.c_str());
	if (!file)
		return (errmsg("error occurs during input file opening"));
	buffer << file.rdbuf();
	content = replace(buffer.str(), str1, str2);
	// Copy the content in the other file
	std::ofstream replace_file(replace_filename.c_str());
	if (!replace_file)
		return (errmsg("error occurs during replace file opening"));
	replace_file << content;
	// Do I need to close files?
	return (0);
}
