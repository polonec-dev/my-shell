#include <iostream>
#include <string>

class CShell
{
private:
	std::string prompt_;
public:
	CShell(std::string pr);
	void prompt();
};