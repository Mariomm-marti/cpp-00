#include "ContactClass.hpp"

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
