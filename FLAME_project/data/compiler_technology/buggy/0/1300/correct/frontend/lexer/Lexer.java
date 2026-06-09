package frontend.lexer;

import error.Error;
import error.ErrorList;
import error.ErrorType;

import java.io.*;
import java.util.List;

public class Lexer {
    private PushbackInputStream input;
    private char current;
    private int lineNum = 1;
    private TokenList tokenList = new TokenList();
    private ErrorList errorList = new ErrorList();

    public Lexer(PushbackInputStream input) {
        this.input = input;
    }

    // 读一个字符
    private void read() throws IOException {
        current = (char) input.read();
    }

    // 回退一个字符
    private void unread() throws IOException {
        input.unread(current);
    }

    private Token getNextToken() throws IOException {
        read();
        // 跳过空格
        while (isBlank(current))
            read();
        // 使用可变StringBuilder
        StringBuilder s = new StringBuilder();
        // 处理标识符 & 保留字 Ident
        if (isLetter(current) || current == '_') {
            s.append(current);
            read();
            while (isLetter(current) || current == '_' || isDigit(current)) {
                s.append(current);
                read();
            }
            unread(); // 进行回退
            TokenType type = decideTokenType(s.toString());
            return new Token(s.toString(), type, lineNum);
        }
        // 处理数字常量 IntConst
        else if (isDigit(current)) {
            s.append(current);
//            System.out.println("s:"+s);
            read();
            while (isDigit(current)) {
                s.append(current);
                read();
            }
            unread();
//            System.out.println(s);
            return new Token(s.toString(), TokenType.INTCON, lineNum);
        }
        // 处理字符串常量 StringConst
        else if (current == '\"') {
            s.append(current);
            read();
            while (current != '\"') {
                s.append(current);
                read();
            }
            s.append(current);
            return new Token(s.toString(), TokenType.STRCON, lineNum);
        }

        // 处理字符常量 CharConst
        else if (current == '\'') {
            s.append(current);
            read();
            if (current == '\\') {
                s.append(current);
                read();
            }
            s.append(current);
            read();
            s.append(current);
            return new Token(s.toString(), TokenType.CHRCON, lineNum);
        }
        // 处理注释 and /
        else if (current == '/') {
            read();
            // 单行注释
            if (current == '/') {
                read();
                while (current != '\n') {
                    if (current == '\uFFFF') {
                        return new Token("\uFFFF", TokenType.EOF, lineNum);
                    } else
                        read();
                }
                lineNum++;
                return getNextToken();
            }
            // 多行注释
            else if (current == '*') {
                read();
                if (current == '\n')
                    lineNum++;
                while (true) {
                    read();
                    if (current == '\uFFFF') {
                        return new Token("\uFFFF", TokenType.EOF, lineNum);
                    } else if (current == '*') {
                        read();
                        if (current == '/') {
                            break;
                        } else
                            unread();
                    } else if (current == '\n')
                        lineNum++;
                }
                return getNextToken();
            } else {
                unread();
                return new Token("/", TokenType.DIV, lineNum);
            }
        }
        // 处理 ! and !=
        else if (current == '!') {
            read();
            if (current == '=')
                return new Token("!=", TokenType.NEQ, lineNum);
            else {
                unread();
                return new Token("!", TokenType.NOT, lineNum);
            }
        }
        // == and =
        else if (current == '=') {
            read();
            if (current == '=')
                return new Token("==", TokenType.EQL, lineNum);
            else {
                unread();
                return new Token("=", TokenType.ASSIGN, lineNum);
            }
        }
        // < and <=
        else if (current == '<') {
            read();
            if (current == '=')
                return new Token("<=", TokenType.LEQ, lineNum);
            else {
                unread();
                return new Token("<", TokenType.LSS, lineNum);
            }
        }
        // > and >=
        else if (current == '>') {
            read();
            if (current == '=')
                return new Token(">=", TokenType.GEQ, lineNum);
            else {
                unread();
                return new Token(">", TokenType.GRE, lineNum);
            }
        }
        // && error:&
        else if (current == '&') {
            read();
            if (current == '&')
                return new Token("&&", TokenType.AND, lineNum);
            else {
                unread();
                // error
                errorList.addError(new Error(ErrorType.a, lineNum));
                return new Token("&", TokenType.AND, lineNum);
            }
        }
        // || error:|
        else if (current == '|') {
            read();
            if (current == '|')
                return new Token("||", TokenType.OR, lineNum);
            else {
                unread();
                // error
                errorList.addError(new Error(ErrorType.a, lineNum));
                return new Token("|", TokenType.OR, lineNum);
            }
        }
        // + - * % ; , ( ) [ ] { }
        else if (current == '+')
            return new Token("+", TokenType.PLUS, lineNum);
        else if (current == '-')
            return new Token("-", TokenType.MINU, lineNum);
        else if (current == '*')
            return new Token("*", TokenType.MULT, lineNum);
        else if (current == '%')
            return new Token("%", TokenType.MOD, lineNum);
        else if (current == ';')
            return new Token(";", TokenType.SEMICN, lineNum);
        else if (current == ',')
            return new Token(",", TokenType.COMMA, lineNum);
        else if (current == '(')
            return new Token("(", TokenType.LPARENT, lineNum);
        else if (current == ')')
            return new Token(")", TokenType.RPARENT, lineNum);
        else if (current == '[')
            return new Token("[", TokenType.LBRACK, lineNum);
        else if (current == ']')
            return new Token("]", TokenType.RBRACK, lineNum);
        else if (current == '{')
            return new Token("{", TokenType.LBRACE, lineNum);
        else if (current == '}')
            return new Token("}", TokenType.RBRACE, lineNum);
            // \n and \r
        else if (current == '\n') {
            lineNum++;
            return getNextToken();
        } else if (current == '\r') {
            return getNextToken();
        }
        // EOF
        else if (current == '\uFFFF')
            return new Token("\uFFFF", TokenType.EOF, lineNum);
        else {
            throw new RuntimeException("uncorrect token");
        }
    }

    // 封装多情况判别函数
    private boolean isBlank(char c) {
        return c == ' ' || c == '\t';
    }

    public boolean isDigit(char c) {
        return c >= '0' && c <= '9';
    }

    public boolean isLetter(char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    // 读source file, 进行词法分析
    public void scanFile() throws IOException {
        Token token = getNextToken();
        while (token.getType() != TokenType.EOF) {
            System.out.println(token);
            tokenList.addToken(token);
            token = getNextToken();
        }
    }

    // 判定字符串的类别码
    private TokenType decideTokenType(String s) {
        return switch (s) {
            case "main" -> TokenType.MAINTK;
            case "const" -> TokenType.CONSTTK;
            case "int" -> TokenType.INTTK;
            case "char" -> TokenType.CHARTK;
            case "break" -> TokenType.BREAKTK;
            case "continue" -> TokenType.CONTINUETK;
            case "if" -> TokenType.IFTK;
            case "else" -> TokenType.ELSETK;
            case "for" -> TokenType.FORTK;
            case "getint" -> TokenType.GETINTTK;
            case "getchar" -> TokenType.GETCHARTK;
            case "printf" -> TokenType.PRINTFTK;
            case "return" -> TokenType.RETURNTK;
            case "void" -> TokenType.VOIDTK;
            default -> TokenType.IDENFR;
        };

    }

    // print all tokens and errors
    public void printMessage() {
        System.out.println(errorList.size());
//        String baseDir = new File(System.getProperty("user.dir")).getParent();
//        String lexerFilePath = baseDir + File.separator + "/compiler/src/main/java/lexer.txt";
//        String errorFilePath = baseDir + File.separator + "/compiler/src/main/java/error.txt";
        String lexerFilePath = "lexer.txt";
        String errorFilePath = "error.txt";
        if (errorList.isEmpty()) {
            // 输出到 lexer.txt 文件
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(lexerFilePath))) {
                for (Token token : tokenList.getTokens()) {
                    writer.write(token.toString());
                    System.out.println(token.toString()); // 控制台输出
                }
                System.out.println("Tokens output written to " + lexerFilePath);
            } catch (IOException e) {
                System.err.println("Error writing to lexer.txt");
                e.printStackTrace();
            }
        } else {
            // 输出到 error.txt 文件
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorFilePath))) {
                for (Error error : errorList.getErrors()) {
                    writer.write(error.toString());
                    System.out.println(error.toString()); // 控制台输出
                }
                System.out.println("Errors output written to " + errorFilePath);
            } catch (IOException e) {
                System.err.println("Error writing to error.txt");
                e.printStackTrace();
            }
        }
    }


}
