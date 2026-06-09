package Lexical;

import Datas.*;
import CompileErrors.*;

import java.io.IOException;
import java.io.PushbackReader;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/22 13:17
 */
public class Lexer {
//    public char errorCode;
//    public int errorLine;
    private static Lexer instance;
    public static Lexer getInstance() {
        if (instance == null) {
            instance = new Lexer();
        }
        return instance;
    }

    public PushbackReader reader;
    public ArrayList<Token> tokens = new ArrayList<>();
    public int lineNo = 1;

    public void setReader(PushbackReader reader) {
        this.reader = reader;
    }

    public void analyze() throws IOException {
        int ch;
        while ((ch = reader.read()) != -1) {
//            System.out.print("ch=" + ch);
            if (!(ch == ' ' || ch == '\t' || ch == '\n')) {
                reader.unread(ch);
                next();
            } else if (ch == '\n') {
                lineNo++;
            }
        }
        Token.setData(tokens);
    }

    public void next() throws IOException {
        Token token = new Token();
        StringBuilder nameBuilder = new StringBuilder();
        int ch;

        ch = reader.read();

        if (CheckTools.isAlpha(ch) || ch == '_') {
            // identifier and reserved word
            // q1
            nameBuilder.append((char)ch);
            ch = reader.read();
            while(CheckTools.isAlpha(ch) || CheckTools.isDigit(ch) || ch == '_') {
                // q2
                nameBuilder.append((char)ch);
                ch = reader.read();
            }
            // q3
            reader.unread(ch);
            token.tokenType = checkReverse(nameBuilder.toString());
            token.name = nameBuilder.toString();
        } else if (CheckTools.isDigit(ch)) {
            // int const(no op)
            nameBuilder.append((char)ch);
            while(CheckTools.isDigit((ch = reader.read()))) {
                nameBuilder.append((char)ch);
            }
            reader.unread(ch);
            token.tokenType = Token.TokenType.INTCON;
            token.name = nameBuilder.toString();
        } else if (ch == '\'') {
            // char const
            nameBuilder.append((char)ch);
            asciiProcess(nameBuilder, ch, token);
            if ((ch = reader.read()) == '\'') {
                nameBuilder.append((char)ch);
                token.tokenType = Token.TokenType.CHRCON;
                token.name = nameBuilder.toString();
            }
        } else if (ch == '"') {
            nameBuilder.append((char)ch);
            while ((ch = reader.read()) != '"' && ch != -1) {
                if (CheckTools.isLegalAscii(ch)) {
                    // q2
                    nameBuilder.append((char)ch);

                } else if (ch == '\\') {
                    // q4
                    nameBuilder.append((char)ch);
                    if (CheckTools.isTranversableAscii(ch = reader.read())) {
                        nameBuilder.append((char)ch);
                    }
                }
            }
            if (ch == '"') {
                nameBuilder.append((char)ch);
                token.tokenType = Token.TokenType.STRCON;
                token.name = nameBuilder.toString();
            } else {
                // error
            }
        } else if (ch == '/'){
            // note or divide
            // q1
            ch = reader.read();
            if (ch == '/') {
                // single line note q2
                while ((ch = reader.read()) != '\n') {
                    if (ch == -1) {
                        return;
                    }
                }
                lineNo++;
                return;
            } else if (ch == '*') {
                // multi-line note q5
                while (ch != -1) {
                    // while loop at the outer side is for q6 -> q5
                    // terrible structure...
                    while ((ch = reader.read()) != '*') {
                        // q5
                        if (ch == -1) {
                            reader.unread(ch);
                            return;
                        } else if (ch == '\n') {
                            lineNo++;
                        }
                    }
                    // q6
                    while ((ch = reader.read()) == '*') {
                        // q6
                    }
                    if (ch == '/') {
                        // q7
                        return;
                    }
                }
                return;
            } else {
                // divide '/'
                reader.unread(ch);
                token.tokenType = Token.TokenType.DIV;
                token.name = "/";
            }
        } else if (ch == '<') {
            ch = reader.read();
            if (ch == '=') {
                // <=
                token.tokenType = Token.TokenType.LEQ;
                token.name = "<=";
            } else {
                reader.unread(ch);
                token.tokenType = Token.TokenType.LSS;
                token.name = "<";
            }
        } else if (ch == '>') {
            ch = reader.read();
            if (ch == '=') {
                // >=
                token.tokenType = Token.TokenType.GEQ;
                token.name = ">=";
            } else {
                reader.unread(ch);
                token.tokenType = Token.TokenType.GRE;
                token.name = ">";
            }
        } else if (ch == '=') {
            ch = reader.read();
            if (ch == '=') {
                token.tokenType = Token.TokenType.EQL;
                token.name = "==";
            } else {
                reader.unread(ch);
                token.tokenType = Token.TokenType.ASSIGN;
                token.name = "=";
            }
        } else if (ch == '!') {
            ch = reader.read();
            if (ch == '=') {
                token.tokenType = Token.TokenType.NEQ;
                token.name = "!=";
            } else {
                reader.unread(ch);
                token.tokenType = Token.TokenType.NOT;
                token.name = "!";
            }
        } else if (ch == '&') {
            ch = reader.read();
            if (ch == '&') {
                token.tokenType = Token.TokenType.AND;
                token.name = "&&";
            } else {
                // error code a
                reader.unread(ch);
                token.tokenType = Token.TokenType.AND;
                token.name = "&";
//                errorCode = 'a';
//                errorLine = lineNo;
                CompileErrorHandler.getInstance().addErrorMessage(lineNo, 'a');
            }
        } else if (ch == '|') {
            ch = reader.read();
            if (ch == '|') {
                token.tokenType = Token.TokenType.OR;
                token.name = "||";
            } else {
                // error code a
                reader.unread(ch);
                token.tokenType = Token.TokenType.OR;
                token.name = "|";
                CompileErrorHandler.getInstance().addErrorMessage(lineNo, 'a');
//                errorCode = 'a';
//                errorLine = lineNo;

            }
        } else {
            nameBuilder.append((char)ch);
            token.tokenType = checkReverse(nameBuilder.toString());
            if (token.tokenType != Token.TokenType.IDENFR) {
                token.name = nameBuilder.toString();
            } else {
                // error
            }
        }

        token.lineNumber = lineNo;
        tokens.add(token);
    }
    
    /**
     * @Description 判断strcon和chrcon时用，识别一个纯的（不含引号）ASCII字符（包括转义）
     *  ch无所谓，reader得指向ascii的第一个字符上
     * @author
     * @date 2024/9/22 16:00
    **/
    private void asciiProcess(StringBuilder nameBuilder, int ch, Token token) throws IOException {
        ch = reader.read();
        if (CheckTools.isLegalAscii(ch)) {
            // q2
            nameBuilder.append((char)ch);

        } else if (ch == '\\') {
            // q4
            nameBuilder.append((char)ch);
            if (CheckTools.isTranversableAscii(ch = reader.read())) {
                nameBuilder.append((char)ch);
            }
        }
    }

    /**
     * @Description 检查这个字符串是不是保留字或者某个长度为1的符号
     * @author
     * @date 2024/9/22 14:53
    **/
    public Token.TokenType checkReverse(String name) {
        for (Token.TokenType tokenType: Token.TokenType.values()) {
//            System.out.println(tokenType.toString() + "  " + name);
            if (!tokenType.toString().equals("0") && tokenType.toString().equals(name)) {
                return tokenType;
            }
        }
        return Token.TokenType.IDENFR;
    }

//    public void outputErrorMessage(FileWriter writer) throws IOException{
//        writer.write(errorLine + " " + errorCode);
//    }
}
