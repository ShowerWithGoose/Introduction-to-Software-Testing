import java.io.*;
import java.util.*;

enum TokenType {
    CONSTTK, INTTK, CHARTK, VOIDTK, MAINTK, IDENFR, INTCON, STRCON, CHRCON, ELSETK, IFTK, FORTK, 
    GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, BREAKTK, CONTINUETK, PLUS, MINU, MULT, DIV, MOD, 
    ASSIGN, EQL, NEQ, LSS, LEQ, GRE, GEQ, NOT, AND, OR, LPARENT, RPARENT, LBRACK, RBRACK, 
    LBRACE, RBRACE, SEMICN, COMMA, INVALID
}

enum ErrorType {
    INVALID_CHAR
}

public class Compiler {
    static Map<TokenType, String> tokenTypeToStr = new HashMap<>();
    static List<String> lines = new ArrayList<>();
    static PrintWriter lexerOut, errorOut;
    static int currentLine = 0;

    static {
        tokenTypeToStr.put(TokenType.CONSTTK, "CONSTTK");
        tokenTypeToStr.put(TokenType.INTTK, "INTTK");
        tokenTypeToStr.put(TokenType.CHARTK, "CHARTK");
        tokenTypeToStr.put(TokenType.VOIDTK, "VOIDTK");
        tokenTypeToStr.put(TokenType.MAINTK, "MAINTK");
        tokenTypeToStr.put(TokenType.IDENFR, "IDENFR");
        tokenTypeToStr.put(TokenType.INTCON, "INTCON");
        tokenTypeToStr.put(TokenType.STRCON, "STRCON");
        tokenTypeToStr.put(TokenType.CHRCON, "CHRCON");
        tokenTypeToStr.put(TokenType.ELSETK, "ELSETK");
        tokenTypeToStr.put(TokenType.IFTK, "IFTK");
        tokenTypeToStr.put(TokenType.FORTK, "FORTK");
        tokenTypeToStr.put(TokenType.GETINTTK, "GETINTTK");
        tokenTypeToStr.put(TokenType.GETCHARTK, "GETCHARTK");
        tokenTypeToStr.put(TokenType.PRINTFTK, "PRINTFTK");
        tokenTypeToStr.put(TokenType.RETURNTK, "RETURNTK");
        tokenTypeToStr.put(TokenType.BREAKTK, "BREAKTK");
        tokenTypeToStr.put(TokenType.CONTINUETK, "CONTINUETK");
        tokenTypeToStr.put(TokenType.PLUS, "PLUS");
        tokenTypeToStr.put(TokenType.MINU, "MINU");
        tokenTypeToStr.put(TokenType.MULT, "MULT");
        tokenTypeToStr.put(TokenType.DIV, "DIV");
        tokenTypeToStr.put(TokenType.MOD, "MOD");
        tokenTypeToStr.put(TokenType.ASSIGN, "ASSIGN");
        tokenTypeToStr.put(TokenType.EQL, "EQL");
        tokenTypeToStr.put(TokenType.NEQ, "NEQ");
        tokenTypeToStr.put(TokenType.LSS, "LSS");
        tokenTypeToStr.put(TokenType.LEQ, "LEQ");
        tokenTypeToStr.put(TokenType.GRE, "GRE");
        tokenTypeToStr.put(TokenType.GEQ, "GEQ");
        tokenTypeToStr.put(TokenType.NOT, "NOT");
        tokenTypeToStr.put(TokenType.AND, "AND");
        tokenTypeToStr.put(TokenType.OR, "OR");
        tokenTypeToStr.put(TokenType.LPARENT, "LPARENT");
        tokenTypeToStr.put(TokenType.RPARENT, "RPARENT");
        tokenTypeToStr.put(TokenType.LBRACK, "LBRACK");
        tokenTypeToStr.put(TokenType.RBRACK, "RBRACK");
        tokenTypeToStr.put(TokenType.LBRACE, "LBRACE");
        tokenTypeToStr.put(TokenType.RBRACE, "RBRACE");
        tokenTypeToStr.put(TokenType.SEMICN, "SEMICN");
        tokenTypeToStr.put(TokenType.COMMA, "COMMA");
        tokenTypeToStr.put(TokenType.INVALID, "INVALID");
    }

    public static void readFile(String filename) {
        try (BufferedReader file = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = file.readLine()) != null) {
                lines.add(line);
            }
        } catch (IOException e) {
            System.err.println("Unable to open file: " + filename);
            System.exit(1);
        }
    }

    public static void outputToken(TokenType type, String value) {
        lexerOut.println(tokenTypeToStr.get(type) + " " + value);
    }

    public static void outputError(int line, ErrorType errorType) {
        errorOut.println((line + 1) + " " + errorType.name().toLowerCase().charAt(0));
    }

    public static boolean isKeyword(String str) {
        return Arrays.asList("const", "int", "char", "void", "if", "else", "while", "for", 
                             "break", "continue", "return", "main", "getint", "getchar", "printf")
                     .contains(str);
    }

    public static TokenType getKeywordToken(String keyword) {
        switch (keyword) {
            case "const": return TokenType.CONSTTK;
            case "int": return TokenType.INTTK;
            case "char": return TokenType.CHARTK;
            case "void": return TokenType.VOIDTK;
            case "if": return TokenType.IFTK;
            case "else": return TokenType.ELSETK;
            case "for": return TokenType.FORTK;
            case "break": return TokenType.BREAKTK;
            case "continue": return TokenType.CONTINUETK;
            case "return": return TokenType.RETURNTK;
            case "main": return TokenType.MAINTK;
            case "getint": return TokenType.GETINTTK;
            case "getchar": return TokenType.GETCHARTK;
            case "printf": return TokenType.PRINTFTK;
            default: return TokenType.INVALID;
        }
    }

    public static void lexerAnalysis() {
        boolean inBlockComment = false;

        for (currentLine = 0; currentLine < lines.size(); ++currentLine) {
            String line = lines.get(currentLine);
            for (int i = 0; i < line.length();) {
                if (Character.isWhitespace(line.charAt(i))) {
                    i++;
                    continue;
                }

                if (!inBlockComment) {
                    if (i + 1 < line.length() && line.charAt(i) == '/' && line.charAt(i + 1) == '/') {
                        break;
                    }
                    if (i + 1 < line.length() && line.charAt(i) == '/' && line.charAt(i + 1) == '*') {
                        inBlockComment = true;
                        i += 2;
                        continue;
                    }
                }

                if (inBlockComment) {
                    while (i + 1 < line.length() && !(line.charAt(i) == '*' && line.charAt(i + 1) == '/')) {
                        i++;
                    }
                    if (i + 1 < line.length() && line.charAt(i) == '*' && line.charAt(i + 1) == '/') {
                        inBlockComment = false;
                        i += 2;
                    } else {
                        break;
                    }
                    continue;
                }

                if (Character.isLetter(line.charAt(i)) || line.charAt(i) == '_') {
                    StringBuilder ident = new StringBuilder();
                    while (i < line.length() && (Character.isLetterOrDigit(line.charAt(i)) || line.charAt(i) == '_')) {
                        ident.append(line.charAt(i++));
                    }
                    if (isKeyword(ident.toString())) {
                        outputToken(getKeywordToken(ident.toString()), ident.toString());
                    } else {
                        outputToken(TokenType.IDENFR, ident.toString());
                    }
                    continue;
                } else if (Character.isDigit(line.charAt(i))) {
                    StringBuilder num = new StringBuilder();
                    while (i < line.length() && Character.isDigit(line.charAt(i))) {
                        num.append(line.charAt(i++));
                    }
                    outputToken(TokenType.INTCON, num.toString());
                } else if (line.charAt(i) == '"') {
                    StringBuilder strConst = new StringBuilder("\"");
                    i++;
                    while (i < line.length() && line.charAt(i) != '"') {
                        strConst.append(line.charAt(i++));
                    }
                    if (i < line.length() && line.charAt(i) == '"') {
                        strConst.append('"');
                        i++;
                        outputToken(TokenType.STRCON, strConst.toString());
                    } else {
                        outputError(currentLine, ErrorType.INVALID_CHAR);
                    }
                } else if (line.charAt(i) == '\'') {
                    i++;
                    if (i < line.length()) {
                        StringBuilder charValue = new StringBuilder("'");
                        char ch = line.charAt(i);
                        if (ch == '\\') {
                            i++;
                            if (i < line.length()) {
                                switch (line.charAt(i)) {
                                    case 'n': ch = '\n'; charValue.append("\\n"); break;
                                    case '0': ch = '\0'; charValue.append("\\0"); break;
                                    case 't': ch = '\t'; charValue.append("\\t"); break;
                                    case '\'': ch = '\''; charValue.append("\\'"); break;
                                    case '"': ch = '"'; charValue.append("\\\""); break;
                                    case '\\': ch = '\\'; charValue.append("\\\\"); break;
                                    default: outputError(currentLine, ErrorType.INVALID_CHAR); i++; continue;
                                }
                            }
                        } else {
                            charValue.append(ch);
                        }
                        i++;
                        if (i < line.length() && line.charAt(i) == '\'') {
                            i++;
                            charValue.append("'");
                            outputToken(TokenType.CHRCON, charValue.toString());
                        } else {
                            outputError(currentLine, ErrorType.INVALID_CHAR);
                        }
                    } else {
                        outputError(currentLine, ErrorType.INVALID_CHAR);
                    }
                    continue;
                } else {
                    switch (line.charAt(i)) {
                        case '<': if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                            outputToken(TokenType.LEQ, "<=");
                            i += 2;
                        } else {
                            outputToken(TokenType.LSS, "<");
                            i++;
                        } continue;
                        case '>': if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                            outputToken(TokenType.GEQ, ">=");
                            i += 2;
                        } else {
                            outputToken(TokenType.GRE, ">");
                            i++;
                        } continue;
                        case '=': if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                            outputToken(TokenType.EQL, "==");
                            i += 2;
                        } else {
                            outputToken(TokenType.ASSIGN, "=");
                            i++;
                        } continue;
                        case '!': if (i + 1 < line.length() && line.charAt(i + 1) == '=') {
                            outputToken(TokenType.NEQ, "!=");
                            i += 2;
                        } else {
                            outputToken(TokenType.NOT, "!");
                            i++;
                        } continue;
                        case '+': outputToken(TokenType.PLUS, "+"); i++; break;
                        case '-': outputToken(TokenType.MINU, "-"); i++; break;
                        case '*': outputToken(TokenType.MULT, "*"); i++; break;
                        case '/': outputToken(TokenType.DIV, "/"); i++; break;
                        case '%': outputToken(TokenType.MOD, "%"); i++; break;
                        case '(': outputToken(TokenType.LPARENT, "("); i++; break;
                        case ')': outputToken(TokenType.RPARENT, ")"); i++; break;
                        case '{': outputToken(TokenType.LBRACE, "{"); i++; break;
                        case '}': outputToken(TokenType.RBRACE, "}"); i++; break;
                        case '[': outputToken(TokenType.LBRACK, "["); i++; break;
                        case ']': outputToken(TokenType.RBRACK, "]"); i++; break;
                        case ';': outputToken(TokenType.SEMICN, ";"); i++; break;
                        case ',': outputToken(TokenType.COMMA, ","); i++; break;
                        case '&': if (i + 1 < line.length() && line.charAt(i + 1) == '&') {
                            outputToken(TokenType.AND, "&&");
                            i += 2;
                        } else {
                            outputError(currentLine, ErrorType.INVALID_CHAR);
                            i++;
                        } continue;
                        case '|': if (i + 1 < line.length() && line.charAt(i + 1) == '|') {
                            outputToken(TokenType.OR, "||");
                            i += 2;
                        } else {
                            outputError(currentLine, ErrorType.INVALID_CHAR);
                            i++;
                        } continue;
                        default: outputError(currentLine, ErrorType.INVALID_CHAR); i++; continue;
                    }
                }
            }
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        lexerOut = new PrintWriter("lexer.txt");
        errorOut = new PrintWriter("error.txt");

        readFile("testfile.txt");

        lexerAnalysis();

        lexerOut.close();
        errorOut.close();
    }
}
