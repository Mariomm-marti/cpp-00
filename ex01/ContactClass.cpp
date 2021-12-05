#include "ContactClass.hpp"
#include <iostream>

ContactClass::ContactClass(void) : firstName("Mario"), lastName("Martin"), nickname("vim"), phone("634768271"), secret("c'est la vim") { }

ContactClass::ContactClass(
		std::string const firstName,
		std::string const lastName,
		std::string const nickname,
		std::string const phone,
		std::string const secret
	) : firstName(firstName), lastName(lastName), nickname(nickname), phone(phone), secret(secret) { }

ContactClass::~ContactClass(void) { }

ContactClass	&ContactClass::operator=(ContactClass const &rhs)
{
	firstName = rhs.firstName;
	lastName = rhs.lastName;
	nickname = rhs.nickname;
	phone = rhs.phone;
	secret = rhs.secret;
	return *this;
}

ContactClass	ContactClass::generateContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phone;
	std::string	secret;

	std::cout << "Contact name: ";
	std::cin >> firstName;
	std::cout << "Contact last name: ";
	std::cin >> lastName;
	std::cout << "Contact nickname: ";
	std::cin >> nickname;
	std::cout << "Contact phone: ";
	std::cin >> phone;
	std::cout << "Contact secret: ";
	std::cin >> secret;
	return ContactClass(firstName, lastName, nickname, phone, secret);
}

std::string		ContactClass::getFirstName(void) const
{
	return firstName;
}

std::string		ContactClass::getLastName(void) const
{
	return lastName;
}

std::string		ContactClass::getNickname(void) const
{
	return nickname;
}

std::string		ContactClass::getPhone(void) const
{
	return phone;
}

std::string		ContactClass::getSecret(void) const
{
	return secret;
}
