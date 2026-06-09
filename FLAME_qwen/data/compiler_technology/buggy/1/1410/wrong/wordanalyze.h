//
// Created by  on 2024-10-11.
//

#ifndef COMPILER_WORDANALYZE_H
#define COMPILER_WORDANALYZE_H
#define MAX_TOKEN_LENGTH 100
typedef struct Token{
    int line;
    char type[15];
    char value[MAX_TOKEN_LENGTH];
} Token;
Token *wordanalyze();
int gettokennum();
#endif //COMPILER_WORDANALYZE_H
