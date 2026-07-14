#include "interface.hpp"
#include <iostream>
#include <string>

// TODO
// - command parsing


int main()
{
	CShell * sh = new CShell("shell> ");
	while (true) {
		sh->prompt();
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
			// cd
			break;
		}
		else {
			// fork + command
			break;
		}
	}
	return 0;
}