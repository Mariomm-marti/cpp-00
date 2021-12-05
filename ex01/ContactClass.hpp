#ifndef CPP00_EX01_CONTACT_CLASS_H_
# define CPP00_EX01_CONTACT_CLASS_H_

# include <string>

class	ContactClass
{
private:
	std::string		firstName;
	std::string		lastName;
	std::string		nickname;
	std::string		phone;
	std::string		secret;

public:
	ContactClass(void);
	ContactClass(
			std::string const firstName,
			std::string const lastName,
			std::string const nickname,
			std::string const phone,
			std::string const secret
		);
	~ContactClass(void);

	ContactClass	&operator=(ContactClass const &rhs);

	std::string		getFirstName(void) const;
	std::string		getLastName(void) const;
	std::string		getNickname(void) const;
	std::string		getPhone(void) const;
	std::string		getSecret(void) const;
};

#endif
