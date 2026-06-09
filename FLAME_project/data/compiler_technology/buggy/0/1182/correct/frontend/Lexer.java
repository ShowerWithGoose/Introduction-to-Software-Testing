package frontend;

import java.util.ArrayList;
import java.util.ArrayList;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.io.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;

public class Lexer {
    private String str;//输入文件
    private String word = "";//当前词
    private int length;//总长度
    private int line;//当前行号
    private ArrayList<Token> tokens;//词法分析结果
    private char c;  // 表示当前位置的字符
    private ArrayList<Integer> errors_token;

    public Lexer() {
        this.word = "";
        this.length = 0;
        this.line = 1;
        this.tokens = new ArrayList<Token>();
        this.errors_token = new ArrayList<Integer>();
    }

    public void run() {
        readfile();
        GetToken();
//        for (Token token : tokens) {
//            System.out.println(token.type + " " + token.value);
//        }
        printTokens();
    }

    private void printTokens() {  // 打印词法分析结果
        if (errors_token.size() != 0) {
            try (BufferedWriter errorWriter = new BufferedWriter(new FileWriter("error.txt", true))){
                for (Integer token : errors_token) {
                    errorWriter.write(token +" a" + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt", true))){
                for (Token token : tokens) {
                    writer.write(token.type + " " + token.value + "\n");
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    private void readfile(){  // 读入文件
        String filePath ="testfile.txt";
        try {
            str = new String(Files.readAllBytes(Paths.get(filePath)));
            this.length = str.length();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void GetToken() {
        for (int i = 0; i < length; i++) {
            c = str.charAt(i);
            if (c == ' ' || c == '\t' || c == '\r') {  // 碰到了空白字符
                check_word();
            } else if (c == '\n') {  // 碰到了换行符
                line++;
                check_word();
            } else if (c == '/') {  // 碰到了 / 符号
                check_word();
                if (i + 1 < str.length() && str.charAt(i + 1) == '/') {  // 碰到了//注释
                    while (i < str.length() && str.charAt(i) != '\n') {
                        i++;
                    }
                    line++;  // 注释所在行号+1
                } else if (i + 1 < str.length() && str.charAt(i + 1) == '*') {  // 碰到了/*注释
                    i++;
                    while (i + 1 < str.length() && !(str.charAt(i) == '*' && str.charAt(i + 1) == '/')) {  // 寻找 */ 与当前 /* 匹配
                        i++;
                        if (str.charAt(i) == '\n')  // /*注释中遇到了换行
                            line++;
                    }
                    i++;
                } else {  // 碰到了除法运算符
                    add_token("DIV", "/", line);
                }
            } else if (c == '\"' || c == '\'') {  // 碰到了字符串
                check_word();
                word += c;
                i++;   // 跳过第一个引号
                while (i < str.length() && !(str.charAt(i) == c && str.charAt(i-1) != '\\')) {  // 寻找字符串结束位置并把字符串中间的都放入word中
                    if (str.charAt(i) == '\n')  // 引号过程中遇到了换行
                        line++;
                    word += str.charAt(i);
                    i++;
                }
                word += c;  // 加上最后的引号
                if (c == '\'') {  // 单引号字符串
                    add_token("CHRCON", word, line);
                } else {  // 双引号字符串
                    add_token("STRCON", word, line);
                }
                word = "";
            } else if (c == '=') {
                check_word();
                if (i + 1 < str.length() && str.charAt(i + 1) == '=') {  // 碰到了 == 运算符
                    add_token("EQL", "==", line);
                    i++;
                } else {  // 碰到了 = 赋值运算符
                    add_token("ASSIGN", "=", line);
                }
            } else if (c == '!') {
                check_word();
                if (i + 1 < str.length() && str.charAt(i + 1) == '=') {  // 碰到了 != 运算符
                    add_token("NEQ", "!=", line);
                    i++;
                } else {  // 碰到了 ! 逻辑非运算符
                    add_token("NOT", "!", line);
                }
            } else if (c == '<') {
                check_word();
                if (i + 1 < str.length() && str.charAt(i + 1) == '=') {  // 碰到了 <= 运算符
                    add_token("LEQ", "<=", line);
                    i++;
                } else {  // 碰到了 < 运算符
                    add_token("LSS", "<", line);
                }
            } else if (c == '>') {
                check_word();
                if (i + 1 < str.length() && str.charAt(i + 1) == '=') {  // 碰到了 >= 运算符
                    add_token("GEQ", ">=", line);
                    i++;
                } else {  // 碰到了 > 运算符
                    add_token("GRE", ">", line);
                }
            } else if (c == '&' || c == '|') {
                check_word();
                if (i + 1 < str.length() && str.charAt(i + 1) == c) {  // 碰到了 && 或 || 逻辑运算符
                    add_token(GetType("" + c + c), "" + c + c, line);
                    i++;
                } else {  // 碰到了 & 或 | 位运算符
                    errors_token.add(line);
                }
            } else if (c >= '0' && c <= '9') {  // 碰到了数字
                if (word.length() == 0) {  // 数字前面没有单词
                    while (i < str.length() && (str.charAt(i) >= '0' && str.charAt(i) <= '9')) {  // 碰到了数字
                        word += str.charAt(i);
                        i++;
                    }
                    tokens.add(new Token("INTCON", word, line));
                    word = "";
                    i--;
                } else {  // 数字是变量的一部分
                    word += c;
                }
            }else if (GetType("" + c) != "IDENFR") {
                // GetType() 返回的指挥使IDENFR类型或者其他标识符，如果不是IDENFR类型则代表前面可能有一个IDENFR类型
                check_word();  // 标识符前面可能有字符串
                if (i + 1 < str.length() && GetType("" + c + str.charAt(i + 1)) != "IDENFR") {
                    // 当前和下一个位置构成了一个两个字符的标识符
                    // 例如 <= 的类型
                    add_token(GetType("" + c + str.charAt(i + 1)), "" + c + str.charAt(i + 1), line);
                } else {
                    add_token(GetType("" + c), "" + c, line);
                }
                word = "";
            } else {
                word += c;
            }
        }
    }

    private void add_token(String type, String value, int line) {  // 放入新的token
        Token token = new Token(type, value, line);
        tokens.add(token);
    }

    private void check_word() {
        if (word.length() != 0) {  // 空白字符前面有单词
            add_token(GetType(word), word, line);
        }
        word = "";
    }

    private String GetType(String word) {
        try {
            TokenType tokenType = TokenType.fromDescription(word);
            if (tokenType!= null){
                return tokenType.name();
            }
            else if(word.length()!=0){
                return "IDENFR";
            }
        } catch (IllegalArgumentException e) {
            return "Type_Error";
        }
        return null;
    }
}
