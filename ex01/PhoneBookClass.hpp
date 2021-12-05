#ifndef CPP00_EX01_PHONEBOOK_CLASS_H_
# define CPP00_EX01_PHONEBOOK_CLASS_H_

# include "ContactClass.hpp"
# include <sys/types.h>

class	PhoneBookClass
{
private:
	ContactClass	_contacts[8];
	size_t			_index;

public:
	PhoneBookClass(void);
	~PhoneBookClass(void);

	void			addContact(ContactClass &contact);
	ContactClass	getContact(size_t const index) const;
};

#endif
