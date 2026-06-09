package frontend.lexer;

import java.io.*;
import java.util.ArrayList;

public class Lexer {
    private PushbackReader reader;
    private int currentChar; // 当前字符
    private int lineNumber; // 行号计数器
    private int charPosition; // 每行字符位置计数器

    public Lexer() {
        this.currentChar = -1; // 初始化为-1，如果有退回的字符会存在currentChar中
        this.lineNumber = 1; // 从第一行开始
        this.charPosition = 0; // 当前行的字符位置
    }

    public ArrayList<Token> parse() throws IOException {
        int flag = 1; // 若词法解析未出错为1，否则为0
        ArrayList<Integer> errorLineList = new ArrayList<>();
        ArrayList<Token> tokenList = new ArrayList<>();
        int canBreak = 0; // 若能结束为1，否则为0
        reader = new PushbackReader(new FileReader("testfile.txt"));
        // 读取第一个字符并进入循环
        while (true) {
            Token token = null;
            int ch = getChar();
            if (ch == -1) break; // 到达文件末尾
            if ((char)ch == '_' || ((char)ch >= 'a' && (char)ch <= 'z') || ((char)ch >= 'A' && (char)ch <= 'Z')) {
                // 该Token的第一个字符为下划线或大小写字母，说明为标识符或保留字
                StringBuilder sb = new StringBuilder();
                sb.append((char)ch);
                ch = getChar();
                while ((char)ch == '_' || ((char)ch >= 'a' && (char)ch <= 'z') || ((char)ch >= 'A' && (char)ch <= 'Z') || ((char)ch >= '0' && (char)ch <= '9')) {
                    sb.append((char)ch);
                    ch = getChar();
                }
                pushBackChar(ch);
                // 标识符或保留字
                token = isReserve(sb.toString());
                tokenList.add(token);
            } else if ((char)ch >= '0' && (char)ch <= '9') {
                StringBuilder sb = new StringBuilder();
                sb.append((char)ch);
                ch = getChar();
                while ((char)ch >= '0' && (char)ch <= '9') {
                    sb.append((char)ch);
                    ch = getChar();
                }
                pushBackChar(ch);
                // 数字
                token = new Token(Token.TokenType.INTCON, sb.toString(), lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '"') {
                StringBuilder sb = new StringBuilder();
                sb.append((char)ch);
                ch = getChar();
                while (ch != '"') {
                    sb.append((char)ch);
                    ch = getChar();
                }
                sb.append((char)ch);
                // 字符串常量
                token = new Token(Token.TokenType.STRCON, sb.toString(), lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '\'') {
                StringBuilder sb = new StringBuilder();
                sb.append((char)ch);
                ch = getChar();
                while (ch != '\'') {
                    // '\''为特殊情况，但其实就是'
                    if (ch == '\\') {
                        sb.append((char)ch);
                        ch = getChar();
                        sb.append((char)ch);
                    } else {
                        sb.append((char)ch);
                    }
                    ch = getChar();
                }
                sb.append((char)ch);
                // 字符常量
                token = new Token(Token.TokenType.CHRCON, sb.toString(), lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '&') {
                ch = getChar();
                if ((char)ch == '&') {
                    // &&
                    token = new Token(Token.TokenType.AND, "&&", lineNumber);
                    tokenList.add(token);
                } else {
                    // &错误处理
                    flag = 0;
                    errorLineList.add(lineNumber);
                }
            } else if ((char)ch == '|') {
                ch = getChar();
                if ((char)ch == '|') {
                    // ||
                    token = new Token(Token.TokenType.OR, "||", lineNumber);
                    tokenList.add(token);
                } else {
                    // |错误处理
                    flag = 0;
                    errorLineList.add(lineNumber);
                }
            } else if ((char)ch == '<') {
                ch = getChar();
                if ((char)ch == '=') {
                    // <=
                    token = new Token(Token.TokenType.LEQ, "<=", lineNumber);
                    tokenList.add(token);
                } else {
                    // <
                    token = new Token(Token.TokenType.LSS, "<", lineNumber);
                    tokenList.add(token);
                    pushBackChar(ch);
                }
            } else if ((char)ch == '>') {
                ch = getChar();
                if ((char)ch == '=') {
                    // >=
                    token = new Token(Token.TokenType.GEQ, ">=", lineNumber);
                    tokenList.add(token);
                } else {
                    // >
                    token = new Token(Token.TokenType.GRE, ">", lineNumber);
                    tokenList.add(token);
                    pushBackChar(ch);
                }
            } else if ((char)ch == '=') {
                ch = getChar();
                if ((char)ch == '=') {
                    // ==
                    token = new Token(Token.TokenType.EQL, "==", lineNumber);
                    tokenList.add(token);
                } else {
                    // =
                    token = new Token(Token.TokenType.ASSIGN, "=", lineNumber);
                    tokenList.add(token);
                    pushBackChar(ch);
                }
            } else if ((char)ch == '!') {
                ch = getChar();
                if ((char)ch == '=') {
                    // !=
                    token = new Token(Token.TokenType.NEQ, "!=", lineNumber);
                    tokenList.add(token);
                } else {
                    // !
                    token = new Token(Token.TokenType.NOT, "!", lineNumber);
                    tokenList.add(token);
                    pushBackChar(ch);
                }
            } else if ((char)ch == '/') {
                ch = getChar();
                if ((char)ch == '/') {
                    // 单行注释 //
                    ch = getChar();
                    while (ch != '\n') {
                        ch = getChar();
                        if (ch == -1) {
                            canBreak = 1;
                            break;
                        }
                    }
                } else if ((char)ch == '*') {
                    // /*
                    ch = getChar();
                    while (true) {
                        if ((char)ch == '*') {
                            ch = getChar();
                            if ((char)ch == '/') {
                                break;
                            }
                        }
                        ch = getChar();
                    }
                } else {
                    // /
                    token = new Token(Token.TokenType.DIV, "/", lineNumber);
                    tokenList.add(token);
                    pushBackChar(ch);
                }
            } else if ((char)ch == '+') {
                token = new Token(Token.TokenType.PLUS, "+", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '-') {
                token = new Token(Token.TokenType.MINU, "-", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '*') {
                token = new Token(Token.TokenType.MULT, "*", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '%') {
                token = new Token(Token.TokenType.MOD, "%", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == ';') {
                token = new Token(Token.TokenType.SEMICN, ";", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == ',') {
                token = new Token(Token.TokenType.COMMA, ",", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '(') {
                token = new Token(Token.TokenType.LPARENT, "(", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == ')') {
                token = new Token(Token.TokenType.RPARENT, ")", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '[') {
                token = new Token(Token.TokenType.LBRACK, "[", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == ']') {
                token = new Token(Token.TokenType.RBRACK, "]", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '{') {
                token = new Token(Token.TokenType.LBRACE, "{", lineNumber);
                tokenList.add(token);
            } else if ((char)ch == '}') {
                token = new Token(Token.TokenType.RBRACE, "}", lineNumber);
                tokenList.add(token);
            }
            if (canBreak == 1) {
                break;
            }
//            if (token != null) {
//                System.out.println("-------");
//                System.out.println(token.getType().toString() + ' ' + token.getValue() + ' ' + token.getLineNumber());
//            }
        }
        print2file(flag, tokenList, errorLineList);
        // print2console(flag, tokenList, errorLineList);
        return tokenList;
    }

    private void print2console(int flag, ArrayList<Token> tokenList, ArrayList<Integer> errorLineList) {
        if (flag == 1) {
            for (Token token : tokenList) {
                System.out.println(token.getType().toString() + ' ' + token.getValue());
            }
        } else {
            for (int ln : errorLineList) {
                System.out.println(ln + " a");
            }
        }
    }

    private void print2file(int flag, ArrayList<Token> tokenList, ArrayList<Integer> errorLineList) {
        if (flag == 1) {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt"))) {
                for (Token token : tokenList) {
                    writer.write(token.getType() + " " + token.getValue());
                    writer.newLine(); // 写入换行符
                }
            } catch (IOException e) {
                System.err.println("写入文件时发生错误: " + e.getMessage());
            }
        } else {
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"))) {
                for (int ln : errorLineList) {
                    writer.write(ln + " a");
                    writer.newLine(); // 写入换行符
                }
            } catch (IOException e) {
                System.err.println("写入文件时发生错误: " + e.getMessage());
            }
        }
    }

    private Token isReserve(String sb) {
        Token token;
        switch (sb) {
            case "main":
                token = new Token(Token.TokenType.MAINTK, sb, lineNumber);
                break;
            case "const":
                token = new Token(Token.TokenType.CONSTTK, sb, lineNumber);
                break;
            case "int":
                token = new Token(Token.TokenType.INTTK, sb, lineNumber);
                break;
            case "char":
                token = new Token(Token.TokenType.CHARTK, sb, lineNumber);
                break;
            case "break":
                token = new Token(Token.TokenType.BREAKTK, sb, lineNumber);
                break;
            case "continue":
                token = new Token(Token.TokenType.CONTINUETK, sb, lineNumber);
                break;
            case "if":
                token = new Token(Token.TokenType.IFTK, sb, lineNumber);
                break;
            case "else":
                token = new Token(Token.TokenType.ELSETK, sb, lineNumber);
                break;
            case "for":
                token = new Token(Token.TokenType.FORTK, sb, lineNumber);
                break;
            case "getint":
                token = new Token(Token.TokenType.GETINTTK, sb, lineNumber);
                break;
            case "getchar":
                token = new Token(Token.TokenType.GETCHARTK, sb, lineNumber);
                break;
            case "printf":
                token = new Token(Token.TokenType.PRINTFTK, sb, lineNumber);
                break;
            case "return":
                token = new Token(Token.TokenType.RETURNTK, sb, lineNumber);
                break;
            case "void":
                token = new Token(Token.TokenType.VOIDTK, sb, lineNumber);
                break;
            default:
                token = new Token(Token.TokenType.IDENFR, sb, lineNumber);
                break;
        }
        return token;
    }

    // 从字符流中读入一个
    private int getChar() throws IOException {
        // 检查当前字符是否有效，如果无效则读取新字符
        if (currentChar != -1) {
            int temp = currentChar; // 保存当前字符
            currentChar = -1; // 重置当前字符
            return temp; // 返回之前保存的字符
        }

        // 读取下一个字符并更新行号和字符位置
        int c = reader.read();
        // System.out.println(c+" "+(char)c);
        updatePosition(c);

        return c; // 返回读取的字符
    }

    // 从字符流中退回一个
    public void pushBackChar(int c) throws IOException {
        if (c != -1) {
            if (c == '\n') {
                lineNumber--; // 退回换行符，减少行号
            } else {
                charPosition--; // 退回字符位置
            }
            currentChar = c; // 保存当前字符以供下次读取
        }
    }

    private void updatePosition(int c) {
        if (c == '\n') { // 如果读取到换行符
            lineNumber++; // 增加行号
            charPosition = 0; // 重置字符位置
        } else if (c != -1) {
            charPosition++; // 增加字符位置
        }
    }
}
