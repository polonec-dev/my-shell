#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <sched.h>
#include <string>
#include <filesystem>
#include <unistd.h>
#include <vector>
#include <sys/wait.h>
#include <filesystem>
#include <pwd.h>

#include "shell.hpp"

CShell::CShell()
{
	user_ = std::getenv("USER");
}
CShell::CShell(std::string dir)
{
	user_ = std::getenv("USER");
	cd(dir);
}
std::string CShell::prompt()
{
	std::string path = std::filesystem::current_path().string();
	if (path == std::getenv("HOME")) 
	{
		path = "~";	
	}
	return user_ + " " + path + "> ";
}

void CShell::cd(std::string path)
{
	if (path == ("~")) {
		path = std::getenv("HOME");
	}
	if (chdir(path.c_str()) == -1) {
		perror("chdir");
	};
}

int CShell::run(CCommand command)
{
	pid_t pid;
	pid = fork();
	if (pid == -1) 
	{
		perror("fork");
		return -1;
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
		int status;
		if (waitpid(pid, &status, 0) == -1) 
		{
			perror("waitpid");
		}
		return 0;
	}
}