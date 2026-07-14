#include "interface.hpp"
#include <iostream>

// TODO
// - reprint prompt when input is only whitespace chars


int main()
{
	CShell * sh = new CShell("shell> ");
	std::string input;
	while (true) {
		sh->prompt();
		std::cin >> input;
	}
}