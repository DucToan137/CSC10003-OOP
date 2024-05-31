#include"ParserFactory.h"
#include"RectangleParser.h"
#include"SquareParser.h"
#include"CircleParser.h"


void ParserFactory::registerWith(IParsable* parser) {
	_container.insert(
		{ parser->parsedObjectName(), parser }
	);
}

IParsable* ParserFactory::create(std::string type) {
	IParsable* parser = NULL;
	if ("Rectangle" == type) {
		parser = new RectangleParser();
	}
	else if ("Square" == type) {
		parser = new SquareParser();
	}
	else if ("Circle" == type) {
		parser = new CircleParser();
	}
	this->registerWith(parser);
	return _container[type];
}

std::string ParserFactory::toString() {
	return "Move to ParseFactory";
}