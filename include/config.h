#include <iostream>
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>

#include <nlohmann/json-schema.hpp>

using nlohmann::json;
using nlohmann::json_schema::json_validator;
using namespace nlohmann;

static const json CONFIG_SCHEMA = 
{
	{"$schema", "http://json-schema.org/draft-07/schema#"},
	{"title", "Game config"},
	{"properties", {
		{"game_name", {
			{"description", "Name of the game"},
			{"type", "string"}
		}},
		{"window_width", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 600}
		}},
		{"window_height", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 500}
		}},
		{"game_width", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 600}
		}},
		{"game_height", {
			{"description", "Name"},
			{"type", "integer"},
			{"minimum", 500}
		}}
	}},
	{"required", {
		"game_name",
		"window_width",
		"window_height",
		"game_width",
		"game_height"
	}},
	{"type", "object"}
};

class Config
{

private:
    std::string mSchemaConfigFileName;
    std::string mInputFileName;

    bool validateFile(const std::string filename);

public:
    std::string getName()
    {
        std::cout << "sondh" << this->mSchemaConfigFileName;
        return this->mSchemaConfigFileName;
    }
    Config(const std::string configName, const std::string inputName);
    json getConfigSchema();
    int checkInput();
};