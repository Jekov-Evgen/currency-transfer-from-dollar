#include <command.h>

std::string returnCommand(std::string command) {
    char buffer[4096];
    std::string result;

    FILE* pipe = _popen(command.c_str(), "r");

    if (!pipe) {
        throw std::runtime_error("Filed open");
    }

    while (std::fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result += buffer;
    }
    
    int returnCode = _pclose(pipe);

    if (returnCode != 0) {
        throw std::runtime_error("Filed succeful command");
    }

    return result;
}