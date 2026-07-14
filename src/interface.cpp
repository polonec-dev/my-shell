#include <iostream>

#include "interface.hpp"

CShell::CShell(std::string pr)
: prompt_(pr) {}
void CShell::prompt()
{
	std::cout << prompt_ << std::flush;
}