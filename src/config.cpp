#include "config.h"

using namespace nlohmann;

Config::Config(std::string configName, std::string inputName)
{
    this->mSchemaConfigFileName = configName;
    this->mInputFileName = inputName;
}

bool Config::validateFile(const std::string filename)
{
    std::ifstream in(filename);

    if (!in)
    {
        std::cerr << filename << " failed to open" << std::endl;
        return false;
    }
    else
    {
        bool empty = (in.get(), in.eof());
        if (empty)
        {
            std::cerr << filename << " empty" << std::endl;
            return false;
        }
        else
        {
            return true;
        }
    }
}
json Config::getConfigSchema()
{
    json config_schema;
    if (!validateFile(this->mSchemaConfigFileName))
    {
        return EXIT_FAILURE;
    }
    std::ifstream i(this->mSchemaConfigFileName);

    i >> config_schema;

    return config_schema;
}

int Config::checkInput()
{
    json input;
    if (!validateFile(this->mInputFileName))
    {
        return EXIT_FAILURE;
    }
    std::ifstream i(this->mInputFileName);
    i >> input;

    json_schema::json_validator validator(this->mSchemaConfigFileName);

    try
    {
        validator.validate(input); // validate the document - uses the default throwing error-handler
        std::cout << "true" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "false" << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}