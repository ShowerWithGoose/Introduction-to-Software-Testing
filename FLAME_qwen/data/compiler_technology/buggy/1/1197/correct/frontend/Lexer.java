package frontend;

import config.Config;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Consumer;
import java.util.function.Predicate;

public class Lexer {
    public static final ArrayList<String> reserveWords = new ArrayList<>();
    public static final HashMap<Predicate<Character>, Consumer<Lexer>> funcList = new HashMap<>();
    public static final Lexer INSTANCE = new Lexer();
    private String source;
    private int curPos;
    private String token;
    private LexType lexType;
    private int lineNum;
    private BigInteger number;
    private boolean error;
    private ArrayList<ErrorLog> errorList;
    private ArrayList<Token> tokenList;
    private int curToken;
    private Lexer() {

    }

    public boolean init(String source) {
        this.source = source;
        curPos = 0;
        lineNum = 1;
        curToken = -1;
        error = false;
        errorList = new ArrayList<>();
        tokenList = new ArrayList<>();
        return next();
    }

    static {
        funcList.put((c) -> Character.isLetter(c) || c == '_', Lexer::getIdent);
        funcList.put(Character::isDigit, Lexer::getIntCon);
        funcList.put((c) -> c == '\'', Lexer::getChar);
        funcList.put((c) -> c == '\"', Lexer::getStr);
        funcList.put((c) -> c == '/', Lexer::getDivOrComment);
        funcList.put((c) -> c == '!', (o) -> o.getWithEq(LexType.NOT, LexType.NEQ));
        funcList.put((c) -> c == '<', (o) -> o.getWithEq(LexType.LSS, LexType.LEQ));
        funcList.put((c) -> c == '>', (o) -> o.getWithEq(LexType.GRE, LexType.GEQ));
        funcList.put((c) -> c == '=', (o) -> o.getWithEq(LexType.ASSIGN, LexType.EQL));
        funcList.put((c) -> c == '&', (o) -> o.getDouble(LexType.AND));
        funcList.put((c) -> c == '|', (o) -> o.getDouble(LexType.OR));
        funcList.put((c) -> c == '+', (o) -> o.getOne(LexType.PLUS));
        funcList.put((c) -> c == '-', (o) -> o.getOne(LexType.MINU));
        funcList.put((c) -> c == '*', (o) -> o.getOne(LexType.MULT));
        funcList.put((c) -> c == '%', (o) -> o.getOne(LexType.MOD));
        funcList.put((c) -> c == ';', (o) -> o.getOne(LexType.SEMICN));
        funcList.put((c) -> c == ',', (o) -> o.getOne(LexType.COMMA));
        funcList.put((c) -> c == '(', (o) -> o.getOne(LexType.LPARENT));
        funcList.put((c) -> c == ')', (o) -> o.getOne(LexType.RPARENT));
        funcList.put((c) -> c == '[', (o) -> o.getOne(LexType.LBRACK));
        funcList.put((c) -> c == ']', (o) -> o.getOne(LexType.RBRACK));
        funcList.put((c) -> c == '{', (o) -> o.getOne(LexType.LBRACE));
        funcList.put((c) -> c == '}', (o) -> o.getOne(LexType.RBRACE));
    }

    private void getIdent() {
        ++curPos;
        while (curPos < source.length() &&
                (Character.isLetterOrDigit(source.charAt(curPos)) ||
                        source.charAt(curPos) == '_')) {
            token += source.charAt(curPos);
            ++curPos;
        }
        if (reserveWords.contains(token)) {
            lexType = Enum.valueOf(LexType.class, token.toUpperCase() + "TK");
        } else {
            lexType = LexType.IDENFR;
        }
    }

    private void getIntCon() {
        ++curPos;
        while (curPos < source.length() && Character.isDigit(source.charAt(curPos))) {
            token += source.charAt(curPos);
            ++curPos;
        }
        lexType = LexType.INTCON;
        number = new BigInteger(token);
    }

    private void getChar() {
        lexType = LexType.CHRCON;
        ++curPos;
        if (curPos >= source.length()) {
            processError(ErrorType.b);
            return;
        }
        token += source.charAt(curPos);
        if (source.charAt(curPos) == '\\') {
            ++curPos;
            if (curPos >= source.length()) {
                processError(ErrorType.b);
                return;
            } else {
                token += source.charAt(curPos);
                ++curPos;
            }
        } else {
            if (source.charAt(curPos) != '\'') {
                ++curPos;
            } else {
                token += source.charAt(curPos);
                ++curPos;
                return;
            }
        }
        if (curPos >= source.length() || source.charAt(curPos) != '\'') {
            processError(ErrorType.b);
            ++curPos;
            while (curPos < source.length() && source.charAt(curPos) != '\'') {
                token += source.charAt(curPos);
                ++curPos;
            }
        } else {
            token += source.charAt(curPos);
            ++curPos;
        }
    }

    private void getStr() {
        lexType = LexType.STRCON;
        ++curPos;
        while (curPos < source.length() && source.charAt(curPos) != '\"') {
            token += source.charAt(curPos);
            ++curPos;
        }
        if (curPos < source.length()) {
            token += '\"';
            ++curPos;
        } else {
            processError(ErrorType.b);
        }
    }

    private void getOne(LexType lexType) {
        this.lexType = lexType;
        ++curPos;
    }

    private void getDouble(LexType lexType) {
        final char chr = source.charAt(curPos);
        this.lexType = lexType;
        ++curPos;
        if (curPos < source.length() && source.charAt(curPos) == chr) {
            token += chr;
            ++curPos;
        } else {
            processError(ErrorType.a);
        }
    }

    private void getWithEq(LexType withoutEq, LexType withEq) {
        ++curPos;
        if (curPos < source.length() && source.charAt(curPos) == '=') {
            token += '=';
            ++curPos;
            lexType = withEq;
        } else {
            lexType = withoutEq;
        }
    }

    private void getDivOrComment() {
        ++curPos;
        if (curPos >= source.length() ||
                (source.charAt(curPos) != '/' && source.charAt(curPos) != '*')) {
            lexType = LexType.DIV;
        } else {
            lexType = LexType.COMMENT;
            if (source.charAt(curPos) == '/') {
                token += '/';
                ++curPos;
                while (curPos < source.length() && source.charAt(curPos) != '\n') {
                    token += source.charAt(curPos);
                    ++curPos;
                }
                if (curPos < source.length()) {
                    token += source.charAt(curPos);
                    ++curPos;
                    ++lineNum;
                }
            } else {
                token += '*';
                ++curPos;
                while (curPos < source.length()) {
                    while (curPos < source.length() && source.charAt(curPos) != '*') {
                        token += source.charAt(curPos);
                        if (source.charAt(curPos) == '\n') {
                            ++lineNum;
                        }
                        ++curPos;
                    }
                    while (curPos < source.length() && source.charAt(curPos) == '*') {
                        token += source.charAt(curPos);
                        ++curPos;
                    }
                    if (curPos < source.length() && source.charAt(curPos) == '/') {
                        token += source.charAt(curPos);
                        break;
                    }
                }
                if (curPos >= source.length()) {
                    processError(ErrorType.b);
                    return;
                }
                ++curPos;
            }
        }
    }

    private void removeWhite() {
        while (curPos < source.length() && Character.isWhitespace(source.charAt(curPos))) {
            if (source.charAt(curPos) == '\n') {
                ++lineNum;
            }
            ++curPos;
        }
    }

    public boolean next() {
        curToken++;
        if (curToken < tokenList.size()) {
            return true;
        }
        removeWhite();
        if (curPos >= source.length()) {
            return false;
        }
        final char curChar = source.charAt(curPos);
        token = "";
        token += curChar;
        for (Map.Entry<Predicate<Character>, Consumer<Lexer>> func : funcList.entrySet()) {
            if (func.getKey().test(curChar)) {
                func.getValue().accept(this);
                if (lexType == LexType.COMMENT) {
                    curToken--;
                    return next();
                }
                tokenList.add(new Token(lexType,
                        lineNum,
                        lexType == LexType.INTCON ? new BigInteger(token) : null,
                        token));
                return true;
            }
        }
        processError(ErrorType.c);
        curPos++;
        return true;
    }

    public void back() {
        curToken--;
    }

    public void back(int times) {
        curToken -= times;
    }

    public void processError(ErrorType errorType) {
        error = true;
        int lineNum = tokenList.get(curToken - 1).lineNum();
        errorList.add(new ErrorLog(lineNum, errorType));
        if (Config.DEBUG) {
            Config.ERR.println(new ErrorLog(lineNum, errorType));
        }
    }

    static {
        reserveWords.add("main");
        reserveWords.add("const");
        reserveWords.add("int");
        reserveWords.add("char");
        reserveWords.add("break");
        reserveWords.add("continue");
        reserveWords.add("else");
        reserveWords.add("for");
        reserveWords.add("getint");
        reserveWords.add("getchar");
        reserveWords.add("printf");
        reserveWords.add("return");
        reserveWords.add("void");
        reserveWords.add("if");
    }

    public String getValue() {
        return tokenList.get(curToken).value();
    }

    public BigInteger getNumber() {
        return tokenList.get(curToken).number();
    }

    public LexType getLexType() {
        return tokenList.get(curToken).lexType();
    }

    public boolean isError() {
        return error;
    }

    public ArrayList<ErrorLog> getErrorList() {
        return errorList;
    }

    public Token getToken() {
        return tokenList.get(curToken);
    }
}
