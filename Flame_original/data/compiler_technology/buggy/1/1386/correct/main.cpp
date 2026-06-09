#include "tools.h"
#include "Parser.h"
#include <fstream>
int main() {
    Lexer lexer("testfile.txt","parser.txt","error.txt");
    Parser parser(&lexer);
    parser.parseNode();
//    int r;
//    while(1){
//        r = lexer.getToken();
//        if(r == EOF)    break;
//    }
    lexer.closeStream();
    return 0;
}
