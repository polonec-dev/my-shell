#include <iostream>
#include <sched.h>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>


#include "shell.hpp"

// TODO
// - command parsing

int main()
{
	CShell sh("root");
	while (true) {
		pid_t pid = 0;
		sh.prompt();
		std::string input;

		if (!std::getline(std::cin, input))
		{
			break;
		}

		if (input.empty()) 
		{
			continue;
		}

		CCommand c(input);

		if(c.name() == "exit")
		{
			break;
		}
		else if (c.name() == "cd") {
			
			if (c.argc() < 2) {
				sh.cd("~");
			}
			else {
				sh.cd(c.argv(1));
			}
		}
		else {
			// fork + command
			sh.run(c);
		}
	}
	return 0;
}