# JSON_VALIDATION_APP

This is a small app that use lib [json-schema-validator](https://github.com/pboettch/json-schema-validator) to check input format

## Getting Started

These instructions will give you a copy of the project up and running on
your local machine for development and testing purposes. See deployment
for notes on deploying the project on a live system.

### Prerequisites

Requirements for the software and other tools to build, test and push

- cmake 3.0
- Ubuntu 16
- C++11
- [json-schema-validator](https://github.com/pboettch/json-schema-validator)
- [nlohmann-json](https://github.com/nlohmann/json)

### Installing

A step by step series of examples that tell you how to get a development
environment running

1. Clone the repo

   ```sh
   git clone https://github.com/hsondd/JSON_VALIDATION_APP
   ```

3. Clone submodule

   ```sh
   git submodule update --init --recursive
   ```

4. Build source

   ```sh
   chmod +x build.sh
   ./build.sh
   ```

## Running the tests

Explain how to run the tests for this application

### Sample Tests

1. Change input at [configs/input.json]()

  ```json
  {
    "username": "booboo",
    "firstName": "Huong",
    "lastName" : "Hoang"
}
  ```

2. Change json_shema at [configs/schema.json]()

  ```json
{
    "$schema": "http://json-schema.org/draft-04/schema",
     "title": "updateUser",
     "type": "object",
     "additionalProperties": false,
     "minProperties" : 3,
     "properties": {
         "username": {
             "title": "username",
             "type": "string",
             "minLength": 1
         },
         "firstName": {
             "title": "firstName",
             "type": "string"
         },
         "lastName": {
             "title": "lastName",
             "type": "string"
         }
     },
     "required": [
         "username"
     ]
}

  ```

3. Run app to test

```sh
./build/jsonvalidationapp 
```

4. Sample result

```sh
➜  JSON_VALIDATION_APP git:(main) ✗  ./build/jsonvalidationapp 
true
```
## Authors

[SonDoan](https://github.com/hsondd)
