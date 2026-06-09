#include <iostream>
#include <fstream>
#include <vector>
#include "lexer.h"
#include "error.h"

using namespace std;
vector<Word> wordList;
vector<Error> errorList;
extern int nowLineNum;
int main() {
    ifstream file;
    file.open("testfile.txt",ios::in | ios::binary);
    if (!file.is_open()) {
        cout<<"open error"<<endl;
        return 0;
    }
    //逐字符读取，暂时不储存，只储存解析出来的词法信息
    //需要注意标识符错误，例如0ab
    //除了“”‘’里面的是以“”‘’为分界线，似乎别的就只用以空格为分界线
    while (!file.eof()) {
        Word temp;//先不用new，看看会不会出现作用域问题
        temp = lexer_getWord(file);
        if (file.eof() && temp.get_str().empty()) break;
        if (temp.get_str().empty()) continue;
        if (temp.isError()) {
            auto temp_error = Error(nowLineNum,'a');
            errorList.push_back(temp_error);
        }
        else {
            wordList.push_back(temp);//解开大括号后，可以让错误word也得到储存
        }
    }
    file.close();
    if (errorList.empty()) {
        ofstream outFile("lexer.txt",ios::out | ios::binary);
        for (int i = 0;i < wordList.size();i++) {
            outFile << wordList[i].get_typeCode()
            << ' ' << wordList[i].get_str() << endl;
        }
    }
    else {
        ofstream outFile("error.txt",ios::out | ios::binary);
        for (int i = 0;i < errorList.size();i++) {
            outFile << errorList[i].get_lineNum() << ' ' << errorList[i].get_type() << endl;
        }
    }
    return 0;
}
