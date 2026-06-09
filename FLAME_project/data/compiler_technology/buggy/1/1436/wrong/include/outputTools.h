#ifndef OUTPUTTOOLS_H
#define OUTPUTTOOLS_H
#include "components.h"
#include <vector>
void outputComponent(Component *src, FILE *out);
void outputErrors(std::vector<ErrorBlock> src, FILE *out);
#endif