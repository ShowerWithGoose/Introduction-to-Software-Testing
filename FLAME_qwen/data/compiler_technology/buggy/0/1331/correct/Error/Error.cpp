#include "Error.h"

void Error::error(char type, int line) {
    error_list.emplace_back(type, line);
}
