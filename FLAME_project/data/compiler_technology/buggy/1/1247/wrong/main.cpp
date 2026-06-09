#include "error.h"
#include "lexer.h"
#include "parser.h"

int main(){
    //remove("error.txt");
    //remove("lexer.txt");
    //remove("parser.txt");
    ast(getWords("testfile.txt"));
    //ast(printWords("lexer.txt"));
    parseWords();
    if(!errors.empty()){
        ast(printErrors("error.txt"));
        return 0;
    }
    ast(printRoot("parser.txt"));
    return 0;
}
