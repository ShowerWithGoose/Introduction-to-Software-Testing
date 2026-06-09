//
// Created by  on 2024/9/24.
//

#include "Error.h"

void Error::error(char type, int line) {
    error_list.emplace_back(type, line);
}
