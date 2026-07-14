#include <iostream>
#include <string>
#include <filesystem>

#include "shell.hpp"

CShell::CShell(std::string user)
: user_(user)
{
	cd("~");
}
CShell::CShell(std::string user, std::string dir)
: user_(user)
{
	cd(dir);
}
void CShell::prompt()
{
	std::cout << user_ + " " + dir_ + "> " << std::flush;
}

void CShell::cd(std::string path)
{
	if (path == ("/home/" + user_ )) {
		path = "~";
	}
	dir_ = path;
}

int CShell::run(CCommand & command)
{
	return 0;
}