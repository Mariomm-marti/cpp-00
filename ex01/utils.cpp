#include <string>

void	truncateString(std::string *truncate, size_t const maxlen)
{
	if (truncate->size() <= maxlen)
		return ;
	*truncate = truncate->substr(0, maxlen - 1);
	*truncate = *truncate + ".";
}
