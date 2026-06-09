#include "include/Error.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "include/Lexer.h"
#include "Parser.h"

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
    vector<int> lines;
    while (lexer.next()) {
        if (!lexer.getToken().empty()) {
            ans.emplace_back(lexer.getLexType(), lexer.getToken());
            lines.emplace_back(lexer.getLine());
//            cout << lexer.getLexType() << " " << lexer.getToken() << lexer.getLine() << endl;
        }
    }
    Parser &parser = Parser::getInstance(ans, lines);
//    parser.outWords();
    ofstream output;
//    output.open("./lexer.txt");
//    if (output.is_open()) {
//        for (const auto &i: ans) {
//            output << i.first << " " << i.second << endl;
//        }
//        output.close();  // 关闭文件
//    } else {
//        cout << "Failed to open file." << endl;
//    }
    output.open("./error.txt");
    if (output.is_open()) {
        const auto &errors = Error::getInstance().getErrors();
        vector<std::pair<char, int>> tmp_errors(errors.begin(), errors.end());
        // 按照 i.second 排序
        sort(tmp_errors.begin(), tmp_errors.end(),
             [](const std::pair<char, int> &a, const std::pair<char, int> &b) {
                 return a.second < b.second;
             });
        for (const auto &i: tmp_errors) {
            output << i.second << ' ' << i.first << endl;
        }
        output.close();  // 关闭文件
    } else {
        cout << "Failed to open error file." << endl;
    }
    output.close();
    return 0;
}