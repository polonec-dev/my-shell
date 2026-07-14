#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "shell.hpp"
#include "command.hpp"

// TODO
// - command parsing

int main()
{
	CShell sh("shell> ");
	while (true) {
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

		if(input == "exit")
		{
			break;
		}
		else if (input == "cd") {
			CCommand c(input);
			break;
		}
		else {
			// fork + command
			CCommand c(input);
		}
	}
	return 0;
}