#include "LA.h"
#include "GA.h"
#include "ParserTree.h"
std::ofstream fileout;
std::ofstream errorout;
std::ifstream inputFile;
Token now, preRead, prePreRead, pre4Read;
int nowIndex;
std::vector<Token> tokens;
std::vector<Error> errorList;
int main() {
    Lexer lexer;
    fileout.open("parser.txt");
    errorout.open("error.txt");
    inputFile.open("testfile.txt");
    std::stringstream buffer;
    if (inputFile.is_open()) {
        buffer << inputFile.rdbuf();
        //fileout << "read success" << endl;
        lexer.LexicalAnalysis(buffer.str());
        inputFile.close();
    }

    nowIndex = 0;
    parserTreeRoot = CompUnit_Analysis();
	SortErrors();
	for (int i = 0; i < errorList.size(); i++) {
		errorout << errorList[i].lineNum << " " << errorList[i].errortype << endl;
	}
	PrintParserTree(parserTreeRoot);
    fileout.close();
    errorout.close();
    buffer.clear();

}