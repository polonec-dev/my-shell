#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


#include "command.hpp"

CCommand::CCommand(std::string argv)
{
    std::istringstream is(argv);
	std::string tmp;
	while (is >> tmp) {
        argc_++;
		argv_.push_back(tmp);
	}
}

std::string CCommand::name()
{
	return argv(0);
}

std::vector<std::string> CCommand::argv()
{
	return argv_;
}

std::string CCommand::argv(size_t id)
{
	return argv_.at(id);
}

int CCommand::argc()
{
	return argv_.size();
}