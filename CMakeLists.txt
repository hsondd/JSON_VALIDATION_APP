cmake_minimum_required(VERSION 3.8.2 FATAL_ERROR)
project(JSON_VALIDATOR_APP LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(lib/nlohmann_json)
add_subdirectory(lib/nlohmann_json_schema_validator)

# find_package(nlohmann_json REQUIRED)
# find_package(nlohmann_json_schema_validator REQUIRED)

set(COMPILATION_PREFIX_EXEC jsonvalidationapp)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/include INCLUDES)
file(GLOB SOURCES src/*.cpp)
add_executable(${COMPILATION_PREFIX_EXEC} ${SOURCES} ${INCLUDES})
target_include_directories(${COMPILATION_PREFIX_EXEC}
        PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )
target_sources(${COMPILATION_PREFIX_EXEC} PUBLIC ${SOURCES})
set_target_properties(${COMPILATION_PREFIX_EXEC} PROPERTIES CXX_STANDARD 17)
target_link_libraries(${COMPILATION_PREFIX_EXEC} PUBLIC nlohmann_json::nlohmann_json nlohmann_json_schema_validator)
# target_compile_definitions(${COMPILATION_PREFIX_EXEC} PUBLIC "CONFIGS_PATH=std::string\(\"${CMAKE_CURRENT_SOURCE_DIR}/configs/\"\)")
