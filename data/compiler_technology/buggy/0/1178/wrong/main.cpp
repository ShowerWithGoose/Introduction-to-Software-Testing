#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include "LexicalAnalyzer.h"

using namespace std;

int main(int argc, char *argv[]){

    // 打开源程序文件
    string sourceFile = "testfile.txt";
    ifstream fin(sourceFile);
    if (!fin.is_open()) {
        cerr << "Error: cannot open source file: " << sourceFile << endl;
        return 1;
    }

    // 打开输出文件
    ofstream fout("lexer.txt");
    if (!fout.is_open()) {
        cerr << "Error: cannot create output file: lexer.txt" << endl;
        fin.close();
        return 1;
    }

    ofstream errorFile("error.txt");
    if (!errorFile.is_open()) {
        std::cerr << "Failed to open error.txt" << std::endl;
        return 1;
    }

    Lexer& lexer = Lexer::getInstance(fin, fout, errorFile);
    while (lexer.getLexType() != LexType::FINISH) {
          lexer.next();       // 获取下一个单词
//        lexer.getToken();   // 输出当前的 token
        if (lexer.getLexType() != LexType::FINISH) {
            cout << lexer.getLexType1() << ' ' << lexer.getToken() << endl;
            fout << lexer.getLexType1() << ' ' << lexer.getToken() << endl;  // 输出到文件
        }
    }

    // 关闭文件
    fout.close();
    fin.close();
    errorFile.close();

    return 0;
}

