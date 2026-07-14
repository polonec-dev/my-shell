#include <iostream>
#include <sstream>
#include <string>
#include <vector>


#include "command.hpp"

CCommand::CCommand(std::string argv)
{
    std::istringstream is(argv);
    is >> name_;

    argc_ = 0;
	std::string tmp;
	while (is >> tmp) {
        argc_++;
		argv_.push_back(tmp);
	}
}