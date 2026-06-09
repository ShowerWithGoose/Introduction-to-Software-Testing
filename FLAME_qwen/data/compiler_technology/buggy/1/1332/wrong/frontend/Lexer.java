package frontend;

import token.Token;
import token.TokenType;
import error.Error;
import error.ErrorType;

import java.util.ArrayList;
import java.util.List;

/**
 * ClassName: Lexer
 * Package: frontend
 * Description:
 *
 * @Author
 * @Create 2024/9/23 19:54
 * @Improve 2024/10/13 20:50
 * @Version 2.0
 */
public class Lexer {
    public static Lexer lexer = new Lexer();

    public String code;

    private char c;

    public List<Token> tokens = new ArrayList<>();

    public int index = -1; // 文件字符流指针

    private int lineNo = 1; // 行号

    private int thisLineTokenNo = 1; // 当前token是这一行的第几个
    private int thisLineCharNo = 0; // 弃用：当前字符是这一行的第几个

    public StringBuilder token = new StringBuilder();

    private char getPreReadChar(int n) {
        if (index + n >= code.length()) {
            return '\0';
        }
        return code.charAt(index + n);
    }

    // 前面拼接到token上的字符不要了
    private void clearToken() {
        token.setLength(0);
    }

    // 使c回到上一个字符
    private void goBackToLastChar() {
        retract(); // 把字符放回去两个
        retract(); // 放回去一个是因为读了别人的，下次别人能读到这个
        getChar(); // 需要手动getChar获取新字符
    }

    // 入口函数
    public void parse(String code) {
        this.code = code;
        Token token;
        // parseToken()返回null表示文件结束
        while ((token = parseToken()) != null) {
            tokens.add(token);
            thisLineTokenNo++;
        }
    }

    // parseToken()返回null表示文件结束
    private Token parseToken() {
        // 下面的过程是填充该tk对象
        Token tk = new Token();
        clearToken();
        getChar();
        while (isWhiteSpace()) { // 如果当前是空白字符 ' ', '\t', '\n'
            isNewLine(); // 特别的，如果是'\n'，行号加1
            getChar(); // 读取下一个
        }
        catToken();
        // identifier
        if (isLetterOr_()) {
            getChar();
            while (isLetterOr_() || isDigit()) {
                catToken();
                getChar();
            }
            // 回退一个
            retract();
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), reserver(), lineNo, thisLineTokenNo);
        }
        // IntConst
        if (isDigit()) { // >= 0
            if (isZero()) { // 0
                getChar();
                if (isDigit()) {
                    // error
                    // 出现有前导零数字的情况
//                    System.out.println("Lexer error when parse intConst");
//                    System.exit(1);
                    throw new RuntimeException("Lexer error when parse intConst");
                } else {
                    retract();
//                    tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                    return new Token(token.toString(), TokenType.INTCON, lineNo, thisLineTokenNo, 0);
                }
            } else { // > 0
                getChar();
                while (isDigit()) {
                    catToken();
                    getChar();
                }
                retract();
                int value;
                try {
                    value = Integer.parseInt(token.toString());
                } catch (NumberFormatException e) {
                    // error
                    // 数字过大
                    throw new RuntimeException("Lexer error when parse intConst, num beyond int, lineNo: " + lineNo);
                }
//                tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                return new Token(token.toString(), TokenType.INTCON, lineNo, thisLineTokenNo, value);
            }
        }
        // StringConst
        if (c == '\"') {
            while (true) {
                getChar();
                // 之前的while都是满足条件，继续循环，现在是不满足条件，继续循环
                // 即，之前的是找符合的，现在是找字符串结束符"或者文件结束符'\0'
                // 找到"，结束循环，接下来还需要判断是不是真的字符串结束
                // 找不满足的时候需要防止死循环：c != '\0'
                // while里遍历了整个字符串
                while (c != '\0' && c != '\"') {
                    // 在这里进行转义字符的处理
//                    if (c == '\\'){
//                        getChar();
//                        if(c == 'n'){
//                            System.out.println("\\n");
//                        }
//                        retract();
//                        retract();
//                        getChar(); // 恢复c = '\\'
//                    }
                    catToken();
                    getChar();
                }
                // 退出循环的原因：c == '\0' || c == '\"'
                if (c == '\0') { // 文件结束，但是字符串未闭合
                    // error
                    // 字符串未闭合
                    return null;
                } else { // 此时c是"，看上一个是不是转义字符
                    goBackToLastChar(); // 此时c是上一个字符
                    if (c == '\\') { // 考虑"\\"和"a\"的情况，前者正常
                        goBackToLastChar(); // 再看上一个是不是`\`
                        if (c == '\\') {
                            getChar(); // "\\", 此时c是第二个`\`
                        } else { // 字符串未结束，需要继续找"
                            getChar();
                            getChar(); // 此时c是"
                            catToken(); // "加到token里
                            continue;
                        }
                    }
                    // 不是转义字符，字符串结束
                    getChar(); // 此时c是" 
                    catToken(); // 
//                    tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                    return new Token(token.toString(), TokenType.STRCON, lineNo, thisLineTokenNo);
                }
            }
        }
        // CharConst
        if (c == '\'') {
            getChar();
            if (c == '\'') {
                // error
                // 字符为空，没说有字符为空的情况
                return parseToken(); // 继续处理下一个token
            } else if (c == '\\') { // 是转义字符
                catToken();
                getChar();
//                if(c == 'x'){ // 判断转义字符合理性
//
//                }
                catToken(); // 转义字符加到token里
                getChar();
                if (c == '\'') {
                    catToken();
//                    tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                    return new Token(token.toString(), TokenType.CHRCON, lineNo, thisLineTokenNo);
                } else {
                    // error
                    // 字符未闭合, 或者说字符长度大于1
                    // 需要手动闭合后继续处理下一个token
                    return parseToken(); // 继续处理下一个token
                }
            } else { // 普通字符
                catToken();
                getChar();
                if (c == '\'') {
                    catToken();
//                    tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                    return new Token(token.toString(), TokenType.CHRCON, lineNo, thisLineTokenNo);
                } else {
                    // error
                    // 字符未闭合, 或者说字符长度大于1
                    // 需要手动闭合后继续处理下一个token
                    return parseToken(); // 继续处理下一个token
                }
            }
        }
        // ! 或者 !=
        if (c == '!') {
            TokenType type;
            if (getPreReadChar(1) == '=') {
                type = TokenType.NEQ;
                getChar();
                catToken();
            } else {
                type = TokenType.NOT;
            }
            return new Token(token.toString(), type, lineNo, thisLineTokenNo);
//            getChar();
//            if (c == '='){ // !=
//                catToken();
//                tk.content = token.toString();
//                tk.type = TokenType.NEQ;
//                tk.lineNo = lineNo;
//                tk.thisLineTokenNo = thisLineTokenNo;
//                tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
//                return tk;
//            }else{ // !
//                retract();
//                tk.content = token.toString();
//                tk.type = TokenType.NOT;
//                tk.lineNo = lineNo;
//                tk.thisLineTokenNo = thisLineTokenNo;
//                tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
//                return tk;
//            }
        }
        if (c == '&') {
            getChar();
            if (c == '&') {
                catToken();
//                tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                return new Token(token.toString(), TokenType.AND, lineNo, thisLineTokenNo);
            } else {
                // error, 只有一个&
//                error.thisLineCharNo = thisLineCharNo;
//                error.thisLineTokenNo = thisLineTokenNo;
                // getChar不会导致lineNo变化
                Error.errors.add(new Error(lineNo, ErrorType.a));

                // 尝试修复
                retract();
                return new Token("&&", TokenType.AND, lineNo, thisLineTokenNo);
            }
        }
        // OR
        if (c == '|') {
            getChar();
            if (c == '|') {
                catToken();
//                tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                return new Token(token.toString(), TokenType.OR, lineNo, thisLineTokenNo);
            } else {
                // error a
                // 错误记录
//                error.thisLineCharNo = thisLineCharNo;
//                error.thisLineTokenNo = thisLineTokenNo;
                Error.errors.add(new Error(lineNo, ErrorType.a));

                // 尝试修复
                retract();
                return new Token("||", TokenType.OR, lineNo, thisLineTokenNo);

            }
        }
        // PLUS
        if (c == '+') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.PLUS, lineNo, thisLineTokenNo);
        }
        // MINU
        if (c == '-') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.MINU, lineNo, thisLineTokenNo);
        }
        // MULT
        if (c == '*') {
//           tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.MULT, lineNo, thisLineTokenNo);
        }
        // MOD
        if (c == '%') {
            return new Token(token.toString(), TokenType.MOD, lineNo, thisLineTokenNo);
        }
        // LSS
        if (c == '<') {
            TokenType type;
            if (getPreReadChar(1) == '=') {
                type = TokenType.LEQ;
                getChar();
                catToken();
            } else {
                type = TokenType.LSS;
            }
            return new Token(token.toString(), type, lineNo, thisLineTokenNo);
        }
        if (c == '>') {
            TokenType type;
            if (getPreReadChar(1) == '=') {
                type = TokenType.GEQ;
                getChar();
                catToken();
            } else {
                type = TokenType.GRE;
            }
            return new Token(token.toString(), type, lineNo, thisLineTokenNo);
        }
        if (c == '=') {
            TokenType type;
            if (getPreReadChar(1) == '=') {
                type = TokenType.EQL;
                getChar();
                catToken();
            } else {
                type = TokenType.ASSIGN;
            }
            return new Token(token.toString(), type, lineNo, thisLineTokenNo);
        }

        if (c == ';') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.SEMICN, lineNo, thisLineTokenNo);
        }
        if (c == ',') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.COMMA, lineNo, thisLineTokenNo);
        }
        if (c == '(') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.LPARENT, lineNo, thisLineTokenNo);
        }
        if (c == ')') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.RPARENT, lineNo, thisLineTokenNo);
        }
        if (c == '[') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.LBRACK, lineNo, thisLineTokenNo);
        }
        if (c == ']') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.RBRACK, lineNo, thisLineTokenNo);
        }
        if (c == '{') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.LBRACE, lineNo, thisLineTokenNo);
        }
        if (c == '}') {
//            tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
            return new Token(token.toString(), TokenType.RBRACE, lineNo, thisLineTokenNo);
        }
        // comment
        if (c == '/') {
            getChar();
            // 多行注释
            if (c == '*') {
                while (true) { // 读到*/结束
                    getChar();
                    // 注释这一个‘token’中间有换行的可能，其他token都没有
                    isNewLine();
                    if (c == '*' && getPreReadChar(1) == '/') {
                        System.out.println("now lineNo is " + lineNo);
                        // 读到 / ，不用为下次parseToken做准备
                        getChar();
                        return parseToken();
                    }
                }
            }
            // 单行注释
            else if (c == '/') {
                getChar();
                while (!isNewLine()) {
                    getChar();
                }
                return parseToken();
            }
            // DIV
            else {
                retract();
//                tk.thisLineCharNo = thisLineCharNo - token.length() + 1;
                return new Token(token.toString(), TokenType.DIV, lineNo, thisLineTokenNo);
            }

        }
        // 上面都没匹配，那就是文件结束了
        if (isEOF()) {
            return null;
        }
        return null;
    }

    // 对于保留字，它是main一类还是标识符
    private TokenType reserver() {
        if (token.toString().equals("main")) {
            return TokenType.MAINTK;
        }
        if (token.toString().equals("const")) {
            return TokenType.CONSTTK;
        }
        if (token.toString().equals("int")) {
            return TokenType.INTTK;
        }
        if (token.toString().equals("char")) {
            return TokenType.CHARTK;
        }
        if (token.toString().equals("break")) {
            return TokenType.BREAKTK;
        }
        if (token.toString().equals("continue")) {
            return TokenType.CONTINUETK;
        }
        if (token.toString().equals("if")) {
            return TokenType.IFTK;
        }
        if (token.toString().equals("else")) {
            return TokenType.ELSETK;
        }
        if (token.toString().equals("for")) {
            return TokenType.FORTK;
        }
        if (token.toString().equals("getint")) {
            return TokenType.GETINTTK;
        }
        if (token.toString().equals("getchar")) {
            return TokenType.GETCHARTK;
        }
        if (token.toString().equals("printf")) {
            return TokenType.PRINTFTK;
        }
        if (token.toString().equals("return")) {
            return TokenType.RETURNTK;
        }
        if (token.toString().equals("void")) {
            return TokenType.VOIDTK;
        }
        return TokenType.IDENFR;
    }

    private void catToken() {
        token.append(c);
    }

    // 从文件中读取下一个字符，如果没有了，c = '\0'，以此判断文件结束
    private void getChar() {
        index++;
        if (index < 0) {
            System.out.println("程序陷入死循环导致index溢出为负数");
            System.exit(1);
        }
        thisLineCharNo++;
        if (index >= code.length()) {
            c = '\0';
        } else {
            c = code.charAt(index);
        }
    }


    private void retract() {
        index--;
        thisLineCharNo--;
    }

    private boolean isEOF() {
        if (c == '\0') {
            return true;
        }
        return false;
    }

    private boolean isWhiteSpace() {
        if (c == ' '
                || c == '\t'
                || c == '\n') {
            return true;
        }
        return false;
    }

    private boolean isNewLine() {
        if (c == '\n') {
            lineNo++;
            thisLineTokenNo = 1;
            thisLineCharNo = 0;
            return true;
        }
        return false;
    }

    private boolean isLetterOr_() {
        return (c >= 'A' && c <= 'Z')
                || (c >= 'a' && c <= 'z')
                || c == '_';
    }

    private boolean isDigit() {
        return c >= '0' && c <= '9';
    }

    private boolean isZero() {
        return c == '0';
    }

}
