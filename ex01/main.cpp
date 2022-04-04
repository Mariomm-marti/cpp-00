#include "PhoneBookClass.hpp"
#include "ContactClass.hpp"
#include "utils.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>

static void		commandAdd(PhoneBookClass &book)
{
	ContactClass	contact;

	contact = ContactClass::generateContact();
	book.addContact(contact);
	std::cout << "Added contact to database...";
}

static void		printColumn(std::string print)
{
	truncateString(&print, 10);
	std::cout << std::setw(10) << print << "|";
}

static void		commandSearchDisplay(PhoneBookClass const &book)
{
	ContactClass	currentContact;
	std::string		limitedLength;

	for (size_t index = 0; index < book.getUsedCapacity(); index++)
	{
		currentContact = book.getContact(index);
		std::cout << std::setw(10) << index << "|";
		printColumn(currentContact.getFirstName());
		printColumn(currentContact.getLastName());
		printColumn(currentContact.getNickname());
		std::cout << std::endl;
	}
}

static void		commandSearchGetContactInfo(PhoneBookClass const &book)
{
	ContactClass	contact;
	size_t			seekIndex;

	std::cout << "Contact to seek: ";
	std::cin >> seekIndex;
	if (std::cin.fail())
		throw std::invalid_argument("Invalid index");

	contact = book.getContact(seekIndex);

	std::cout << "Name: " << contact.getFirstName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone: " << contact.getPhone() << std::endl;
	std::cout << "Secret: " << contact.getSecret();
}

static void		commandSearch(PhoneBookClass const &book)
{
	commandSearchDisplay(book);
	try
	{
		commandSearchGetContactInfo(book);
	} catch (std::invalid_argument const &)
	{
		std::cout << "Invalid index in book";
	}
}

int		main(void)
{
	PhoneBookClass	book;
	std::string		command;

	std::cout << "$ ";
	std::getline(std::cin, command);
	while (command != "EXIT")
	{
		if (command == "ADD")
			commandAdd(book);
		else if (command == "SEARCH")
			commandSearch(book);
		if (command == "ADD" || command == "SEARCH")
		{
			std::cin.ignore(INT_MAX, '\n');
			std::cin.clear();
		}
		std::cout << std::endl;
		std::cout << "$ ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			command = "EXIT";
	}
	return 0;
}
