#include "include/Error.h"
#include <iostream>
#include <vector>
#include <utility>
#include "include/Lexer.h"

using namespace std;

int main() {
    string content;
    string line;
    ifstream file;
    file.open("./testfile.txt");
    while (getline(file, line)) {
        content += line + '\n';
    }
    content += EOF;
    file.close();
    Lexer &lexer = Lexer::getInstance(content);
    vector<pair<string, string>> ans;
    while (lexer.next()) {
        if (!lexer.getToken().empty())
            ans.emplace_back(lexer.getLexType(), lexer.getToken());
    }
    ofstream output;
    output.open("./lexer.txt");
    if (output.is_open()) {
        for (const auto &i: ans) {
            output << i.first << " " << i.second << endl;
        }
        output.close();  // 关闭文件
    } else {
        cout << "Failed to open file." << endl;
    }
    output.open("./error.txt");
    if (output.is_open()) {
        const auto &errors = Error::getInstance().getErrors();
        for (const auto &i: errors) {
            output << i.second << ' ' << i.first << endl;
        }
        output.close();  // 关闭文件
    } else {
        cout << "Failed to open error file." << endl;
    }
    output.close();
    return 0;
}