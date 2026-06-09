#include"lexer/Lexer.h"
#include"parser/Parser.h"
#include"util/Util.h"
#include "error/Error.h"
int main() {
    Util::initEnv();
    Lexer::lexicalAnalysis();
    Parser::parse();
    Error::sortError();
    return 0;
}
