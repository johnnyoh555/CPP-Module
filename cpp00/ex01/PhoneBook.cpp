/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:32:35 by jooh              #+#    #+#             */
/*   Updated: 2024/01/27 15:25:55 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook() : idx(0), cnt(0) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::ft_add() {
	std::string	temp;

	while (1)
	{
		std::cout << "firstname: " << std::flush;
		std::getline(std::cin, temp);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
		}
		if (is_printalbe(temp))
			continue;
		if (!temp.empty())
			break ;
	}
	contact[idx].set_firstname(temp);
	
	while (1)
	{
		std::cout << "lastname: " << std::flush;
		std::getline(std::cin, temp);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
		}
		if (is_printalbe(temp))
			continue;
		if (!temp.empty())
			break ;
	}
	contact[idx].set_lastname(temp);
	
	while (1)
	{
		std::cout << "nickname: " << std::flush;
		std::getline(std::cin, temp);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
		}
		if (is_printalbe(temp))
			continue;
		if (!temp.empty())
			break ;
	}
	contact[idx].set_nickname(temp);
	
	while (1)
	{
		std::cout << "phonenumber: " << std::flush;
		std::getline(std::cin, temp);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
		}
		if (is_digit(temp))
			continue;
		if (!temp.empty())
			break ;
	}
	contact[idx].set_phonenumber(temp);
	
	while (1)
	{
		std::cout << "darkestsecret: " << std::flush;
		std::getline(std::cin, temp);
		if (std::cin.fail())
		{
			std::cin.clear();
			std::clearerr(stdin);
			std::cout << std::endl;
		}
		if (is_printalbe(temp))
			continue;
		if (!temp.empty())
			break ;
	}
	contact[idx].set_darkestsecret(temp);
	
	idx = (idx + 1) % MAX_INDEX;
	if (cnt < MAX_INDEX)
		cnt++;
}

void	PhoneBook::ft_search() {
	std::string str;
	int			tmp;
	
	std::cout << "-------------------------------------------" << std::endl;
	if (cnt == 0)
		return ;
	for (int i = 0; i < cnt; i++)
		print_Contact(i);
	std::cout << "\n" << "index want to find: " << std::flush;
	std::getline(std::cin, str);
	if (std::cin.fail())
	{
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << std::endl;
		return ;
	}
	if (is_digit(str))
		return;
	tmp = atoi(str.c_str());
	if (tmp < 0 || tmp >= cnt)
		return ;
	ft_search(tmp);
}

void	PhoneBook::ft_search(int idx) {
	if (idx >= cnt)
		return ;
	contact[idx].print_info();
}

void	PhoneBook::print_Contact(int i) {
	std::cout << std::setw(10);
	
	std::cout << i % 8 << "|" << std::flush;
	std::cout << std::setw(10);
	std::cout << cut_info(contact[i].get_firstname()) << "|" << std::flush;
	std::cout << std::setw(10);
	std::cout << cut_info(contact[i].get_lastname())<< "|" << std::flush;
	std::cout << std::setw(10);
	std::cout << cut_info(contact[i].get_nickname())<< std::endl;
}

const	std::string PhoneBook::cut_info(const std::string str) {
	if (str.size() > 10)
		return str.substr(0,10).replace(9, 1, ".");
	return str;
}

int		PhoneBook::is_printalbe(std::string& str) const {
	for (int i = 0; i < (int)str.size(); i++)
		if (!std::isprint(str[i]))
			return (1);
	return (0);
}
int		PhoneBook::is_digit(std::string& str) const {
	for (int i = 0; i < (int)str.size(); i++)
		if (!std::isdigit(str[i]))
			return (1);
	return (0);
}
