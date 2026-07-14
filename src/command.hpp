#include <string>
#include <vector>

class CCommand
{
private:
    std::string name_;
    int argc_;
    std::vector<std::string> argv_;
public:
    CCommand(std::string argv);
};