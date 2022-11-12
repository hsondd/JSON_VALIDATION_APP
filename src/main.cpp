#include <iostream>
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>

#include <nlohmann/json-schema.hpp>

using nlohmann::json;
using nlohmann::json_schema::json_validator;
using namespace nlohmann;

int get_input(const std::string& filename, json &input, json config_schema)
{
	std::ifstream i(filename);
	i >> input;

	json_schema::json_validator validator(config_schema);

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

int main()
{
    json config_schema;
    json input;
	int status;
    
    json_validator validator; // create validator

    std::ifstream i(INPUT_PATH + "schema.json");
	i >> config_schema;

    try {
        validator.set_root_schema(config_schema); // insert root-schema
    } catch (const std::exception &e) {
        std::cerr << "Validation of schema failed, here is why: " << e.what() << "\n";
        return EXIT_FAILURE;
    }

    if ((status = get_input(INPUT_PATH + "input.json", input, config_schema)) != 0)
	{
		return status;
	}

    return EXIT_SUCCESS;
}