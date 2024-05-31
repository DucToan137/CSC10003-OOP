#pragma	once
#include"IParsable.h"
#include<vector>
#include<string>

class DailyEmployeeParser : public IParsable {
public:
	Object* parse(std::string data) override;
	std::string toString() override;
	std::string parsedObjectName() override;
};