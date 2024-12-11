#include <command.h>
#include <nlohmann/json.hpp>

int main() {
    std::string result = returnCommand("curl -s \"https://open.er-api.com/v6/latest/USD\"");
    std::string currency;
    nlohmann::json objectJson;

    try
    {
        objectJson = nlohmann::json::parse(result);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "Enter the required currency: ";
    std::cin >> currency;

    std::cout<< "Rate in relation to the dollar to your currency: " << objectJson["rates"][currency] << std::endl;
}