#include "LexicalAnalyzer/CLexicalAnalyzer.h"
#include <iostream>

using namespace std;

int main() {
    CLexicalAnalyzer lexicalAnalyzer;
    extern map<string, enum _TOKEN_TYPE> sg_cReservedMap;
    extern char const* g_strTokenCategoryCode[];
    FILE *lexer = fopen("lexer.txt", "w");
    FILE *error = fopen("error.txt", "w");
    string *token;

    while (true) {
        try {
            if ((token = (string *)lexicalAnalyzer.NextToken()) == nullptr) {
                break;
            }
            fprintf(lexer, "%s %s\n",
                    g_strTokenCategoryCode[lexicalAnalyzer.GetTokenType()], token->c_str());
            delete token;
        } catch (LexicalError& e) {
            token = e.GetLexme();
            fprintf(lexer, "%s %s\n",
                    g_strTokenCategoryCode[lexicalAnalyzer.GetTokenType()], token->c_str());
            fprintf(error, "%d a\n", e.GetLine());
            delete token;
            continue;
        }
    }
}
