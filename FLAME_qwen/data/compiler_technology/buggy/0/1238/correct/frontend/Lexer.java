package frontend;

import error.ErrorType;
import token.Token;
import token.Type;
import error.Error;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PushbackReader;
import java.io.FileNotFoundException;
import java.io.PrintWriter;

import static token.Type.*;
import static error.ErrorType.*;

public class Lexer {
    private PushbackReader reader;
    private PrintWriter writer;
    private PrintWriter errorWriter;

    public Lexer(String inputFileName, String outputFileName, String errorFileName) throws FileNotFoundException {
        this.reader = new PushbackReader(new BufferedReader(new FileReader(inputFileName)), 1);
        this.writer = new PrintWriter(outputFileName);
        this.errorWriter = new PrintWriter(errorFileName);
    }

    private boolean isWhitespace(char ch) {
        return Character.isWhitespace(ch);
    }

    private boolean isIdentifierStart(char ch) {
        return Character.isLetter(ch) || ch == '_';
    }

    private boolean isIdentifierPart(char ch) {
        return Character.isLetterOrDigit(ch) || ch == '_';
    }

    private boolean isDigit(char ch) {
        return Character.isDigit(ch);
    }

    private boolean isQuote(char ch) {
        return ch == '\'' || ch == '"';
    }

    private boolean isEndOfFile(int ch) {
        return ch == -1;
    }

    private String readIdentifierOrKeyword(char ch) throws IOException {
        if (isIdentifierStart((char) ch)) {
            StringBuilder sb = new StringBuilder();                                                                              
            sb.append((char) ch);
            while (!isEndOfFile((ch = (char) reader.read())) && isIdentifierPart((char) ch)) {
                sb.append((char) ch);
            }
            reader.unread(ch); // 将最后一个字符重新放入输入流
            return sb.toString();
        } else {
            throw new IllegalArgumentException("Expected an identifier start but got: " + (char) ch);
        }
    }

    private String readNumber(int ch) throws IOException {
        if (isDigit((char) ch)) {
            StringBuilder sb = new StringBuilder();
            sb.append((char) ch);
            while (!isEndOfFile((ch = reader.read())) && isDigit((char) ch)) {
                sb.append((char) ch);
            }
            reader.unread(ch); // 将最后一个字符重新放入输入流
            return sb.toString();
        } else {
            throw new IllegalArgumentException("Expected a digit but got: " + (char) ch);
        }
    }

    private String readStringLiteral(char ch) throws IOException {
        StringBuilder sb = new StringBuilder();
        while (!isEndOfFile((ch = (char) reader.read())) && !isQuote((char) ch)) {
            sb.append((char) ch);
        }
        return sb.toString();
    }

    /*public void parse() throws IOException {
        int ch;
        while (!isEndOfFile((ch = reader.read()))) {
            if (isWhitespace((char) ch)) {
                continue; // 忽略空白字符
            }
            switch (ch) {
                case ';':
                    writeToken(SEMICN, ";");
                    break;
                case '(':
                    writeToken(LPARENT, "(");
                    break;
                case ')':
                    writeToken(RPARENT, ")");
                    break;
                case '[':
                    writeToken(LBRACK, "[");
                    break;
                case ']':
                    writeToken(RBRACK, "]");
                    break;
                case '{':
                    writeToken(LBRACE, "{");
                    break;
                case '}':
                    writeToken(RBRACE, "}");
                    break;
                case ',':
                    writeToken(COMMA, ",");
                    break;
                case '+':
                    writeToken(PLUS, "+");
                    break;
                case '-':
                    writeToken(MINU, "-");
                    break;
                case '*':
                    writeToken(MULT, "*");
                    break;
                case '/':
                    writeToken(DIV, "/");
                    break;
                case '%':
                    writeToken(MOD, "%");
                    break;
                case '<':
                    int nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(LEQ, "<=");
                    } else {
                        writeToken(LSS, "<");
                        reader.unread(nextCh);
                    }
                    break;
                case '>':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(GEQ, ">=");
                    } else {
                        writeToken(GRE, ">");
                        reader.unread(nextCh);
                    }
                    break;
                case '=':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(EQL, "==");
                    } else {
                        writeToken(ASSIGN, "=");
                        reader.unread(nextCh);
                    }
                    break;
                case '!':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(NEQ, "!=");
                    } else {
                        writeToken(NOT, "!");
                        reader.unread(nextCh);
                    }
                    break;
                case '&':
                    nextCh = reader.read();
                    if (nextCh == '&') {
                        writeToken(AND, "&&");
                    } else {
                        writeToken(AND, "&");
                        reader.unread(nextCh);
                    }
                    break;
                case '|':
                    nextCh = reader.read();
                    if (nextCh == '|') {
                        writeToken(OR, "||");
                    } else {
                        writeToken(OR, "|");
                        reader.unread(nextCh);
                    }
                    break;
                default:
                    if (Character.isLetter(ch) || ch == '_') {
                        String identifier = readIdentifierOrKeyword((char) ch);
                        writeToken(mapKeyword(identifier), identifier);
                    } else if (Character.isDigit(ch)) {
                        String number = readNumber(ch);
                        writeToken(INTCON, number);
                    } else if (isQuote((char) ch)) {
                        String stringLiteral = readStringLiteral((char) ch);
                        writeToken(STRCON, "\"" + stringLiteral + "\"");
                    } else {
                        throw new IllegalArgumentException("Unknown token: " + (char) ch);
                    }
            }
        }
        reader.close();
        writer.close();
    }*/

    public void parse() throws IOException {
        int ch;
        int lineNumber = 1;

        while (!isEndOfFile((ch = reader.read()))) {
            if (isWhitespace((char) ch)) {
                if ((char) ch == '\n') {
                    lineNumber++; // 遇到换行符时增加行号
                }
                continue; // 忽略空白字符
            }
            switch (ch) {
                case '/': // 检查是否为注释的开始
                    int nextCh = reader.read();
                    if (nextCh == '/') { // 单行注释 //
                        while ((ch = reader.read()) != '\n' && !isEndOfFile(ch));
                        lineNumber++;
                        continue;
                    } else if (nextCh == '*') { // 多行注释 /*
                        while (true) {
                            ch = reader.read();
                            if (isEndOfFile(ch)) {
                                break; // 如果文件结束前没有找到注释结束符，则退出
                            }
                            if (ch == '*' && (nextCh = reader.read()) == '/') {
                                break; // 找到注释结束符 */
                            }
                            if (ch == '\n') {
                                lineNumber++; // 遇到换行符时增加行号
                            }
                        }
                        continue;
                    } else {
                        reader.unread(nextCh); // 如果不是注释，则将下一个字符放回流中
                        switch (ch) {
                            case ';':
                                writeToken(SEMICN, ";");
                                break;
                            case '(':
                                writeToken(LPARENT, "(");
                                break;
                            case ')':
                                writeToken(RPARENT, ")");
                                break;
                            case '[':
                                writeToken(LBRACK, "[");
                                break;
                            case ']':
                                writeToken(RBRACK, "]");
                                break;
                            case '{':
                                writeToken(LBRACE, "{");
                                break;
                            case '}':
                                writeToken(RBRACE, "}");
                                break;
                            case ',':
                                writeToken(COMMA, ",");
                                break;
                            case '+':
                                writeToken(PLUS, "+");
                                break;
                            case '-':
                                writeToken(MINU, "-");
                                break;
                            case '*':
                                writeToken(MULT, "*");
                                break;
                            case '/':
                                writeToken(DIV, "/");
                                break;
                            case '%':
                                writeToken(MOD, "%");
                                break;
                            default:
                                // 不应达到此处，因为 ch 已经被确认为不是 '/' 或者其他情况已经处理
                                break;
                        }
                    }
                    break;
                case ';':
                    writeToken(SEMICN, ";");
                    break;
                case '(':
                    writeToken(LPARENT, "(");
                    break;
                case ')':
                    writeToken(RPARENT, ")");
                    break;
                case '[':
                    writeToken(LBRACK, "[");
                    break;
                case ']':
                    writeToken(RBRACK, "]");
                    break;
                case '{':
                    writeToken(LBRACE, "{");
                    break;
                case '}':
                    writeToken(RBRACE, "}");
                    break;
                case ',':
                    writeToken(COMMA, ",");
                    break;
                case '+':
                    writeToken(PLUS, "+");
                    break;
                case '-':
                    writeToken(MINU, "-");
                    break;
                case '*':
                    writeToken(MULT, "*");
                    break;
                case '%':
                    writeToken(MOD, "%");
                    break;
                case '<':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(LEQ, "<=");
                    } else {
                        writeToken(LSS, "<");
                        reader.unread(nextCh);
                    }
                    break;
                case '>':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(GEQ, ">=");
                    } else {
                        writeToken(GRE, ">");
                        reader.unread(nextCh);
                    }
                    break;
                case '=':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(EQL, "==");
                    } else {
                        writeToken(ASSIGN, "=");
                        reader.unread(nextCh);
                    }
                    break;
                case '!':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(NEQ, "!=");
                    } else {
                        writeToken(NOT, "!");
                        reader.unread(nextCh);
                    }
                    break;
                case '&':
                    nextCh = reader.read();
                    if (nextCh == '&') {
                        writeToken(AND, "&&");
                    } else {
                        writeError(lineNumber, a);
                        reader.unread(nextCh);
                    }
                    break;
                case '|':
                    nextCh = reader.read();
                    if (nextCh == '|') {
                        writeToken(OR, "||");
                    } else {
                        writeError(lineNumber, a);
                        reader.unread(nextCh);
                    }
                    break;
                default:
                    if (Character.isLetter(ch) || ch == '_') {
                        String identifier = readIdentifierOrKeyword((char) ch);
                        writeToken(mapKeyword(identifier), identifier);
                    } else if (Character.isDigit(ch)) {
                        String number = readNumber(ch);
                        writeToken(INTCON, number);
                    } else if (isQuote((char) ch)) {
                        if (ch == '\'') {
                            String stringLiteral = readStringLiteral((char) ch);
                            writeToken(CHRCON, "\'" + stringLiteral + "\'");
                        }
                        if (ch == '\"') {
                            String stringLiteral = readStringLiteral((char) ch);
                            writeToken(STRCON, "\"" + stringLiteral + "\"");
                        }
                    } else {
                        throw new IllegalArgumentException("Unknown token: " + (char) ch);
                    }
                    break;
            }
        }
        reader.close();
        writer.close();
        errorWriter.close();
    }

    private void writeToken(Type type, String value) {
        Token token = new Token(type, value);
        writer.println(token.toString());
    }

    private void writeError(int line, ErrorType type) {
        Error error = new Error(type, line);
        errorWriter.println(error.toString());
    }

    private Type mapKeyword(String identifier) {
        switch (identifier) {
            case "else":
                return ELSETK;
            case "void":
                return VOIDTK;
            case "main":
                return MAINTK;
            case "for":
                return FORTK;
            case "const":
                return CONSTTK;
            case "getint":
                return GETINTTK;
            case "int":
                return INTTK;
            case "getchar":
                return GETCHARTK;
            case "char":
                return CHARTK;
            case "printf":
                return PRINTFTK;
            case "break":
                return BREAKTK;
            case "return":
                return RETURNTK;
            case "if":
                return IFTK;
            case "continue":
                return CONTINUETK;
            default:
                return IDENFR;
        }
    }
}