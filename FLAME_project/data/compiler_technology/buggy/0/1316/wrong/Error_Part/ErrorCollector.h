#ifndef ERROR_H_

#include <iostream>
#include <list>

#define ILLEGAL_SYMBOL 'a'
using std::list;
class ErrorCollector {
public:
	static bool hasError();
	static void meet_error(char error_type, int error_line);
	static void put_error(std::ostream& output);
private:
	ErrorCollector();
	list<int> error_lines;
	list<char> error_types;
	static ErrorCollector error_collector;
};

#endif