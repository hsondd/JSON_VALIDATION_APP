#include <iostream>
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>

#include <nlohmann/json-schema.hpp>

using nlohmann::json;
using nlohmann::json_schema::json_validator;
using namespace nlohmann;

class Config
{

private:
    std::string mSchemaConfigFileName;
    std::string mInputFileName;

    bool validateFile(const std::string filename);

public:
    Config(const std::string configName, const std::string inputName);
    json getConfigSchema();
    int checkInput(json configSchema);
};