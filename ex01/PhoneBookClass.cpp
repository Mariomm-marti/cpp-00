#include "ContactClass.hpp"
#include "PhoneBookClass.hpp"
#include <stdexcept>
#include <sys/types.h>

PhoneBookClass::PhoneBookClass(void) {
	_index = 0;
}

PhoneBookClass::~PhoneBookClass(void) { }

void	PhoneBookClass::addContact(ContactClass &contact)
{
	if (_index >= 8)
		_index = 0;
	_contacts[_index] = contact;
	_index++;
}

ContactClass	PhoneBookClass::getContact(size_t const index) const
{
	if (index >= 8)
		throw std::invalid_argument("Invalid index for contact");
	return _contacts[index];
}
