package front.lexer;

import fault.Fault;

import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 词法分析类
 */
public class Lexer {
    /**
     * 保留字 map
     */
    private Map<String, TokenType> keywordMap = new HashMap<String, TokenType>();
    /**
     * 输入流封装的 reader
     */
    private FileReader fileReader;
    /**
     * 获取 Fault 单例
     */
    private Fault fault = Fault.getFault();
    /**
     * 存储读入的字符
     */
    private char ch;
    /**
     * 记录读入的 token
     */
    private String token;
    /**
     * 记录转换后的 int 常量
     */
    private long intConst;
    /**
     * 记录 string 常量
     */
    private String stringConst;
    /**
     * 记录 ch 常量
     */
    private char charConst;
    /**
     * 记录读入的 token 类型
     */
    private TokenType tokenType;
    /**
     * 行计数器
     */
    private int line = 1;
    /**
     * 记录处理的所有 token
     */
    private List<Token> tokenList = new ArrayList<>();

    /**
     * Lexer 构造方法，初始化保留字 map
     *
     * @param fileReader 输入流封装的 reader
     */
    private Lexer(FileReader fileReader) {
        this.fileReader = fileReader;
        keywordMap.put("main", TokenType.MAINTK);
        keywordMap.put("const", TokenType.CONSTTK);
        keywordMap.put("int", TokenType.INTTK);
        keywordMap.put("char", TokenType.CHARTK);
        keywordMap.put("break", TokenType.BREAKTK);
        keywordMap.put("continue", TokenType.CONTINUETK);
        keywordMap.put("if", TokenType.IFTK);
        keywordMap.put("else", TokenType.ELSETK);
        keywordMap.put("for", TokenType.FORTK);
        keywordMap.put("getint", TokenType.GETINTTK);
        keywordMap.put("getchar", TokenType.GETCHARTK);
        keywordMap.put("printf", TokenType.PRINTFTK);
        keywordMap.put("return", TokenType.RETURNTK);
        keywordMap.put("void", TokenType.VOIDTK);
        getCh();
    }

    /**
     * Lexer 单例
     */
    private static Lexer lexer;

    /**
     * 初始化 Lexer
     *
     * @param fileReader 输入流封装的 reader
     */
    public static void initLexer(FileReader fileReader) {
        lexer = new Lexer(fileReader);
    }

    /**
     * 获取 Lexer 单例
     *
     * @return Lexer 单例
     */
    public static Lexer getLexer() {
        return lexer;
    }

    /**
     * 读取下一个单词
     *
     * @return tokenType/-1 on EOF/INNER_ERROR on error
     */
    private int next() {
        if (isSpace() || isNewLine() || isTab() || isR()) {
            while (isSpace() || isNewLine() || isTab() || isR()) {
                if (isNewLine()) {
                    line++;
                }
                getCh();
            }
        }
        if (isEOF()) {
            return Fault.EOF;
        }
        cleanToken();
        if (isLetter()) {
            while (isLetter() || isDigit()) {
                getCh();
            }
            getToken();
            TokenType result = keywordMap.get(token);
            if (result != null) {
                tokenType = result;
            } else {
                tokenType = TokenType.IDENFR;
            }
            //TODO:add table
        } else if (isDigit()) {
            while (isDigit()) {
                getCh();
            }
            getToken();
            intConst = transNum();
            tokenType = TokenType.INTCON;
        } else if (isShuang()) {
            getCh();
            stringConst = "";
            while (true) {
                if (!isAscii()) {
                    fault.otherInLexer(line);
                    return Fault.INNER_ERROR;
                } else if (isShuang()) {
                    break;
                } else if (isFan()) {
                    getCh();
                    char result = getESC();
                    if (result == (char) Fault.INNER_ERROR) {
                        fault.otherInLexer(line);
                        return Fault.INNER_ERROR;
                    }
                    stringConst = stringConst + result;
                } else {
                    stringConst = stringConst + ch;
                }
                getCh();
            }
            getCh();
            getToken();
            tokenType = TokenType.STRCON;
        } else if (isDan()) {
            getCh();
            if (!isAscii()) {
                fault.otherInLexer(line);
                return Fault.INNER_ERROR;
            } else if (isFan()) {
                getCh();
                char result = getESC();
                if (result == (char) Fault.INNER_ERROR) {
                    fault.otherInLexer(line);
                    return Fault.INNER_ERROR;
                }
                charConst = result;
            } else {
                charConst = ch;
            }
            getCh();
            if (!isDan()) {
                fault.otherInLexer(line);
                return Fault.INNER_ERROR;
            }
            getCh();
            getToken();
            tokenType = TokenType.CHRCON;
        } else if (isNot()) {
            getCh();
            if (isEqual()) {
                tokenType = TokenType.NEQ;
                getCh();
            } else {
                tokenType = TokenType.NOT;
            }
            getToken();
        } else if (isAnd()) {
            getCh();
            if (!isAnd()) {
                fault.illegalSymbol(line);
                tokenList.add(new Token(TokenType.AND, "&", line));
                return Fault.INNER_ERROR;
            }
            tokenType = TokenType.AND;
            getCh();
            getToken();
        } else if (isOr()) {
            getCh();
            if (!isOr()) {
                fault.illegalSymbol(line);
                tokenList.add(new Token(TokenType.OR, "|", line));
                return Fault.INNER_ERROR;
            }
            tokenType = TokenType.OR;
            getCh();
            getToken();
        } else if (isPlus()) {
            tokenType = TokenType.PLUS;
            getCh();
            getToken();
        } else if (isMinus()) {
            tokenType = TokenType.MINU;
            getCh();
            getToken();
        } else if (isStar()) {
            tokenType = TokenType.MULT;
            getCh();
            getToken();
        } else if (isDiv()) {
            getCh();
            if (isDiv()) {
                getCh();
                while (!isNewLine() && !isEOF()) {
                    getCh();
                }
                getCh();
                return next();
            } else if (isStar()) {
                getCh();
                while (true) {
                    if (isEOF()) {
                        fault.otherInLexer(line);
                        return Fault.INNER_ERROR;
                    }
                    if (isNewLine()) {
                        getCh();
                        line++;
                    } else if (isStar()) {
                        getCh();
                        if (isDiv()) {
                            break;
                        }
                    } else {
                        getCh();
                    }
                }
                getCh();
                return next();
            } else {
                tokenType = TokenType.DIV;
            }
            getToken();
        } else if (isMod()) {
            tokenType = TokenType.MOD;
            getCh();
            getToken();
        } else if (isLess()) {
            getCh();
            if (isEqual()) {
                tokenType = TokenType.LEQ;
                getCh();
            } else {
                tokenType = TokenType.LSS;
            }
            getToken();
        } else if (isGreater()) {
            getCh();
            if (isEqual()) {
                tokenType = TokenType.GEQ;
                getCh();
            } else {
                tokenType = TokenType.GRE;
            }
            getToken();
        } else if (isEqual()) {
            getCh();
            if (isEqual()) {
                tokenType = TokenType.EQL;
                getCh();
            } else {
                tokenType = TokenType.ASSIGN;
            }
            getToken();
        } else if (isFen()) {
            tokenType = TokenType.SEMICN;
            getCh();
            getToken();
        } else if (isDou()) {
            tokenType = TokenType.COMMA;
            getCh();
            getToken();
        } else if (isLXiao()) {
            tokenType = TokenType.LPARENT;
            getCh();
            getToken();
        } else if (isRXiao()) {
            tokenType = TokenType.RPARENT;
            getCh();
            getToken();
        } else if (isLZhong()) {
            tokenType = TokenType.LBRACK;
            getCh();
            getToken();
        } else if (isRZhong()) {
            tokenType = TokenType.RBRACK;
            getCh();
            getToken();
        } else if (isLDa()) {
            tokenType = TokenType.LBRACE;
            getCh();
            getToken();
        } else if (isRDa()) {
            tokenType = TokenType.RBRACE;
            getCh();
            getToken();
        } else {
            fault.otherInLexer(line);
            getCh();
            return Fault.INNER_ERROR;
        }
        tokenList.add(new Token(tokenType, token, line));
        return tokenType.ordinal();
    }

    /**
     * 输出 token 列表
     *
     * @param printStream 输出流
     * @param printLine   是否输出行号
     */
    public void printTokenList(PrintStream printStream, boolean printLine) {
        for (Token token1 : tokenList) {
            if (printLine) {
                printStream.print(token1.getLine() + " ");
            }
            printStream.println(token1);
        }
    }

    /**
     * 获取 token 列表
     *
     * @return token 列表
     */
    public List<Token> getTokenList() {
        return new ArrayList<>(tokenList);
    }

    /**
     * 读取下一个字符到ch，同时将字符添加到token尾部，
     * 这样会使得token会多记录一个所以在判断完token后使用getToken获得实际的token
     */
    private void getCh() {
        try {
            ch = (char) fileReader.read();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        token = token + ch;
    }

    /**
     * 判断是否为空格
     *
     * @return 是否为空格
     */
    private boolean isSpace() {
        return ch == ' ';
    }

    /**
     * 判断是否为换行
     *
     * @return 是否为换行
     */
    private boolean isNewLine() {
        return ch == '\n';
    }

    /**
     * 判断是否为 CR
     *
     * @return 是否为 CR
     */
    private boolean isR() {
        return ch == '\r';
    }

    /**
     * 判断是否为制表符
     *
     * @return 是否为制表符
     */
    private boolean isTab() {
        return ch == '\t';
    }

    /**
     * 判断是否为字母
     *
     * @return 是否为字母
     */
    private boolean isLetter() {
        return 'A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z' || ch == '_';
    }

    /**
     * 判断是否为数字
     *
     * @return 是否为数字
     */
    private boolean isDigit() {
        return '0' <= ch && ch <= '9';
    }

    /**
     * 判断是否为逗号
     *
     * @return 是否为逗号
     */
    private boolean isDou() {
        return ch == ',';
    }

    /**
     * 判断是否为分号
     *
     * @return 是否为分号
     */
    private boolean isFen() {
        return ch == ';';
    }

    /**
     * 判断是否为等号
     *
     * @return 是否为等号
     */
    private boolean isEqual() {
        return ch == '=';
    }

    /**
     * 判断是否为加号
     *
     * @return 是否为加号
     */
    private boolean isPlus() {
        return ch == '+';
    }

    /**
     * 判断是否为减号
     *
     * @return 是否为减号
     */
    private boolean isMinus() {
        return ch == '-';
    }

    /**
     * 判断是否为除号
     *
     * @return 是否为除号
     */
    private boolean isDiv() {
        return ch == '/';
    }

    /**
     * 判断是否为乘号
     *
     * @return 是否为乘号
     */
    private boolean isStar() {
        return ch == '*';
    }

    /**
     * 判断是否为 (
     *
     * @return 是否为 (
     */
    private boolean isLXiao() {
        return ch == '(';
    }

    /**
     * 判断是否为 )
     *
     * @return 是否为 )
     */
    private boolean isRXiao() {
        return ch == ')';
    }

    /**
     * 判断是否为 !
     *
     * @return 是否为 !
     */
    private boolean isNot() {
        return ch == '!';
    }

    /**
     * 判断是否为于
     *
     * @return 是否为与
     */
    private boolean isAnd() {
        return ch == '&';
    }

    /**
     * 判断是否为或
     *
     * @return 是否为或
     */
    private boolean isOr() {
        return ch == '|';
    }

    /**
     * 判断是否为 %
     *
     * @return 是否为 %
     */
    private boolean isMod() {
        return ch == '%';
    }

    /**
     * 判断是否为小于号
     *
     * @return 是否为小于号
     */
    private boolean isLess() {
        return ch == '<';
    }

    /**
     * 判断是否为大括号
     *
     * @return 是否为大括号
     */
    private boolean isGreater() {
        return ch == '>';
    }

    /**
     * 判断是否为 [
     *
     * @return 是否为 [
     */
    private boolean isLZhong() {
        return ch == '[';
    }

    /**
     * 判断是否为 ]
     *
     * @return 是否为 ]
     */
    private boolean isRZhong() {
        return ch == ']';
    }

    /**
     * 判断是否为 {
     *
     * @return 是否为 {
     */
    private boolean isLDa() {
        return ch == '{';
    }

    /**
     * 判断是否为 }
     *
     * @return 是否为 }
     */
    private boolean isRDa() {
        return ch == '}';
    }

    /**
     * 判断是否为 "
     *
     * @return 是否为 "
     */
    private boolean isShuang() {
        return ch == '\"';
    }

    /**
     * 判断是否为 '
     *
     * @return 是否为 '
     */
    private boolean isDan() {
        return ch == '\'';
    }

    /**
     * 判断是否为文法规定中的字符（不包含转义符）
     *
     * @return 是否为文法规定中的字符（不包含转义符）
     */
    private boolean isAscii() {
        return 32 <= ch && ch <= 126;
    }

    /**
     * 判断是否为 \
     *
     * @return 是否为 \
     */
    private boolean isFan() {
        return ch == '\\';
    }

    /**
     * 判断是否为 EOF
     *
     * @return 是否为 EOF
     */
    private boolean isEOF() {
        return ch == Fault.EOF;
    }

    /**
     * 获取转义字符
     *
     * @return 转义字符/INNER_ERROR on error
     */
    private char getESC() {
        return switch (ch) {
            case 'a' -> 7;
            case 'b' -> 8;
            case 't' -> 9;
            case 'n' -> 10;
            case 'v' -> 11;
            case 'f' -> 12;
            case '\"' -> 34;
            case '\'' -> 39;
            case '\\' -> 92;
            case '0' -> 0;
            default -> (char) Fault.INNER_ERROR;
        };
    }

    /**
     * 截掉token最后一个字符
     */
    private void getToken() {
        token = token.substring(0, token.length() - 1);
    }

    /**
     * 清空token，然后将当前ch中的字符载入token
     */
    private void cleanToken() {
        token = "" + ch;
    }

    /**
     * 把 token 转为数字
     *
     * @return token 转换的数字
     */
    private long transNum() {
        return Long.parseLong(token);
    }

    /**
     * 执行词法分析
     */
    public void pass() {
        int result;
        do {
            result = lexer.next();
        } while (result != Fault.EOF);
    }
}
