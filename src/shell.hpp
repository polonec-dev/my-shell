#include <iostream>
#include <string>

#include "command.hpp"

class CShell
{
private:
	std::string dir_;
	std::string user_;
public:
	CShell(std::string user);
	CShell(std::string user, std::string dir);
	void prompt();
	void cd(std::string path);
	int run(CCommand & command);
};