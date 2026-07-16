#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <sched.h>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <vector>
#include <sys/wait.h>
#include <filesystem>

#include "command.hpp"

class CShell
{
private:
	std::string user_;
public:
	CShell();
	CShell(std::string dir);
	std::string prompt();
	void cd(std::string path);
	int run(CCommand command);
};