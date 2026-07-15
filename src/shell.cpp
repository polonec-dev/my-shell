#include <cstddef>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <sched.h>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <vector>

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

int CShell::run(CCommand command)
{
	pid_t pid;
	pid = fork();
	if (pid == -1) 
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		std::vector<char *> cargv;
		for (size_t i = 0; i < command.argv().size(); i++) 
		{
			cargv.push_back(const_cast<char *>(command.argv(i).c_str()));
		}
		cargv.push_back(nullptr);
		execvp(command.name().c_str(), cargv.data());
		perror("execvp");
		_exit(127);
	}
	else
	{
		prompt();
		return 0;
	}
}