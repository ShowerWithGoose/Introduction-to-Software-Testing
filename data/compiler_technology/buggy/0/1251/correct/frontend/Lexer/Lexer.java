package frontend.Lexer;

import error.Error;
import frontend.Reader;

import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;

public class Lexer {
    private final Reader reader;
    private final StringBuilder str = new StringBuilder();
    private int lineNum = 1;
    private final ArrayList<Token> tokens = new ArrayList<>();
    private final ArrayList<Error> errors = new ArrayList<>();
    public Lexer(String inputFile) {
        reader = new Reader(inputFile);
    }

    public void parse() {
        while (true) {
            str.setLength(0);
            TokenType tokenType = null;
            int num = 0;
            char c = reader.read();

            // 空白符
            if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
                if (c == '\n') {
                    lineNum++;
                }
                continue;
            }

            // source读到末尾
            if (c == (char) 0) {
                break;
            }

            // 保留字或标识符
            if (Character.isLetter(c) || c == '_') {
                while (Character.isLetterOrDigit(c) || c == '_') {
                    str.append(c);
                    c = reader.read();
                }
                reader.unread();
                tokenType = reserve(str.toString());
                if (tokenType == null) {
                    tokenType = TokenType.IDENFR;
                }
            }

            // 数值常量
            else if (Character.isDigit(c)) {
                tokenType = TokenType.INTCON;
                str.append(c);
                if (c != '0') {
                    while (Character.isDigit(c = reader.read())) {
                        str.append(c);
                    }
                    reader.unread();
                }
                //num = Integer.parseInt(str.toString());
            }

            // 双分界符
            else if (c == '<') {
                str.append(c);
                if ((c = reader.read()) == '=') {
                    str.append(c);
                    tokenType = TokenType.LEQ;
                }
                else {
                    reader.unread();
                    tokenType = TokenType.LSS;
                }
            }
            else if (c == '>') {
                str.append(c);
                if ((c = reader.read()) == '=') {
                    str.append(c);
                    tokenType = TokenType.GEQ;
                }
                else {
                    reader.unread();
                    tokenType = TokenType.GRE;
                }
            }
            else if (c == '=') {
                str.append(c);
                if ((c = reader.read()) == '=') {
                    str.append(c);
                    tokenType = TokenType.EQL;
                }
                else {
                    reader.unread();
                    tokenType = TokenType.ASSIGN;
                }
            }
            else if (c == '!') {
                str.append(c);
                if ((c = reader.read()) == '=') {
                    str.append(c);
                    tokenType = TokenType.NEQ;
                }
                else {
                    reader.unread();
                    tokenType = TokenType.NOT;
                }
            }
            else if (c == '&') {
                str.append(c);
                if ((c = reader.read()) == '&') {
                    str.append(c);
                }
                else {
                    reader.unread();
                    errors.add(new Error('a', lineNum));
                }
                tokenType = TokenType.AND;
            }
            else if (c == '|') {
                str.append(c);
                if ((c = reader.read()) == '|') {
                    str.append(c);
                }
                else {
                    reader.unread();
                    errors.add(new Error('a', lineNum));
                }
                tokenType = TokenType.OR;
            }

            // 关于'/'的处理
            else if (c == '/') {
                str.append(c);
                c = reader.read();
                if (c == '/') {
                    do {
                        c = reader.read();
                    } while (c != '\n' && c != '\0');
                    if (c == '\0') break;
                    lineNum++;
                    continue;
                }
                else if (c == '*') {
                    while (true) {
                        c = reader.read();
                        if (c == '\n') {
                            lineNum++;
                        }
                        else if (c == '*') {
                            if (reader.read() == '/') {
                                break;
                            }
                        }
                    }
                    continue;
                }
                else {
                    reader.unread();
                    tokenType = TokenType.DIV;
                }
            }

            // 关于'\''的处理
            else if (c == '\'') {
                str.append(c);
                c = reader.read();
                str.append(c);
                if (c == '\\') {
                    str.append(reader.read());
                }
                str.append(reader.read());
                tokenType = TokenType.CHRCON;
            }

            // 关于'\"'的处理
            else if (c == '\"') {
                do {
                    str.append(c);
                } while ((c = reader.read()) != '\"');
                str.append(c);
                tokenType = TokenType.STRCON;
            }

            // 其他单分界符
            else {
                str.append(c);
                tokenType = single(str.toString());
            }

            tokens.add(new Token(tokenType, str.toString(), num));
            // System.out.println(lineNum + " " + tokenType.name() + " " + str);
        }
        if (errors.isEmpty()) {
            String outputFile = "lexer.txt";
            try {
                PrintStream ps = new PrintStream(outputFile);
                System.out.println("Correct");
                System.setOut(ps);
                for (Token token : tokens) {
                    System.out.println(token.type().name() + ' ' + token.str());
                }
            }catch(IOException e){
                System.out.println("Can not find " + outputFile);
            }
        }
        else {
            String outputFile = "error.txt";
            try {
                PrintStream ps = new PrintStream(outputFile);
                System.out.println("Error");
                System.setOut(ps);
                for (Error error : errors) {
                    System.out.printf("%d %c", error.lineNum(), error.type());
                }
            }catch(FileNotFoundException e){
                System.out.println("Can not Find " + outputFile);
            }
        }
    }

    private TokenType reserve(String str) {
        return switch (str) {
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
            default -> null;
        };
    }

    private TokenType single(String str) {
        return switch (str) {
            case "+" -> TokenType.PLUS;
            case "-" -> TokenType.MINU;
            case "*" -> TokenType.MULT;
            case "%" -> TokenType.MOD;
            case ";" -> TokenType.SEMICN;
            case "," -> TokenType.COMMA;
            case "(" -> TokenType.LPARENT;
            case ")" -> TokenType.RPARENT;
            case "[" -> TokenType.LBRACK;
            case "]" -> TokenType.RBRACK;
            case "{" -> TokenType.LBRACE;
            case "}" -> TokenType.RBRACE;
            default -> null;
        };
    }
}