#include <cstdlib>
#include <iostream>
#include <sched.h>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>
#include <readline/history.h>
#include <readline/readline.h>


#include "shell.hpp"

// TODO
// - pipes

int main()
{
	CShell sh;
	while (true) {
		pid_t pid = 0;
		char * line = readline(sh.prompt().c_str());

		if (line == nullptr) 
		{
			break;
		}

		std::string input(line);

		if (!input.empty()) 
		{
			add_history(line);	
		}
		std::free(line);

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
			sh.run(c);
		}
	}
	return 0;
}