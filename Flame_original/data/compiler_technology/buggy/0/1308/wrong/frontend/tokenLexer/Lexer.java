package frontend.tokenLexer;

import error.ErrorType;

import java.util.*;
import java.util.regex.Pattern;

public class Lexer {
    private String codeFile;
    private int pos;
    public int line;
    private int fileLength;
    private static String symbolsHead = "!&|+-*/%<>=;,()[]{}";
    private static String singleSymbol = "!&|+-*/%<>=;,()[]{}";
    private static Set<String> doubleSymbol = new HashSet<>(List.of("&&", "||", "<=", ">=", "==", "!="));
    private static Pattern patternIdentHead = Pattern.compile("[a-zA-Z_]");
    private static Pattern patternIdentAll = Pattern.compile("[0-9a-zA-Z_]");
    private static Set<String> specialStringSet = new HashSet<>(List.of("main", "const", "int", "char", "break", "continue", "if", "else", "for", "getint", "getchar", "printf", "return", "void"));

    public Lexer(Scanner scanner) {
        this.codeFile = scannerToCodeFile(scanner);
        pos = 0;
        line = 1;
        fileLength = this.codeFile.length();
    }

    private String scannerToCodeFile(Scanner scanner) {
        StringBuilder sb = new StringBuilder();
        while (scanner.hasNextLine()) {
            sb.append(scanner.nextLine()).append("\n");
        }
        return sb.toString();
    }

    public Token getNextToken() {
        while (pos < fileLength) {
            if (codeFile.startsWith("//", pos) || codeFile.startsWith("/*", pos)) {
                skipAnnotation();
                continue;
            }
            char c = codeFile.charAt(pos);
            switch (c) {
                case '\n':
                    pos++;
                    line++;
                    continue;
                case ' ':
                    pos++;
                    continue;
                case '"':
                    return nextStringConst();
                case '\'':
                    return nextCharConst();
            }
            if (isDigital()) {
                return nextDigital();
            } else if (isSymbol()) {
                return nextSymbol();
            } else if (isSpecialStringNotIdent()) {
                return nextSpecialString();
            } else if (isIdent()) {
                return nextIdent();
            }
        }
        return null;
    }

    private void skipAnnotation() {
        pos++;
        if (codeFile.charAt(pos) == '/') {
            pos = codeFile.indexOf('\n', pos) + 1;
            line++;
        } else {
            while (!codeFile.startsWith("*/", pos)) {
                if (codeFile.charAt(pos) == '\n') {
                    line++;
                }
                pos++;
            }
            pos += 2;
        }
    }

    private boolean isSpecialStringNotIdent() {
        Optional<String> optionalS = specialStringSet.stream().filter(string -> codeFile.startsWith(string, pos)).findFirst();
        //System.out.println(codeFile.substring(pos, pos + 4));
        if (optionalS.isEmpty()) {
            return false;
        }
        int len = optionalS.get().length();
        if (patternIdentAll.matcher(codeFile.substring(pos + len, pos + len + 1)).matches()) { //判断是否为Ident
            return false;
        }
        return true;
    }

    private boolean isDigital() {
        return codeFile.charAt(pos) >= '0' && codeFile.charAt(pos) <= '9';
    }

    private boolean isSymbol() {
        return symbolsHead.contains(codeFile.substring(pos, pos + 1));
    }

    private boolean isIdent() {
        return patternIdentHead.matcher(codeFile.substring(pos, pos + 1)).matches();
    }

    private Token nextStringConst() {
        int lastPos = pos;
        pos = codeFile.indexOf('"', pos + 1);
        while (codeFile.charAt(pos - 1) == '\\') {
            pos = codeFile.indexOf('"', pos + 1);
        }
        pos++;
        return new Token(codeFile.substring(lastPos, pos), TokenType.STRCON, line, ErrorType.no);
    }

    private Token nextCharConst() {
        int lastPos = pos;
        pos = codeFile.charAt(pos + 1) == '\\' ? pos + 4 : pos + 3;
        return new Token(codeFile.substring(lastPos, pos), TokenType.CHRCON, line, ErrorType.no);
    }

    private Token nextSymbol() {
        Optional<String> optionalS = doubleSymbol.stream().filter(string -> codeFile.startsWith(string, pos)).findFirst();
        if (optionalS.isPresent()) {
            String string = codeFile.substring(pos, pos + 2);
            pos += 2;
            return new Token(string, strToTokenType(string), line, ErrorType.no);
        }
        String string = codeFile.substring(pos, pos + 1);
        pos++;
        if (string.equals("|")) {
            return new Token(string, TokenType.OR, line, ErrorType.a);
        }
        if (string.equals("&")) {
            return new Token(string, TokenType.AND, line, ErrorType.a);
        }
        return new Token(string, strToTokenType(string), line, ErrorType.no);
    }

    private Token nextSpecialString() {
        String specialString = specialStringSet.stream().filter(string -> codeFile.startsWith(string, pos)).findFirst().get();
        pos = pos + specialString.length();
        return new Token(specialString, strToTokenType(specialString), line, ErrorType.no);
    }

    private Token nextIdent() {
        int lastPos = pos;
        StringBuilder sb = new StringBuilder();
        while (patternIdentAll.matcher(codeFile.substring(pos, pos + 1)).matches()) {
            sb.append(codeFile.charAt(pos));
            pos++;
        }
        return new Token(sb.toString(), TokenType.IDENFR, line, ErrorType.no);
    }

    private Token nextDigital() {
        int lastPos = pos;
        StringBuilder sb = new StringBuilder();
        while (patternIdentAll.matcher(codeFile.substring(pos, pos + 1)).matches()) {
            sb.append(codeFile.charAt(pos));
            pos++;
        }
        return new Token(sb.toString(), TokenType.INTCON, line, ErrorType.no);
    }

    private TokenType strToTokenType(String string) {
        switch (string) {
            case "main":
                return TokenType.MAINTK;
            case "const":
                return TokenType.CONSTTK;
            case "int":
                return TokenType.INTTK;
            case "char":
                return TokenType.CHARTK;
            case "break":
                return TokenType.BREAKTK;
            case "continue":
                return TokenType.CONTINUETK;
            case "if":
                return TokenType.IFTK;
            case "else":
                return TokenType.ELSETK;
            case "!":
                return TokenType.NOT;
            case "&&":
                return TokenType.AND;
            case "||":
                return TokenType.OR;
            case "for":
                return TokenType.FORTK;
            case "getint":
                return TokenType.GETINTTK;
            case "getchar":
                return TokenType.GETCHARTK;
            case "printf":
                return TokenType.PRINTFTK;
            case "return":
                return TokenType.RETURNTK;
            case "+":
                return TokenType.PLUS;
            case "-":
                return TokenType.MINU;
            case "void":
                return TokenType.VOIDTK;
            case "*":
                return TokenType.MULT;
            case "/":
                return TokenType.DIV;
            case "%":
                return TokenType.MOD;
            case "<":
                return TokenType.LSS;
            case "<=":
                return TokenType.LEQ;
            case ">":
                return TokenType.GRE;
            case ">=":
                return TokenType.GEQ;
            case "==":
                return TokenType.EQL;
            case "!=":
                return TokenType.NEQ;
            case "=":
                return TokenType.ASSIGN;
            case ";":
                return TokenType.SEMICN;
            case ",":
                return TokenType.COMMA;
            case "(":
                return TokenType.LPARENT;
            case ")":
                return TokenType.RPARENT;
            case "[":
                return TokenType.LBRACK;
            case "]":
                return TokenType.RBRACK;
            case "{":
                return TokenType.LBRACE;
            case "}":
                return TokenType.RBRACE;
        }
        return null;
    }
}
