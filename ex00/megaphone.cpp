#include <iostream>
#include <cstring>

#define MEGAPHONE_AMBIENT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

void	megaphone_string(char const *loud_string)
{
	while (*loud_string)
	{
		std::cout << static_cast<char>(std::toupper(*loud_string));
		loud_string++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << MEGAPHONE_AMBIENT << std::endl;
		return 0;
	}
	while (*++argv)
		megaphone_string(*argv);
	std::cout << std::endl;
	return 0;
}
