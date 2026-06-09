package frontend;
import java.io.*;
import java.util.*;

public class Lexer {
    private static Lexer instance;
    private String source;
    private int curPos;
    private String token;
    private LexType lexType;
    private List<String> reserveWords;
    private int lineNum;
    private String inputFile;
    private List<Token> tokens;
    private List<MyError> myErrors;

    private Lexer(List<Token> tokens, List<MyError> myErrors) {
        this.tokens = tokens;
        this.myErrors = myErrors;
    }

    public static Lexer getInstance(List<Token> tokens, List<MyError> myErrors) {
        if (instance == null) {
            instance = new Lexer(tokens , myErrors);
        }
        return instance;
    }

    public void initialize(String inputFile) {
        this.inputFile = inputFile;
        this.lineNum = 1;
        loadSource();
    }

    private void loadSource() {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFile))) {
            String line;
            while ((line = reader.readLine()) != null) {
                sb.append(line).append("\n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        this.source = sb.toString();
    }

    public void tokenize() {
        while (curPos < source.length()) {
            next();
            if (lexType != null) {
                tokens.add(new Token(lexType, token, lineNum));
            }
        }
    }

    public List<Token> getTokens() {
        return tokens;
    }

    public List<MyError> getErrors() {
        return myErrors;
    }

    public void next() {
        token = "";
        lexType = null;

        while (curPos < source.length() && Character.isWhitespace(source.charAt(curPos))) {
            if (source.charAt(curPos) == '\n') {
                lineNum++;
            }
            curPos++;
        }

        if (curPos >= source.length()) {
            return;
        }

        char currentChar = source.charAt(curPos);
        char nextChar = curPos + 1 < source.length() ? source.charAt(curPos + 1) : '\0';

        if (currentChar == '/' && nextChar == '/') {
            skipSingleLineComment();
            next(); // Recursive call to continue lexing after skipping comment
            return;
        } else if (currentChar == '/' && nextChar == '*') {
            skipMultiLineComment();
            next(); // Recursive call to continue lexing after skipping comment
            return;
        }

        switch (currentChar) {
            case '!':
                if (nextChar == '=') {
                    token = "!=";
                    lexType = LexType.NEQ;
                    curPos += 2;
                } else {
                    token = "!";
                    lexType = LexType.NOT;
                    curPos++;
                }
                break;
            case '&':
                if (nextChar == '&') {
                    token = "&&";
                    lexType = LexType.AND;
                    curPos += 2;
                } else {
                    token = "&&";
                    lexType = LexType.AND;
                    MyError myError = new MyError(lineNum, "a");
                    addError(myError);
                    curPos++;
                }
                break;
            case '|':
                if (nextChar == '|') {
                    token = "||";
                    lexType = LexType.OR;
                    curPos += 2;
                } else {
                    token = "||";
                    lexType = LexType.OR;
                    MyError myError = new MyError(lineNum, "a");
                    addError(myError);
                    curPos++;
                }
                break;
            case '+':
                token = "+";
                lexType = LexType.PLUS;
                curPos++;
                break;
            case '-':
                token = "-";
                lexType = LexType.MINU;
                curPos++;
                break;
            case '*':
                token = "*";
                lexType = LexType.MULT;
                curPos++;
                break;
            case '/':
                token = "/";
                lexType = LexType.DIV;
                curPos++;
                break;
            case '%':
                token = "%";
                lexType = LexType.MOD;
                curPos++;
                break;
            case '<':
                if (nextChar == '=') {
                    token = "<=";
                    lexType = LexType.LEQ;
                    curPos += 2;
                } else {
                    token = "<";
                    lexType = LexType.LSS;
                    curPos++;
                }
                break;
            case '>':
                if (nextChar == '=') {
                    token = ">=";
                    lexType = LexType.GEQ;
                    curPos += 2;
                } else {
                    token = ">";
                    lexType = LexType.GRE;
                    curPos++;
                }
                break;
            case '=':
                if (nextChar == '=') {
                    token = "==";
                    lexType = LexType.EQL;
                    curPos += 2;
                } else {
                    token = "=";
                    lexType = LexType.ASSIGN;
                    curPos++;
                }
                break;
            case ';':
                token = ";";
                lexType = LexType.SEMICN;
                curPos++;
                break;
            case ',':
                token = ",";
                lexType = LexType.COMMA;
                curPos++;
                break;
            case '(':
                token = "(";
                lexType = LexType.LPARENT;
                curPos++;
                break;
            case ')':
                token = ")";
                lexType = LexType.RPARENT;
                curPos++;
                break;
            case '[':
                token = "[";
                lexType = LexType.LBRACK;
                curPos++;
                break;
            case ']':
                token = "]";
                lexType = LexType.RBRACK;
                curPos++;
                break;
            case '{':
                token = "{";
                lexType = LexType.LBRACE;
                curPos++;
                break;
            case '}':
                token = "}";
                lexType = LexType.RBRACE;
                curPos++;
                break;
            case '"':
                tokenizeStringConstant();
                break;
            case '\'':
                tokenizeCharConstant();
                break;
            default:
                if (isNonDigit(currentChar)) {
                    tokenizeIdentifierOrReservedWord();
                } else if (Character.isDigit(currentChar)) {
                    tokenizeNumber();
                } else {
                    String str = "Unknown token at line " + lineNum + ": " + currentChar;
                    MyError myError = new MyError(lineNum, str);
                    addError(myError);
                    curPos++;
                }
                break;
        }
    }

    private void skipSingleLineComment() {
        curPos += 2; // Skip the "//"
        while (curPos < source.length() && source.charAt(curPos) != '\n') {
            curPos++;
        }
        if (curPos < source.length() && source.charAt(curPos) == '\n') {
            lineNum++;
            curPos++;
        }
    }

    private void skipMultiLineComment() {
        curPos += 2; // Skip the "/*"
        while (curPos + 1 < source.length() && !(source.charAt(curPos) == '*' && source.charAt(curPos + 1) == '/')) {
            if (source.charAt(curPos) == '\n') {
                lineNum++;
            }
            curPos++;
        }
        if (curPos + 1 < source.length() && source.charAt(curPos) == '*' && source.charAt(curPos + 1) == '/') {
            curPos += 2; // Skip the "*/"
        } else {
            String str = "Unterminated multi-line comment at line " + lineNum;
            MyError myError = new MyError(lineNum, str);
            addError(myError);
            curPos++;
        }
    }

    private void tokenizeStringConstant() {
        StringBuilder tokenBuilder = new StringBuilder();
        tokenBuilder.append('"');
        curPos++;
        while (curPos < source.length() && source.charAt(curPos) != '"') {
            char currentChar = source.charAt(curPos);
            if (currentChar == '\n') {
                lineNum++;
            }
            tokenBuilder.append(currentChar);
            curPos++;
        }
        if (curPos < source.length() && source.charAt(curPos) == '"') {
            tokenBuilder.append('"');
            curPos++;
            token = tokenBuilder.toString();
            lexType = LexType.STRCON;
        } else {
            String str = "Unterminated string constant at line " + lineNum;
            MyError myError = new MyError(lineNum, str);
            addError(myError);
            lexType = LexType.ERROR;
        }
    }

    private void tokenizeCharConstant() {
        StringBuilder tokenBuilder = new StringBuilder();
        tokenBuilder.append('\''); // 添加起始引号
        curPos++;

        if (curPos < source.length()) {
            char currentChar = source.charAt(curPos);

            // 检查是否是转义字符
            if (currentChar == '\\') {
                curPos++;
                if (curPos < source.length()) {
                    currentChar = source.charAt(curPos);
                    if (currentChar == '0') {
                        tokenBuilder.append("\\0");
                        curPos++;
                    } else if (currentChar == 'a') {
                        tokenBuilder.append("\\a");
                        curPos++;
                    } else if (currentChar == 'b') {
                        tokenBuilder.append("\\b");
                        curPos++;
                    } else if (currentChar == 't') {
                        tokenBuilder.append("\\t");
                        curPos++;
                    } else if (currentChar == 'n') {
                        tokenBuilder.append("\\n");
                        curPos++;
                    } else if (currentChar == 'v') {
                        tokenBuilder.append("\\v");
                        curPos++;
                    } else if (currentChar == 'f') {
                        tokenBuilder.append("\\f");
                        curPos++;
                    } else if (currentChar == '\'' || currentChar == '\"' || currentChar == '\\') {
                        tokenBuilder.append('\\').append(currentChar);
                        curPos++;
                    } else {
                        String str = "Invalid escape sequence at line " + lineNum;
                        MyError myError = new MyError(lineNum, str);
                        addError(myError);
                        lexType = LexType.ERROR;
                        while (curPos < source.length() && source.charAt(curPos) != '\n') {
                            curPos++;
                        }
                        return;
                    }
                }
            } else if (currentChar != '\'' && currentChar != '\n') {
                tokenBuilder.append(currentChar);
                curPos++;
            } else {
                String str = "Invalid char constant at line " + lineNum;
                MyError myError = new MyError(lineNum, str);
                addError(myError);
                lexType = LexType.ERROR;
                while (curPos < source.length() && source.charAt(curPos) != '\n') {
                    curPos++;
                }
                return;
            }

            // 检查结束引号
            if (curPos < source.length() && source.charAt(curPos) == '\'') {
                tokenBuilder.append('\'');
                token = tokenBuilder.toString();
                lexType = LexType.CHRCON;
                curPos++;
            } else {
                String str = "Unterminated char constant at line " + lineNum;
                MyError myError = new MyError(lineNum, str);
                addError(myError);
                lexType = LexType.ERROR;
                while (curPos < source.length() && source.charAt(curPos) != '\n') {
                    curPos++;
                }
            }
        } else {
            String str = "Unterminated char constant at line " + lineNum;
            MyError myError = new MyError(lineNum, str);
            addError(myError);
            lexType = LexType.ERROR;
        }
    }

    private void tokenizeIdentifierOrReservedWord() {
        StringBuilder tokenBuilder = new StringBuilder();
        tokenBuilder.append(source.charAt(curPos));
        curPos++;
        while (curPos < source.length() && (isNonDigit(source.charAt(curPos)) || Character.isDigit(source.charAt(curPos)))) {
            tokenBuilder.append(source.charAt(curPos));
            curPos++;
        }
        token = tokenBuilder.toString();
        reserve();
    }

    private void tokenizeNumber() {
        StringBuilder tokenBuilder = new StringBuilder();
        tokenBuilder.append(source.charAt(curPos));
        curPos++;
        while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
            tokenBuilder.append(source.charAt(curPos));
            curPos++;
        }
        token = tokenBuilder.toString();
        lexType = LexType.INTCON;
    }

    private void reserve() {
        switch (token) {
            case "else":
                lexType = LexType.ELSETK;
                break;
            case "void":
                lexType = LexType.VOIDTK;
                break;
            case "main":
                lexType = LexType.MAINTK;
                break;
            case "for":
                lexType = LexType.FORTK;
                break;
            case "const":
                lexType = LexType.CONSTTK;
                break;
            case "getint":
                lexType = LexType.GETINTTK;
                break;
            case "int":
                lexType = LexType.INTTK;
                break;
            case "getchar":
                lexType = LexType.GETCHARTK;
                break;
            case "char":
                lexType = LexType.CHARTK;
                break;
            case "printf":
                lexType = LexType.PRINTFTK;
                break;
            case "break":
                lexType = LexType.BREAKTK;
                break;
            case "return":
                lexType = LexType.RETURNTK;
                break;
            case "continue":
                lexType = LexType.CONTINUETK;
                break;
            case "if":
                lexType = LexType.IFTK;
                break;
            default:
                lexType = LexType.IDENFR;
                break;
        }
    }

    private void addError(MyError myError) {
        myErrors.add(myError);
    }

    private boolean isNonDigit(char c) {
        return Character.isLetter(c) || c == '_';
    }
}
