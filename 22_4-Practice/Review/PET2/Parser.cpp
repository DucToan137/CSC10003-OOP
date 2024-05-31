#include "Parser.h"


Parsable* Parser::create(string type) {
    if (type == "Dog") {
        return new DogParser();
    }
    else if (type == "Cat") {
        return new CatParser();
    }
    else if (type == "Bird") {
        return new BirdParser();
    }
    else {
        return nullptr;
    }
}

Pet* Parser::parse(string line) {
    istringstream iss(line);
    string type;
    iss >> type;
    Parsable* parser = create(type);
    if (parser) {
        return parser->parse(line);
    }
    else {
        return nullptr;
    }
}