#include "ContactClass.hpp"
#include "PhoneBookClass.hpp"
#include <stdexcept>
#include <sys/types.h>

PhoneBookClass::PhoneBookClass(void) {
	_index = 0;
	_usedCapacity = 0;
}

PhoneBookClass::~PhoneBookClass(void) { }

void	PhoneBookClass::addContact(ContactClass &contact)
{
	if (_index >= 8)
		_index = 0;
	if (_usedCapacity < 8)
		_usedCapacity++;
	_contacts[_index] = contact;
	_index++;
}

size_t	PhoneBookClass::getUsedCapacity(void) const
{
	return _usedCapacity;
}

ContactClass	PhoneBookClass::getContact(size_t const index) const
{
	if (index >= 8 || index >= _usedCapacity || _usedCapacity == 0)
		throw std::invalid_argument("Invalid index for contact");
	return _contacts[index];
}
