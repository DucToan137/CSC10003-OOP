#include"Book.h"
#include"Fiction.h"
#include"NonFiction.h"
#include"Comic.h"


class Parser {
public:
	static Book* parseBook(string input);
};
