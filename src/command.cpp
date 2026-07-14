#include <iostream>
#include <sstream>
#include <string>
#include <vector>


#include "command.hpp"

CCommand::CCommand(int argc, std::string argv)
: argc_(argc - 1)
{
    std::istringstream is(argv);
    is >> name_;

	std::string tmp;
	while (is >> tmp) {
		argv_.push_back(tmp);
	}
}