package frontend;

import java.io.*;
import java.util.ArrayList;

public class Lexer {
    BufferedReader reader = new BufferedReader(new FileReader("testfile.txt"));
    FileWriter lw = new FileWriter("lexer.txt");
    FileWriter ew = new FileWriter("error.txt");
    int line = 0;
    String token = "";
    long number;
    String type;
    boolean error = false;
    int reservedCount = 14;
    String[] reserved = {"main", "const", "int", "char", "break", "continue", "if", "else", "for", "getint", "getchar", "printf", "return", "void"};
    static public ArrayList<Sym> symList = new ArrayList<>();
    static public ArrayList<Error> errorList = new ArrayList<>();

    public Lexer() throws IOException {
    }

    int reserve() {
        for (int i = 0; i < reservedCount; i++) {
            if (token.equals(reserved[i])) {
                return i + 1;
            }
        }
        return 0;
    };

    boolean isNonDigit(char c) {
        if(Character.isLetter(c) || c == '_')
            return true;
        else
            return false;
    };

    boolean Issymbol(char c) {
        if(c == '!') {
            return true;
        }
        else if(c == '&') {
            return true;
        }
        else if(c == '|') {
            return true;
        }
        else if(c == '+') {
            token = "+";
            type = "PLUS";
            return true;
        }
        else if(c == '-') {
            token = "-";
            type = "MINU";
            return true;
        }
        else if(c == '*') {
            token = "*";
            type = "MULT";
            return true;
        }
        else if(c == '/') {
            return true;
        }
        else if (c == '%') {
            token = "%";
            type = "MOD";
            return true;
        }
        else if (c == '<') {
            return true;
        }
        else if(c == '>') {
            return true;
        }
        else if(c == '=') {
            return true;
        }
        else if(c == ';') {
            token = ";";
            type = "SEMICN";
            return true;
        }
        else if(c == ',') {
            token = ",";
            type = "COMMA";
            return true;
        }
        else if(c == '(') {
            token = "(";
            type = "LPARENT";
            return true;
        }
        else if(c == ')') {
            token = ")";
            type = "RPARENT";
            return true;
        }
        else if(c == '[') {
            token = "[";
            type = "LBRACK";
            return true;
        }
        else if(c == ']') {
            token = "]";
            type = "RBRACK";
            return true;
        }
        else if(c == '{') {
            token = "{";
            type = "LBRACE";
            return true;
        }
        else if(c == '}') {
            token = "}";
            type = "RBRACE";
            return true;
        }
        return false;
    };

    void print() throws IOException {
        if(!error) {
            Sym sym = new Sym(token, type, line);
            symList.add(sym);
            //lw.write(type + " " + token + "\n");
        }
        else {
            Error error1 = new Error(line, type);
            errorList.add(error1);
            //ew.write(line + " " + type + "\n");
            if(token.equals("&&"))
                type = "AND";
            else
                type = "OR";
            Sym sym = new Sym(token, type, line);
            symList.add(sym);
            error = false;
        }
    };

    public void scanner() throws IOException {

        String string;
        int flag = 0;
        while((string = reader.readLine()) != null) {
            line++;
            int i = 0, strlen = string.length();
            while(i < strlen){
                if(flag == 0){
                    char c = string.charAt(i++);
                    if(isNonDigit(c)) { // 标识符或保留字
                        token += c;
                        while(i < strlen && (isNonDigit(string.charAt(i)) || Character.isDigit(string.charAt(i)))) {
                            // 下一个字符为数字或字母
                            c = string.charAt(i++);
                            token += c;
                        }
                        int reservedCode = reserve(); // 查关键字表
                        if (reservedCode == 0) {
                            type = "IDENFR";
                        } else {
                            switch (reservedCode) {
                                case 1: type = "MAINTK"; break;
                                case 2: type = "CONSTTK"; break;
                                case 3: type = "INTTK"; break;
                                case 4: type = "CHARTK"; break;
                                case 5: type = "BREAKTK"; break;
                                case 6: type = "CONTINUETK"; break;
                                case 7: type = "IFTK"; break;
                                case 8: type = "ELSETK"; break;
                                case 9: type = "FORTK"; break;
                                case 10: type = "GETINTTK"; break;
                                case 11: type = "GETCHARTK"; break;
                                case 12: type = "PRINTFTK"; break;
                                case 13: type = "RETURNTK"; break;
                                case 14: type = "VOIDTK"; break;
                            }
                        }
                        print();
                        token = "";
                    }
                    else if(Character.isDigit(c)) { // 无符号整数
                        token += c;
                        while(i < string.length() && Character.isDigit(string.charAt(i))) {
                            // 下一个符号是数字
                            c = string.charAt(i++);
                            token += c;
                        }
                        type = "INTCON"; // 设置单词类别
                        number = Long.parseLong(token); // 转化为数值
                        print();
                        token = "";
                    }
                    else if(c == '"') { // 字符串常量
                        token += c;
                        while(i < string.length() && string.charAt(i) != '"') {
                            // 下一个符号不是'"'
                            c = string.charAt(i++);
                            token += c;
                        }
                        if(i < string.length())
                            c = string.charAt(i++);
                        token += c;
                        type = "STRCON"; // 设置单词类别
                        print();
                        token = "";
                    }
                    else if(c == '\'') { // 字符常量
                        token += c;
                        while(i < string.length() && string.charAt(i) != '\'') {
                            // 下一个符号不是'''
                            c = string.charAt(i++);
                            if(c == '\\'){
                                token += c;
                                c = string.charAt(i++);
                            }
                            token += c;
                        }
                        if(i < string.length())
                            c = string.charAt(i++);
                        token += c;
                        type = "CHRCON"; // 设置单词类别
                        print();
                        token = "";
                    }
                    else if(Issymbol(c)) { //符号
                        if(c == '!') {
                            if((i < string.length() && string.charAt(i) == '=')) {
                                token = "!=";
                                type = "NEQ";
                                i++;
                            }
                            else {
                                token = "!";
                                type = "NOT";
                            }
                        }
                        else if(c == '&') {
                            if((i < string.length() && string.charAt(i) == '&')) {
                                token = "&&";
                                type = "AND";
                                i++;
                            }
                            else {
                                error = true;
                                token = "&&";
                                type = "a";
                            }
                        }
                        else if(c == '|') {
                            if((i < string.length() && string.charAt(i) == '|')) {
                                token = "||";
                                type = "OR";
                                i++;
                            }
                            else {
                                error = true;
                                token = "||";
                                type = "a";
                            }
                        }
                        else if (c == '<') {
                            if((i < string.length() && string.charAt(i) == '=')) {
                                token = "<=";
                                type = "LEQ";
                                i++;
                            }
                            else {
                                token = "<";
                                type = "LSS";
                            }
                        }
                        else if(c == '>') {
                            if((i < string.length() && string.charAt(i) == '=')) {
                                token = ">=";
                                type = "GEQ";
                                i++;
                            }
                            else {
                                token = ">";
                                type = "GRE";
                            }
                        }
                        else if(c == '=') {
                            if((i < string.length() && string.charAt(i) == '=')) {
                                token = "==";
                                type = "EQL";
                                i++;
                            }
                            else {
                                token = "=";
                                type = "ASSIGN";
                            }
                        }
                        else if(c == '/') { // 第一个 /
                            if((i < string.length() && string.charAt(i) == '/')) {
                                break;
                            }
                            else if((i < string.length() && string.charAt(i) == '*')) {
                                flag = 1;
                                i++;
                                while(i < string.length() && string.charAt(i) != '*') {
                                    // 下一个符号不是'*'
                                    i++;
                                }
                                if(i < string.length()) {
                                    i++;
                                    if(i < string.length() && string.charAt(i) == '/') {
                                        flag = 0;
                                        i++;
                                        token = "";
                                        continue;
                                    }
                                }
                                break;
                            }
                            else {
                                token = "/";
                                type = "DIV";
                            }
                        }
                        print();
                        token = "";
                    }
                }
                else {
                    while(i < string.length() && string.charAt(i) != '*') {
                        // 下一个符号不是'*'
                        i++;
                    }
                    if(i < string.length()) {
                        i++;
                        if(i < string.length() && string.charAt(i) == '/') {
                            flag = 0;
                            i++;
                            token = "";
                            continue;
                        }
                    }
                    break;
                }
            }
        }
        lw.close();
        ew.close();
    }
}
