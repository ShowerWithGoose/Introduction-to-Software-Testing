#include "ErrorCollector.h"



ErrorCollector ErrorCollector::error_collector;

ErrorCollector::ErrorCollector() = default;

bool ErrorCollector::hasError() {
	return !error_collector.error_lines.empty();
}

void ErrorCollector::meet_error(const char error_type, const int error_line)
{
	error_collector.error_types.push_back(error_type);
	error_collector.error_lines.push_back(error_line);
}

void ErrorCollector::put_error(std::ostream& output)
{
	auto it1 = error_collector.error_lines.begin();
	auto it2 = error_collector.error_types.begin();
	while (it1 != error_collector.error_lines.end() && it2 != error_collector.error_types.end())
	{
		output << *it1 << " " << *it2 << std::endl;
		++it1;
		++it2;
	}
}
