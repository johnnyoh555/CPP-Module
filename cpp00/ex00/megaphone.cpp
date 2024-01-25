/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 21:01:44 by jooh              #+#    #+#             */
/*   Updated: 2024/01/25 13:51:57 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char *av[]){
	std::string	str;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
		str += av[i];
	for (std::string::size_type i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
	std::cout << "\e[33m" << str << "\e[0m" << std::endl;
	return (0);
}
