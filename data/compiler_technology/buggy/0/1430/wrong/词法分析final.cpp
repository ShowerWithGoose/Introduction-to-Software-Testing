#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <fstream>

// 词法单元结构
struct Token {
    std::string type;
    std::string value;
};

// 关键字与其对应的类型映射
std::map<std::string, std::string> keywords = {
    {"const", "CONSTTK"},
    {"int", "INTTK"},
    {"main", "MAINTK"},
    {"char", "CHARTK"},
    {"break", "BREAKTK"},
    {"continue", "CONTINUETK"},
    {"if", "IFTK"},
    {"else", "ELSETK"},
    {"for", "FORTK"},
    {"return", "RETURNTK"},
    {"printf", "PRINTFTK"},
    {"getint", "GETINTTK"},
    {"getchar", "GETCHARTK"},
    {"void", "VOIDTK"}
};

// 运算符与其对应的类型映射
std::map<std::string, std::string> operators = {
    {"<=", "LEQ"},    // <=
    {">=", "GEQ"},    // >=
    {"==", "EQL"},    // ==
    {"!=", "NEQ"},    // !=
    {"<", "LSS"},     // <
    {">", "GRE"},     // >
    {"=", "ASSIGN"},  // =
    {"+", "PLUS"},    // +
    {"-", "MINU"},    // -
    {"*", "MULT"},    // *
    {"/", "DIV"},     // /
    {"%", "MOD"},     // %
    {"!", "NOT"},     // !
    {",", "COMMA"},   // ,
    {";", "SEMICN"},  // ;
    {"(", "LPARENT"}, // (
    {")", "RPARENT"}, // )
    {"[", "LBRACK"},  // [
    {"]", "RBRACK"},  // ]
    {"{", "LBRACE"},  // {
    {"}", "RBRACE"},  // }
    {"&&", "AND"},    // &&
    {"||", "OR"}      // ||
};

void preprocessFile(const std::string &inputFileName, const std::string &outputFileName) {
    std::ifstream inputFile(inputFileName);
    if (!inputFile) {
        std::cerr << "无法打开文件 " << inputFileName << std::endl;
        return;
    }

    std::ofstream outputFile(outputFileName);
    if (!outputFile) {
        std::cerr << "无法创建文件 " << outputFileName << std::endl;
        return;
    }

    std::string line;
    bool insideBlockComment = false; // 标记是否在多行注释中

    while (std::getline(inputFile, line)) {
        std::string processedLine;
        size_t i = 0;

        while (i < line.size()) {
            // 检查是否在多行注释中
            if (insideBlockComment) {
                size_t endBlockPos = line.find("*/", i);
                if (endBlockPos != std::string::npos) {
                    // 找到了多行注释的结束符，跳过它
                    insideBlockComment = false;
                    i = endBlockPos + 2;
                } else {
                    // 整行都在多行注释内，跳过
                    break;
                }
            }
            // 检查单行注释 //
            else if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '/') {
                // 找到单行注释，忽略后面的内容
                break;
            }
            // 检查多行注释 /*
            else if (line[i] == '/' && i + 1 < line.size() && line[i + 1] == '*') {
                // 进入多行注释模式
                insideBlockComment = true;
                i += 2;
            }
            else {
                // 非注释部分，保留字符
                processedLine += line[i];
                i++;
            }
        }

        // 如果处理后这一行有内容，将其写入输出文件
        if (!processedLine.empty() && !insideBlockComment) {
            outputFile << processedLine << std::endl;
        }
    }

    // 关闭文件
    inputFile.close();
    outputFile.close();
}

// 错误检查：解析 LAndExp 和 LOrExp
bool checkLogicalExpressions(const std::string &code, std::ofstream &errorFile) {
	std::vector<Token> tokens;
    int i = 0, line = 1;
    while (i < code.size()) {
    	if (std::isspace(code[i])) {
		            // 跳过空白字符
		            if (code[i] == '\n') {
						line++;
					}
		            i++;
		            continue;
		        } else if (std::isalpha(code[i]) || code[i] == '_') { while (i < code.size() && (std::isalnum(code[i]) || code[i] == '_')) i++;
		        } else if (std::isdigit(code[i])) { while (i < code.size() && std::isdigit(code[i])) i++;
		        } else if (code[i] == '"') { while (i < code.size() && code[i] != '"') i++; i++;
		        } else if (code[i] == '\'') {
		        	while (i < code.size() && code[i] != '\'') i++; i++;
		        } else {
		        	if (i + 1 < code.size()) {
					    std::string twoCharOp = code.substr(i, 2);
					    if (operators.count(twoCharOp)) {
					        i += 2;
					        continue;
					    }
					}
		            if (code[i]=='&') {
		            	if (i + 1 >= code.size() || code[i + 1] != '&') {
							errorFile << line << " a" << std::endl;
						    return false;
						} else { i+=2; }
		            }
		            else if (code[i]=='|') {
						if (i + 1 >= code.size() || code[i + 1] != '|') {
							errorFile << line << " a" << std::endl;
							return false;
						} else { i+=2; }
					}
					else { i++; }
		        }
    }
    // 没有发现单个 & 或 |，返回 true
    return true;
}


// 词法分析函数
std::vector<Token> lexer(const std::string &code) {
    std::vector<Token> tokens;
    int i = 0;
    while (i < code.size()) {
        if (std::isspace(code[i])) {
            // 跳过空白字符
            i++;
            continue;
        } else if (std::isalpha(code[i]) || code[i] == '_') {
            // 识别标识符或关键字
            int start = i;
            while (i < code.size() && (std::isalnum(code[i]) || code[i] == '_')) i++;
            std::string word = code.substr(start, i - start);
            if (keywords.count(word)) {
                tokens.push_back({keywords[word], word});
            } else {
                tokens.push_back({"IDENFR", word});
            }
        } else if (std::isdigit(code[i])) {
            // 识别整数常量
            int start = i;
            while (i < code.size() && std::isdigit(code[i])) i++;
            tokens.push_back({"INTCON", code.substr(start, i - start)});
        } else if (code[i] == '"') {
            // 识别字符串常量
            int start = i++;
            while (i < code.size() && code[i] != '"') i++;
            i++; // 跳过最后一个引号
            tokens.push_back({"STRCON", code.substr(start, i - start)});
        }else if (code[i] == '\'') {
		     if (i + 3 < code.size() && code[i + 3] == '\'') { 
			// 情况 2: 间隔 2 个字符，可能是转义字符
				if (code[i+1] == '\\') {
				char nextChar = code[i + 2];
				std::string validEscapeChars = "abtnvf\"\'\\0";
				if (validEscapeChars.find(nextChar) != std::string::npos) {
					// 合法的转义字符
					tokens.push_back({"CHRCON", code.substr(i, 4)});
				} else {
					        std::cerr << "非法转义字符: \\" << nextChar << std::endl;
					    }
				} else {
					    	std::cerr << "字符常量格式错误，期待转义字符" << std::endl;
					    }
				i += 4; // 跳过字符和结束的单引号
			} else if (i + 2 < code.size() && code[i + 2] == '\'') { 
			// 情况 3: 间隔 1 个字符，检查是否是 ASCII 码 32-126 的可打印字符
	        char charConst = code[i+1];
	        if (charConst >= 32 && charConst <= 126) {
			    tokens.push_back({"CHRCON", code.substr(i, 3)});
            } else {
	            std::cerr << "非法字符常量: " << charConst << std::endl;
            }
	            i += 3; // 跳过字符和结束的单引号
	        } else {
	            std::cerr << "字符常量格式错误" << std::endl;
	            i += 3; // 跳过错误的单引号
	        }
		}
		else {
            // 检查多字符运算符
            if (i + 1 < code.size()) {
                std::string twoCharOp = code.substr(i, 2);
                if (operators.count(twoCharOp)) {
                    tokens.push_back({operators[twoCharOp], twoCharOp});
                    i += 2;
                    continue;
                }
            }
            // 处理单字符运算符
            std::string oneCharOp = std::string(1, code[i]);
            if (operators.count(oneCharOp)) {
                tokens.push_back({operators[oneCharOp], oneCharOp});
                i++;
            } else {
                std::cerr << "未知符号: " << code[i] << std::endl;
                i++;
            }
        }
    }
    return tokens;
}

int main() {
    // 打开输入文件
    preprocessFile("testfile.txt", "testfile-1.txt");
    std::ifstream inputFile("testfile-1.txt");
    if (!inputFile) {
        return 1;
    }

    // 读取文件内容到一个字符串中
    std::string code((std::istreambuf_iterator<char>(inputFile)),
                     std::istreambuf_iterator<char>());
    inputFile.close();

    // 打开错误文件 error.txt，用于记录错误信息
    std::ofstream errorFile("error.txt");
    if (!errorFile) {
        return 1;
    }

    // 初始化行号变量
    int line = 1;

    // 调用逻辑表达式检查函数
    if (!checkLogicalExpressions(code, errorFile)) {
        // 如果发现错误，关闭错误文件并终止程序
        errorFile.close();
        return 1;
    }

    // 关闭错误文件（如果没有错误，会保持为空）
    errorFile.close();

    // 如果没有发现错误，则继续进行词法分析
    std::vector<Token> tokens = lexer(code);

    // 打开输出文件 lexer.txt，用于保存词法分析结果
    std::ofstream outputFile("lexer.txt");
    if (!outputFile) {
        return 1;
    }

    // 输出词法单元到文件
    for (const auto &token : tokens) {
	        outputFile << token.type << " " << token.value << std::endl;
	    }

    // 关闭输出文件
    outputFile.close();

    return 0;
}
