/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:15:10 by mbriand           #+#    #+#             */
/*   Updated: 2024/10/01 14:25:11 by mbriand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HPP
# define PARSING_HPP

# include <cstdlib>
# include <fstream>
# include <iostream>
# include <string>
# include <cstring>
# include <cstddef>
# include <map>

void	parsing(int ac, char **av, std::map<t_date, int>& input);

#endif