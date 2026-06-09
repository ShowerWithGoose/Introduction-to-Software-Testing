package frontend;

import token.Token;
import token.TokenType;
import token.Error;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lexer {
    private static final Lexer instance = new Lexer();

    public static Lexer getInstance() {
        return instance;
    }

    private List<Token> tokens = new ArrayList<>();
    private List<Error> errors = new ArrayList<>();

    private Map<String, TokenType> keywords = new HashMap<String, TokenType>() {{
        put("main", TokenType.MAINTK);
        put("const", TokenType.CONSTTK);
        put("int", TokenType.INTTK);
        put("char", TokenType.CHARTK);
        put("void", TokenType.VOIDTK);
        put("if", TokenType.IFTK);
        put("else", TokenType.ELSETK);
        put("for", TokenType.FORTK);
        put("break", TokenType.BREAKTK);
        put("continue", TokenType.CONTINUETK);
        put("return", TokenType.RETURNTK);
        put("getint", TokenType.GETINTTK);
        put("getchar", TokenType.GETCHARTK);
        put("printf", TokenType.PRINTFTK);
    }};

    private static final Pattern tokenPatterns = Pattern.compile(
            "(?<IDENFR>[a-zA-Z_][a-zA-Z0-9_]*)" +
                    "|(?<INTCON>\\d+)" +
                    "|(?<STRCON>\"[^\"]*\")" +
                    "|(?<CHRCON>'(\\\\'|\\\\0|\\\\t|\\\\n|\\\\r|\\\\b|\\\\f|\\\\\\\\|[^'])')" +
                    "|(?<AND>&&)" +
                    "|(?<OR>\\|\\|)" +
                    "|(?<EQL>==)" +
                    "|(?<NEQ>!=)" +
                    "|(?<LEQ><=)" +
                    "|(?<GEQ>>=)" +
                    "|(?<NOT>!)" +
                    "|(?<MULT>\\*)" +
                    "|(?<DIV>/)" +
                    "|(?<MOD>%)" +
                    "|(?<PLUS>\\+)" +
                    "|(?<MINU>-)" +
                    "|(?<ASSIGN>=)" +
                    "|(?<LSS><)" +
                    "|(?<GRE>>)" +
                    "|(?<SEMICN>;)" +
                    "|(?<COMMA>,)" +
                    "|(?<LPARENT>\\()" +
                    "|(?<RPARENT>\\))" +
                    "|(?<LBRACK>\\[)" +
                    "|(?<RBRACK>])" +
                    "|(?<LBRACE>\\{)" +
                    "|(?<RBRACE>})" +
                    "|(?<ILLEGAL>[|&])"
    );

    public List<Token> getTokens() {
        return tokens;
    }

    public List<Error> getErrors() {
        return errors;
    }

    public void analyze(String content) {
        StringBuilder cleanedContent = new StringBuilder();
        boolean inSingleLineComment = false;
        boolean inMultiLineComment = false;

        for (int i = 0; i < content.length(); i++) {
            if (inSingleLineComment) {
                if (content.charAt(i) == '\n') {
                    inSingleLineComment = false;
                    cleanedContent.append(content.charAt(i));
                }
            } else if (inMultiLineComment) {
                if (content.charAt(i) == '*'
                        && i + 1 < content.length()
                        && content.charAt(i + 1) == '/') {
                    inMultiLineComment = false;
                    i++;
                }
            } else {
                if (content.charAt(i) == '/' && i + 1 < content.length()) {
                    if (content.charAt(i + 1) == '/') {
                        inSingleLineComment = true;
                        i++;
                    } else if (content.charAt(i + 1) == '*') {
                        inMultiLineComment = true;
                        i++;
                    } else {
                        cleanedContent.append(content.charAt(i));
                    }
                } else {
                    cleanedContent.append(content.charAt(i));
                }
            }
        }

        content = cleanedContent.toString();

        int lineNumber = 1;
        Matcher matcher = tokenPatterns.matcher(content);
        int lastMatchEnd = 0;

        while (matcher.find()) {
            for (int i = lastMatchEnd; i < matcher.start(); i++) {
                if (i < content.length() && content.charAt(i) == '\n') {
                    lineNumber++;
                }
            }
            lastMatchEnd = matcher.end();

            String token = matcher.group();
            TokenType type = null;

            if (matcher.group("IDENFR") != null) {
                type = keywords.getOrDefault(token, TokenType.IDENFR);
            } else if (matcher.group("INTCON") != null) {
                type = TokenType.INTCON;
            } else if (matcher.group("STRCON") != null) {
                type = TokenType.STRCON;
            } else if (matcher.group("CHRCON") != null) {
                type = TokenType.CHRCON;
            } else if (matcher.group("AND") != null) {
                type = TokenType.AND;
            } else if (matcher.group("OR") != null) {
                type = TokenType.OR;
            } else if (matcher.group("NOT") != null) {
                type = TokenType.NOT;
            } else if (matcher.group("MULT") != null) {
                type = TokenType.MULT;
            } else if (matcher.group("DIV") != null) {
                type = TokenType.DIV;
            } else if (matcher.group("MOD") != null) {
                type = TokenType.MOD;
            } else if (matcher.group("PLUS") != null) {
                type = TokenType.PLUS;
            } else if (matcher.group("MINU") != null) {
                type = TokenType.MINU;
            } else if (matcher.group("ASSIGN") != null) {
                type = TokenType.ASSIGN;
            } else if (matcher.group("EQL") != null) {
                type = TokenType.EQL;
            } else if (matcher.group("NEQ") != null) {
                type = TokenType.NEQ;
            } else if (matcher.group("LSS") != null) {
                type = TokenType.LSS;
            } else if (matcher.group("LEQ") != null) {
                type = TokenType.LEQ;
            } else if (matcher.group("GRE") != null) {
                type = TokenType.GRE;
            } else if (matcher.group("GEQ") != null) {
                type = TokenType.GEQ;
            } else if (matcher.group("SEMICN") != null) {
                type = TokenType.SEMICN;
            } else if (matcher.group("COMMA") != null) {
                type = TokenType.COMMA;
            } else if (matcher.group("LPARENT") != null) {
                type = TokenType.LPARENT;
            } else if (matcher.group("RPARENT") != null) {
                type = TokenType.RPARENT;
            } else if (matcher.group("LBRACK") != null) {
                type = TokenType.LBRACK;
            } else if (matcher.group("RBRACK") != null) {
                type = TokenType.RBRACK;
            } else if (matcher.group("LBRACE") != null) {
                type = TokenType.LBRACE;
            } else if (matcher.group("RBRACE") != null) {
                type = TokenType.RBRACE;
            } else if (matcher.group("ILLEGAL") != null) {
                errors.add(new Error(lineNumber, " a"));
            }

            if (type != null) {
                tokens.add(new Token(type, lineNumber, token));
            }
        }
    }

    public void printLexAns() {
        if (!errors.isEmpty()) {
            return;
        }
        for (Token token : tokens) {
            System.out.println(token.getType() + " " + token.getContent());
        }
    }

    public void printErrors() {
        for (Error error : errors) {
            System.err.println(error.getLineNumber() + error.getErrorType());
        }
    }
}