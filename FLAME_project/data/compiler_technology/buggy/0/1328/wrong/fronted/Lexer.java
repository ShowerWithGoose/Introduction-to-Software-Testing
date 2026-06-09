package fronted;

import error.ErrorHandler;
import error.ErrorType;
import error.Error;
import fronted.token.Token;
import fronted.token.TokenType;
import utils.MyIO;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public class Lexer {
    private static Lexer lexer = new Lexer();

    public static Lexer getInstance() {
        return lexer;
    }

    private ArrayList<Token> tokens = new ArrayList<>();

    // 建立保留字到TokenType的一一映射
    private Map<String, TokenType> keywords = new HashMap<String, TokenType>() {{
        put("main", TokenType.MAINTK);
        put("const", TokenType.CONSTTK);
        put("int", TokenType.INTTK);
        put("char", TokenType.CHARTK);
        put("break", TokenType.BREAKTK);
        put("continue", TokenType.CONTINUETK);
        put("if", TokenType.IFTK);
        put("else", TokenType.ELSETK);
        put("for", TokenType.FORTK);
        put("getint", TokenType.GETINTTK);
        put("getchar", TokenType.GETCHARTK);
        put("printf", TokenType.PRINTFTK);
        put("return", TokenType.RETURNTK);
        put("void", TokenType.VOIDTK);
    }};

    public void fsa(String input) {
        int lineNum = 1;
        int len = input.length();

        // 进入自动机
        // WARN: 每次集训循环前会i++，调整游标时注意
        for (int i = 0; i < len; i++) {
            char c = input.charAt(i);
            char next = i + 1 < len ? input.charAt(i + 1) : '\0';
            // 判断换行
            // WARN: 注意，后续如果要涉及游标移动，最好判断==而不是！=，不然容易漏掉对\n的检测
            if (c == '\n') {
                lineNum++;
            } else if (c == '_' || Character.isLetter(c)) { // 标识符或保留字
                String s = "";
                for (int j = i; j < len; j++) {
                    char cc = input.charAt(j);
                    if (cc == '_' || Character.isLetterOrDigit(cc)) {
                        s += cc;
                    } else {
                        i = j - 1;
                        break;
                    }
                }
                tokens.add(new Token(keywords.getOrDefault(s, TokenType.IDENFR), lineNum, s));
            } else if (Character.isDigit(c)) { // 数字
                String s = "";
                for (int j = i; j < len; j++) {
                    char cc = input.charAt(j);
                    if (Character.isDigit(cc)) {
                        s += cc;
                    } else {
                        i = j - 1;
                        break;
                    }
                }
                tokens.add(new Token(TokenType.INTCON, lineNum, s));
            } else if (c == '\"') { // 字符串
                // BUG: 字符串前后引号是一样的，所以这里需要初始化一个引号再后移一位判断，不然会直接跳出
                String s = "\"";
                for (int j = i + 1; j < len; j++) {
                    char cc = input.charAt(j);
                    if (cc != '\"') {
                        s += cc;
                    } else {
                        i = j;
                        s += "\"";
                        break;
                    }
                }
                tokens.add(new Token(TokenType.STRCON, lineNum, s));
            } else if (c == '!') {
                if (next == '=') { // !=
                    tokens.add(new Token(TokenType.NEQ, lineNum, "!="));
                    i++;
                } else
                    tokens.add(new Token(TokenType.NOT, lineNum, "!"));
            } else if (c == '<') {
                if (next == '=') { // <=
                    tokens.add(new Token(TokenType.LEQ, lineNum, "<="));
                    i++;
                } else
                    tokens.add(new Token(TokenType.LSS, lineNum, "<"));
            } else if (c == '>') {
                if (next == '=') { // >=
                    tokens.add(new Token(TokenType.GEQ, lineNum, ">="));
                    i++;
                } else
                    tokens.add(new Token(TokenType.GRE, lineNum, ">"));
            } else if (c == '=') {
                if (next == '=') { // ==
                    tokens.add(new Token(TokenType.EQL, lineNum, "=="));
                    i++;
                } else
                    tokens.add(new Token(TokenType.ASSIGN, lineNum, "="));
            } else if (c == '&') {
                if (next == '&') { // &&
                    tokens.add(new Token(TokenType.AND, lineNum, "&&"));
                    i++;
                } else
                    ErrorHandler.getInstance().addError(new Error(ErrorType.a, lineNum));
            } else if (c == '|') {
                if (next == '|') {  // ||
                    tokens.add(new Token(TokenType.OR, lineNum, "||"));
                    i++;
                } else
                    ErrorHandler.getInstance().addError(new Error(ErrorType.a, lineNum));
            } else if (c == '/') {
                if (next == '/') { // 单行注释
                    int j = input.indexOf('\n', i + 2);
                    if (j == -1) {
                        j = len;
                    }
                    i = j - 1;
                } else if (next == '*') { // 多行注释
                    for (int j = i + 2; j < len; j++) {
                        // BUG: 不要忘记换行符的判断！！
                        char cc = input.charAt(j);
                        if (cc == '\n') {
                            lineNum++;
                        } else if (cc == '*' && input.charAt(j + 1) == '/') {
                            i = j + 1;
                            break;
                        }
                    }
                } else
                    tokens.add(new Token(TokenType.DIV, lineNum, "/"));
            } else if (c == '+')
                tokens.add(new Token(TokenType.PLUS, lineNum, "+"));
            else if (c == '-')
                tokens.add(new Token(TokenType.MINU, lineNum, "-"));
            else if (c == '*')
                tokens.add(new Token(TokenType.MULT, lineNum, "*"));
            else if (c == '%')
                tokens.add(new Token(TokenType.MOD, lineNum, "%"));
            else if (c == ';')
                tokens.add(new Token(TokenType.SEMICN, lineNum, ";"));
            else if (c == ',')
                tokens.add(new Token(TokenType.COMMA, lineNum, ","));
            else if (c == '(')
                tokens.add(new Token(TokenType.LPARENT, lineNum, "("));
            else if (c == ')')
                tokens.add(new Token(TokenType.RPARENT, lineNum, ")"));
            else if (c == '[')
                tokens.add(new Token(TokenType.LBRACK, lineNum, "["));
            else if (c == ']')
                tokens.add(new Token(TokenType.RBRACK, lineNum, "]"));
            else if (c == '{')
                tokens.add(new Token(TokenType.LBRACE, lineNum, "{"));
            else if (c == '}')
                tokens.add(new Token(TokenType.RBRACE, lineNum, "}"));
        }
    }

    public void printTokens() {
        for (Token token : tokens) {
            MyIO.writeToken(token.toString());
        }
    }
}
