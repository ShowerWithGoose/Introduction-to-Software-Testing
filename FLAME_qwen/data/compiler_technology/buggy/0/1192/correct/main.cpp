#include <cstdlib>
#include "source_program.h"
#include "lexer_func.h"

int main() {
    getSourceCode("testfile.txt");
    int ret_val = initLexer(source_code, source_code_size);
    if (ret_val == 0) {
        outputLexer();
    } else {
        errorLexer();
    }
    return 0;
}
