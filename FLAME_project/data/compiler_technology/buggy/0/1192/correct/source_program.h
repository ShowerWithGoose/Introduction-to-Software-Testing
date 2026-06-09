//
// Created by  on 2024/10/3.
//

#ifndef COMPILER_SOURCE_PROGRAM_H
#define COMPILER_SOURCE_PROGRAM_H

#include <cstring>
#include <cstdio>
#include "global_settings.h"

static char source_code[global_sourceCodeMaxLength];
static size_t source_code_size;
static char file_name[global_sourceCodeFileNameLength];

void getSourceCode(const char filename[]) {
    strcpy(file_name, filename);
    FILE *file = fopen(file_name, "r");
    source_code_size = fread(source_code, sizeof(char), global_sourceCodeMaxLength, file);
    source_code[source_code_size] = 0;
    fclose(file);
}

void getSourceCode() {
    file_name[0] = 0;
    source_code_size = 0;
    char c = getchar();
    while (c > 0) {
        source_code[source_code_size++] = c;
        c = getchar();
        printf("(%d)", source_code_size);
    }
    source_code[source_code_size] = 0;puts("end");
}

#endif //COMPILER_SOURCE_PROGRAM_H
