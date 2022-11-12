#include <iostream>
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "config.h"
#include <nlohmann/json-schema.hpp>

using nlohmann::json;
using nlohmann::json_schema::json_validator;
using namespace nlohmann;

static const std::string CONFIG_SCHEMA_PATH = INPUT_PATH + "schema.json";
static const std::string INPUT_TC_PATH = INPUT_PATH + "input.json";

int main()
{
	int status;
	json_validator validator;
	json configSchema;

	Config ValidateUser(CONFIG_SCHEMA_PATH, INPUT_TC_PATH);
	configSchema = ValidateUser.getConfigSchema();

	try
	{
		validator.set_root_schema(configSchema); // insert root-schema
	}
	catch (const std::exception &e)
	{

		std::cerr << "Validation of schema failed, here is why: " << e.what() << "\n";
		return EXIT_FAILURE;
	}

	if ((status = ValidateUser.checkInput(configSchema)) != 0)
	{
		return status;
	}

	return EXIT_SUCCESS;
}