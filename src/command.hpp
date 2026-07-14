#include <string>
#include <vector>

class CCommand
{
private:
    int argc_ = 0;
    std::vector<std::string> argv_;
public:
    CCommand(std::string argv);
};