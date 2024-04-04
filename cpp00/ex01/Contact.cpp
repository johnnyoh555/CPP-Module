/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jooh <jooh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 20:56:58 by jooh              #+#    #+#             */
/*   Updated: 2024/01/29 12:07:08 by jooh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact::set_firstname(const std::string& str) {
	firstname = str;
}

void	Contact::set_lastname(const std::string& str) {
	lastname = str;
}

void	Contact::set_nickname(const std::string& str) {
	nickname = str;
}

void	Contact::set_phonenumber(const std::string& str) {
	phonenumber = str;
}

void	Contact::set_darkestsecret(const std::string& str) {
	darkestsecret = str;
}

const std::string& Contact::get_firstname(void) const {
	return firstname;
}

const std::string& Contact::get_lastname(void) const {
	return lastname;
}

const std::string& Contact::get_nickname(void) const {
	return nickname;
}

const std::string& Contact::get_phonenumber(void) const {
	return phonenumber;
}

const std::string& Contact::get_darkestsecret(void) const {
	return darkestsecret;
}

void	Contact::print_info(void) const {
	std::cout <<  "firstname     :" << firstname << "\n";
	std::cout <<  "lastname      :" << lastname << "\n";
	std::cout <<  "nickname      :" << nickname << "\n";
	std::cout <<  "phonenumber   :" << phonenumber << "\n";
	std::cout <<  "darkestsecret :" << darkestsecret << std::endl;
}

Contact::Contact() : firstname(""), lastname(""), nickname(""), \
				phonenumber(""), darkestsecret("") {}

Contact::~Contact() {}