#pragma once
#include"Parsable.h"
#include"DogParser.h"
#include"CatParser.h"
#include"BirdParser.h"



class Parser {
public:
    static Parsable* create(string type);
    static Pet* parse(string line);
};