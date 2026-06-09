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
import java.util.ArrayList;

import static token.Type.*;
import static error.ErrorType.*;

public class Lexer {
    private PushbackReader reader;
    private PrintWriter writer;
    private ArrayList<Token> tokens = new ArrayList<>();
    private ArrayList<Error> errors = new ArrayList<>();

    public Lexer(String inputFileName, String outputFileName) throws FileNotFoundException {
        this.reader = new PushbackReader(new BufferedReader(new FileReader(inputFileName)), 1);
        this.writer = new PrintWriter(outputFileName);
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
            if (ch == '\\') {
                ch = (char) reader.read();
                sb.append(ch);
            }
        }
        return sb.toString();
    }

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
                            if (ch == '*') {
                                nextCh = reader.read();
                                if (nextCh == '/') {
                                    break; // 找到注释结束符 */
                                }
                                reader.unread(nextCh);
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
                                writeToken(SEMICN, ";", lineNumber);
                                break;
                            case '(':
                                writeToken(LPARENT, "(", lineNumber);
                                break;
                            case ')':
                                writeToken(RPARENT, ")", lineNumber);
                                break;
                            case '[':
                                writeToken(LBRACK, "[", lineNumber);
                                break;
                            case ']':
                                writeToken(RBRACK, "]", lineNumber);
                                break;
                            case '{':
                                writeToken(LBRACE, "{", lineNumber);
                                break;
                            case '}':
                                writeToken(RBRACE, "}", lineNumber);
                                break;
                            case ',':
                                writeToken(COMMA, ",", lineNumber);
                                break;
                            case '+':
                                writeToken(PLUS, "+", lineNumber);
                                break;
                            case '-':
                                writeToken(MINU, "-", lineNumber);
                                break;
                            case '*':
                                writeToken(MULT, "*", lineNumber);
                                break;
                            case '/':
                                writeToken(DIV, "/", lineNumber);
                                break;
                            case '%':
                                writeToken(MOD, "%", lineNumber);
                                break;
                            default:
                                // 不应达到此处，因为 ch 已经被确认为不是 '/' 或者其他情况已经处理
                                break;
                        }
                    }
                    break;
                case ';':
                    writeToken(SEMICN, ";", lineNumber);
                    break;
                case '(':
                    writeToken(LPARENT, "(", lineNumber);
                    break;
                case ')':
                    writeToken(RPARENT, ")", lineNumber);
                    break;
                case '[':
                    writeToken(LBRACK, "[", lineNumber);
                    break;
                case ']':
                    writeToken(RBRACK, "]", lineNumber);
                    break;
                case '{':
                    writeToken(LBRACE, "{", lineNumber);
                    break;
                case '}':
                    writeToken(RBRACE, "}", lineNumber);
                    break;
                case ',':
                    writeToken(COMMA, ",", lineNumber);
                    break;
                case '+':
                    writeToken(PLUS, "+", lineNumber);
                    break;
                case '-':
                    writeToken(MINU, "-", lineNumber);
                    break;
                case '*':
                    writeToken(MULT, "*", lineNumber);
                    break;
                case '%':
                    writeToken(MOD, "%", lineNumber);
                    break;
                case '<':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(LEQ, "<=", lineNumber);
                    } else {
                        writeToken(LSS, "<", lineNumber);
                        reader.unread(nextCh);
                    }
                    break;
                case '>':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(GEQ, ">=", lineNumber);
                    } else {
                        writeToken(GRE, ">", lineNumber);
                        reader.unread(nextCh);
                    }
                    break;
                case '=':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(EQL, "==", lineNumber);
                    } else {
                        writeToken(ASSIGN, "=", lineNumber);
                        reader.unread(nextCh);
                    }
                    break;
                case '!':
                    nextCh = reader.read();
                    if (nextCh == '=') {
                        writeToken(NEQ, "!=", lineNumber);
                    } else {
                        writeToken(NOT, "!", lineNumber);
                        reader.unread(nextCh);
                    }
                    break;
                case '&':
                    nextCh = reader.read();
                    if (nextCh == '&') {
                        writeToken(AND, "&&", lineNumber);
                    } else {
                        writeToken(AND, "&&", lineNumber);
                        writeError(lineNumber, a);
                        reader.unread(nextCh);
                    }
                    break;
                case '|':
                    nextCh = reader.read();
                    if (nextCh == '|') {
                        writeToken(OR, "||", lineNumber);
                    } else {
                        writeToken(OR, "||", lineNumber);
                        writeError(lineNumber, a);
                        reader.unread(nextCh);
                    }
                    break;
                default:
                    if (Character.isLetter(ch) || ch == '_') {
                        String identifier = readIdentifierOrKeyword((char) ch);
                        writeToken(mapKeyword(identifier), identifier, lineNumber);
                    } else if (Character.isDigit(ch)) {
                        String number = readNumber(ch);
                        writeToken(INTCON, number, lineNumber);
                    } else if (isQuote((char) ch)) {
                        if (ch == '\'') {
                            String stringLiteral = readStringLiteral((char) ch);
                            writeToken(CHRCON, "\'" + stringLiteral + "\'", lineNumber);
                        }
                        if (ch == '\"') {
                            String stringLiteral = readStringLiteral((char) ch);
                            writeToken(STRCON, "\"" + stringLiteral + "\"", lineNumber);
                        }
                    } else {
                        throw new IllegalArgumentException("Unknown token: " + (char) ch);
                    }
                    break;
            }
        }
        reader.close();
        writer.close();
    }

    private void writeToken(Type type, String value, int line) {
        Token token = new Token(type, value, line);
        writer.println(token.toString());
        tokens.add(token);
    }

    private void writeError(int line, ErrorType type) {
        Error error = new Error(type, line);
        errors.add(error);
        // errorWriter.println(error.toString());
    }

    public ArrayList<Error> getErrors() {
        return errors;
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

    public ArrayList<Token> getTokens() {
        return tokens;
    }
}