#include <iostream>
#include <unordered_map>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
#include <vector>

using namespace std;

string source;//用于存储源程序字符串
int lineNum = 1;//用于记录当前行号
string token,lexType;//用于存储当前的token和token的类型
int curPos = 0;//用于记录当前解析到source的位置
int num = 0;//用于解析数字
vector<pair<string, string>> identifier;//用于存储已经识别的标识符
int is_error = 0;//用于记录是否有错误

//列举保留字的所有类型以及其对应的类别码
unordered_map<string, string> reserveWords = {
    {"main","MAINTK"},{"const","CONSTTK"},
    {"int","INTTK"},{"char","CHARTK"},
    {"break","BREAKTK"},{"continue","CONTINUETK"},
    {"if","IFTK"},{"else","ELSETK"},
    {"for","FORTK"},{"getint","GETINTTK"},
    {"getchar","GETCHARTK"},{"printf","PRINTFTK"},
    {"return","RETURNTK"},{"void","VOIDTK"},
};

//列举单个标点符号的所有类型以及其对应的类别码
unordered_map<string, string> chars = {
    {"+","PLUS"},
    {"-","MINU"},{"*","MULT"},
    {"%","MOD"},{";","SEMICN"},
    {",","COMMA"},{"(","LPARENT"},
    {")","RPARENT"},{"[","LBRACK"},
    {"]","RBRACK"},{"{","LBRACE"},
    {"}","RBRACE"},
};

/*读取文件到字符串当中*/
string readFileIntoString(const string& filename) {
    ifstream file(filename);
    ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// 词法分析器
int main(){
    //读取文件内容到字符串source中
    string filename = "testfile.txt";
    source = readFileIntoString(filename);

    //分别定义并打开输出正确信息和错误信息的文件
    ofstream correct,error;
    correct.open("lexer.txt");
    error.open("error.txt");

    //开始进行词法分析  
    while(curPos < source.length()){
        //跳过空白字符 
        if(curPos < source.length() && isspace(source.at(curPos))){
            if(source.at(curPos) == '\n'){
                lineNum++;
            }
            curPos++;
        }

        //解析标识符和保留字
        else if(isalpha(source.at(curPos))||source.at(curPos) == '_'){//如果是字母或者下划线开头
            token = "";
            token += source.at(curPos);
            curPos++;

            while(curPos < source.length() && 
            (isalpha(source.at(curPos)) || isdigit(source.at(curPos))||source.at(curPos) == '_')){
                //下一次字符为数字或字母或下划线
                token += source.at(curPos);
                curPos++;
            }

            //判断是否为保留字  
            if(reserveWords.find(token)!= reserveWords.end()){
            //如果是保留字
                lexType = reserveWords.find(token)->second;
            }
            else{
                lexType = "IDENFR";
            }
            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }

        //解析数字
        else if(isdigit(source.at(curPos))){
            //如果是数字
            token = "";
            while(curPos < source.length() && isdigit(source.at(curPos))){
                token += source.at(curPos);
                curPos++;
            }
            lexType = "INTCON";
            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }

        //解析单元符号
        else if(chars.find(source.substr(curPos,1))!= chars.end()){
            //如果是符号
            token = source.substr(curPos,1);
            lexType = chars.find(token)->second;
            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
            curPos++;
        }

        //解析!和!=
        else if(source.substr(curPos,1) == "!"&&curPos < source.length()){
            //如果是!
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是!=
                token += source.at(curPos);
                lexType = "NEQ";
                curPos++;
            }
            else{
                lexType = "NOT";
            }

            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }

        //解析&&
        else if(source.substr(curPos,1) == "&"&&curPos < source.length()){
            //如果是&
            token = "";
            token += source.at(curPos);
            curPos++;
            if(curPos < source.length() && source.at(curPos) == '&'){
                //如果是&&
                token += source.at(curPos);
                lexType = "AND";
                identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
                curPos++;
            }
            else{
                //如果不是&&,则报错
                error << lineNum << " " << "a" << endl;
                is_error = 1;}
        }

        //解析||
        else if(source.substr(curPos,1) == "|"&&curPos < source.length()){
            //如果是|
            token = "";
            token += source.at(curPos);
            curPos++;
            if(curPos < source.length() && source.at(curPos) == '|'){
                //如果是||
                token += source.at(curPos);
                lexType = "OR";
                identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
                curPos++;
            }
            else{
                //如果不是||,则报错
                error << lineNum << " " << "a" << endl;
                is_error = 1;}
        }

        //解析<=和<
        else if(source.substr(curPos,1) == "<"&&curPos < source.length()){
            //如果是<
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是<=
                token += source.at(curPos);
                lexType = "LEQ";
                curPos++;
            }
            else{
                lexType = "LSS";
            }

            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }

        //解析>=和>
        else if(source.substr(curPos,1) == ">"&&curPos < source.length()){
            //如果是>
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是>=
                token += source.at(curPos);
                lexType = "GEQ";
                curPos++;
            }
            else{
                lexType = "GRE";
            }

            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }

        //解析==和=
        else if(source.substr(curPos,1) == "="&&curPos < source.length()){
            //如果是=
            token = "";
            token += source.at(curPos);
            curPos++;

            if(curPos < source.length() && source.at(curPos) == '='){
                //如果是==
                token += source.at(curPos);
                lexType = "EQL";
                curPos++;
            }
            else{
                lexType = "ASSIGN";
            }

            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }


        //解析字符常量
        else if(source.at(curPos) == '\''){
            //如果是字符常量
            token = "";
            token += source.at(curPos);
            curPos++;
            lexType = "CHRCON";

            if(curPos < source.length() && source.at(curPos) == '\\'){
                //如果是转义字符
                token += source.substr(curPos,3);
                curPos+=3;
            }

            else if(curPos < source.length() && source.at(curPos) != '\\'){
                //如果是字符常量
                token += source.substr(curPos,2);
                curPos+=2;
            }
            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }

        //解析字符串常量
        else if(source.at(curPos) == '\"')
        {
            //如果是字符串常量
            token = "";
            token += source.at(curPos);
            curPos++;
            lexType = "STRCON";

            while(curPos < source.length() && source.at(curPos)!= '\"'){
                //如果是字符串常量
                token += source.at(curPos);
                if(source.substr(curPos,2) == "\n"){
                    //如果是换行符
                    lineNum++;
                }
                curPos++;
            }

            if(curPos < source.length() && source.at(curPos) == '\"'){
                //如果是字符串常量
                token += source.at(curPos);
                curPos++;
            }

            identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
        }

        //解析注释
        else if(source.at(curPos)== '/')
        {
            token = "";
            token += source.at(curPos);
            curPos++;
            if(curPos < source.length() && source.at(curPos) == '/')
            {
                curPos++;
                while(curPos < source.length() && source.at(curPos)!= '\n')
                {
                    //如果是//注释
                    curPos++;
                }
                if(curPos < source.length() && source.at(curPos) == '\n')
                {
                    curPos++;

                    //如果是//注释
                    lineNum++;
                }
            }
            else if(curPos < source.length() && source.at(curPos) == '*')
            {
                //如果是/*注释
                token += source.at(curPos);
                curPos++;
                while(curPos < source.length())
                {
                    if(source.at(curPos)=='\n')
                    {
                        //如果是/*注释
                        lineNum++;
                    }
                    if(source.substr(curPos,2) == "*/"&&curPos+1 < source.length())
                    {
                        //如果是/*注释
                        token += source.substr(curPos,2);
                        curPos+=2;
                        break;
                    }
                    else if(curPos+1 < source.length()&&source.substr(curPos,2)!="*/"){
                        //如果是/*注释
                        token += source.at(curPos);
                        curPos++;
                    }
                }

            }
            else
            {
                //如果不是注释
                lexType = "DIV";
                identifier.push_back(make_pair(token,lexType));//将标识符加入到标识符表中
            }
        }
    }

    if(is_error == 0){
        //如果没有错误
        for(int i = 0;i < identifier.size();i++){
            //输出正确信息
            correct << identifier[i].second << " " << identifier[i].first << endl;
        }
    }

    return 0;
}