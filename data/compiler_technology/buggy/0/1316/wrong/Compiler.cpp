// Compiler_Nu_CMake.cpp: 定义应用程序的入口点。
//

#include "Compiler.h"

using namespace std;

int main()
{
    std::ifstream file("testfile.txt");
    Lexer* lexer;
    if (file.is_open()) {
        lexer = new Lexer(file);
        lexer->process_lexer();
        file.close();
    }
    else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }
    if (ErrorCollector::hasError()) {
        std::ofstream err_file("error.txt");
        if (err_file.is_open()) {
            ErrorCollector::put_error(err_file);
            err_file.close();
        }
        else {
            std::cerr << "Unable to open file" << std::endl;
            return 1;
        }
    } else {
        std::ofstream output("lexer.txt");
        if (output.is_open()) {
            lexer->put_tokens(output);
            output.close();
        }
        else {
            std::cerr << "Unable to open file" << std::endl;
            return 1;
        }

    }
	return 0;
}
