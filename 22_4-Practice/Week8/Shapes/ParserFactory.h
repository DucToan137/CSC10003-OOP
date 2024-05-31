#pragma once
#include"IParsable.h"
#include<map>
#include<string>


class ParserFactory : public Object {
private:
	std::map<std::string, IParsable*> _container; // A container for all the dependencies injection
public:
	void registerWith(IParsable* parser);
	IParsable* create(std::string type);
	std::string toString() override;
};


