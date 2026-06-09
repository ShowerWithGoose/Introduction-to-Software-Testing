package frontend;

import Error.CompileException;
import Error.ErrorType;
import Error.ErrorHandler;
import Token.Token;
import Utils.IO;

import java.util.*;

/**
 * @author:
 * TODO
 * 2024/9/21 9:12
 */
//    单例模式
public class Lexer {
    //    主要成员变量
    private String source;
    private int curPos;
    private String token;
    private LexType lexType;
    private long number;
    private int lineNumber;
    private static final Map<String, LexType> reserveWords;
    private List<Token> tokens = new ArrayList<>();

    private boolean isComment;

    static {
        Map<String, LexType> hashMap = new HashMap<>();
        hashMap.put("main", LexType.MAINTK);
        hashMap.put("const", LexType.CONSTTK);
        hashMap.put("int", LexType.INTTK);
        hashMap.put("char", LexType.CHARTK);
        hashMap.put("break", LexType.BREAKTK);
        hashMap.put("continue", LexType.CONTINUETK);
        hashMap.put("if", LexType.IFTK);
        hashMap.put("else", LexType.ELSETK);
        hashMap.put("for", LexType.FORTK);
        hashMap.put("getint", LexType.GETINTTK);
        hashMap.put("getchar", LexType.GETCHARTK);
        hashMap.put("printf", LexType.PRINTFTK);
        hashMap.put("return", LexType.RETURNTK);
        hashMap.put("void", LexType.VOIDTK);
        reserveWords = Collections.unmodifiableMap(hashMap);
    }

    //    单例模式
    private static Lexer instance = new Lexer();

    private Lexer() {
    }

    public static Lexer getInstance() {
        return instance;
    }

    //    初始化
    public void init(int lineNumber, String line) {
        this.source = line;
        this.curPos = 0;
        this.token = "";
        this.lexType = null;
        this.number = 0;
        this.lineNumber = lineNumber;
    }

    //    lexer分析函数，执行取next和分析
    public void Lexer_main() {
        while (curPos < source.length()) {
            next();
            if (getLexType() != null) {
                tokens.add(new Token(getLexType(), getToken(), lineNumber));
            }
        }
    }


    public void next() {
        char c = source.charAt(curPos++);

        token = "";
        lexType = null;
        number = 0;

        if (isComment) {
            curPos -= 1;//maybe c='*'
            while (curPos < source.length()) {
                if (source.charAt(curPos++) == '*') {
                    if (curPos < source.length() && source.charAt(curPos) == '/') {
                        isComment = false;
                        curPos += 1;
                        return;
                    }
                }
            }
            return;
        }
        if (isNonDigit(c)) {
            token += c;
            while (curPos < source.length() && (isNonDigit(source.charAt(curPos)) || Character.isDigit(source.charAt(curPos)))) {
                c = source.charAt(curPos++);
                token += c;
            }
            reserve();
        } else if (Character.isDigit(c)) {
            token += c;
            while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
                c = source.charAt(curPos++);
                token += c;
            }
            lexType = LexType.INTCON;
//            这里存疑,number是用来存数字的真实值的,范围不确定
            number = Long.parseLong(token);
        } else {
            switch (c) {
//                这里的两个会throw a类错误
                case '&':
                    token += c;
                    if (curPos < source.length() && source.charAt(curPos) == '&') {
                        c = source.charAt(curPos++);
                        token += c;
                        lexType = LexType.AND;
                    } else {
                        token += c;
                        lexType = LexType.AND;
                        ErrorHandler.getInstance().add(new CompileException(lineNumber, ErrorType.a));
                    }
                    break;
                case '|':
                    token += c;
                    if (curPos < source.length() && source.charAt(curPos) == '|') {
                        c = source.charAt(curPos++);
                        token += c;
                        lexType = LexType.OR;
                    } else {
                        token += c;
                        lexType = LexType.OR;
                        ErrorHandler.getInstance().add(new CompileException(lineNumber, ErrorType.a));
                    }
                    break;

//                这里都是可能两个结果的,!=,<=,>=,==
                case '!':
                    token += c;
                    if (curPos < source.length() && source.charAt(curPos) == '=') {
                        c = source.charAt(curPos++);
                        token += c;
                        lexType = LexType.NEQ;
                    } else {
                        lexType = LexType.NOT;
                    }
                    break;
                case '<':
                    token += c;
                    if (curPos < source.length() && source.charAt(curPos) == '=') {
                        c = source.charAt(curPos++);
                        token += c;
                        lexType = LexType.LEQ;
                    } else {
                        lexType = LexType.LSS;
                    }
                    break;
                case '>':
                    token += c;
                    if (curPos < source.length() && source.charAt(curPos) == '=') {
                        c = source.charAt(curPos++);
                        token += c;
                        lexType = LexType.GEQ;
                    } else {
                        lexType = LexType.GRE;
                    }
                    break;
                case '=':
                    token += c;
                    if (curPos < source.length() && source.charAt(curPos) == '=') {
                        c = source.charAt(curPos++);
                        token += c;
                        lexType = LexType.EQL;
                    } else {
                        lexType = LexType.ASSIGN;
                    }
                    break;
                case '+':
                    token += c;
                    lexType = LexType.PLUS;
                    break;
                case '-':
                    token += c;
                    lexType = LexType.MINU;
                    break;
                case '*':
                    token += c;
                    lexType = LexType.MULT;
                    break;
                case '%':
                    token += c;
                    lexType = LexType.MOD;
                    break;
                case ';':
                    token += c;
                    lexType = LexType.SEMICN;
                    break;
                case ',':
                    token += c;
                    lexType = LexType.COMMA;
                    break;
                case '(':
                    token += c;
                    lexType = LexType.LPARENT;
                    break;
                case ')':
                    token += c;
                    lexType = LexType.RPARENT;
                    break;
                case '[':
                    token += c;
                    lexType = LexType.LBRACK;
                    break;
                case ']':
                    token += c;
                    lexType = LexType.RBRACK;
                    break;
                case '{':
                    token += c;
                    lexType = LexType.LBRACE;
                    break;
                case '}':
                    token += c;
                    lexType = LexType.RBRACE;
                    break;

//                处理注释
                case '/':
//                    单行注释,直接推到头
                    if (curPos < source.length() && source.charAt(curPos) == '/') {
                        curPos = source.length();
                        return;
                    }
//                    多行注释,打上tag
                    if (curPos < source.length() && source.charAt(curPos) == '*') {
                        isComment = true;
                        curPos += 1;
                        while (curPos < source.length()) {
                            if (source.charAt(curPos++) == '*') {
                                if (curPos < source.length() && source.charAt(curPos) == '/') {
                                    isComment = false;
                                    curPos += 1;
                                    return;
                                }
                            }
                        }
                        return;
                    }
                    token += c;
                    lexType = LexType.DIV;
                    break;

//                字符串常量
                case '"':
                    token += c;
                    lexType = LexType.STRCON;
                    while (curPos < source.length()) {
                        token += source.charAt(curPos++);
                        if (source.charAt(curPos - 1) == '"' && (curPos - 2 >= 0 && source.charAt(curPos - 2) != '\\'))
                            break;
                    }
                    break;

//                字符常量
                case '\'':
                    token += c;
                    lexType = LexType.CHRCON;
//                    按理来说就是'一个字符',这一个字符可能是转义字符,最多是两个字符
                    if (curPos < source.length()) {
                        token += source.charAt(curPos++);
                        if (source.charAt(curPos - 1) == '\\') {
                            token += source.charAt(curPos++);
                        }
                    }

                    if (curPos < source.length() && source.charAt(curPos) == '\'') {
                        token += source.charAt(curPos++);
                    } else {
                        ErrorHandler.getInstance().print(new CompileException(lineNumber, ErrorType.CHRCONLEN));
                    }
                    break;
                default:
                    if (c == ' ' || c == '\t' || c == '\n') {
                        return;
                    }
            }
        }

    }

    public String getToken() {
        return token;
    }

    public LexType getLexType() {
        return lexType;
    }

    public boolean isNonDigit(char c) {
        return (Character.isLetter(c) || c == '_');
    }

    public void reserve() {
        lexType = reserveWords.getOrDefault(token, LexType.IDENFR);
    }

    //    打印函数
    public void Lexer_print() {
        for (Token token : tokens) {
            IO.lexer_output(token.toString());
        }
    }

    //    给parser传tokens
    public List<Token> getTokens() {
        return tokens;
    }
}
