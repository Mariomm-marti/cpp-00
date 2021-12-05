#ifndef CPP00_EX01_PHONEBOOK_CLASS_H_
# define CPP00_EX01_PHONEBOOK_CLASS_H_

# include "ContactClass.hpp"
# include <sys/types.h>

class	PhoneBookClass
{
private:
	ContactClass	_contacts[8];
	size_t			_index;
	size_t			_usedCapacity;

public:
	PhoneBookClass(void);
	~PhoneBookClass(void);

	void			addContact(ContactClass &contact);
	size_t			getUsedCapacity(void) const;
	ContactClass	getContact(size_t const index) const;
};

#endif
