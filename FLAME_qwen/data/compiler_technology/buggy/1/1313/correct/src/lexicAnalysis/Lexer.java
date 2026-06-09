package src.lexicAnalysis;

import src.errorHandle.ErrorList;
import src.errorHandle.ErrorType;
import src.errorHandle.Error;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * 词法分析器，词法分析核心部分
 */
public class Lexer {
    private List<String> inputList; // 输入的字符串列表
    private Map<String, TokenType> tokenMap; // 单词类型对应表
    private TokenList tokenList; // 处理后的单词列表
    private ErrorList errorList; // 错误列表
    private int curRow, curCol;
    private char curChar;
    private String curStr;

    public Lexer(ArrayList<String> list) {
        this.inputList = list;
        this.tokenList = new TokenList();
        this.errorList = new ErrorList();
        this.curRow = 0;
        this.curCol = 0;
        this.curStr = list.isEmpty() ? "" : list.get(0);

        this.tokenMap = new HashMap<>();
        this.tokenMap.put("main", TokenType.MAINTK);
        this.tokenMap.put("const", TokenType.CONSTTK);
        this.tokenMap.put("int", TokenType.INTTK);
        this.tokenMap.put("char", TokenType.CHARTK);
        this.tokenMap.put("break", TokenType.BREAKTK);
        this.tokenMap.put("continue", TokenType.CONTINUETK);
        this.tokenMap.put("if", TokenType.IFTK);
        this.tokenMap.put("else", TokenType.ELSETK);
        this.tokenMap.put("!", TokenType.NOT);
        this.tokenMap.put("&&", TokenType.AND);
        this.tokenMap.put("||", TokenType.OR);
        this.tokenMap.put("for", TokenType.FORTK);
        this.tokenMap.put("getint", TokenType.GETINTTK);
        this.tokenMap.put("getchar", TokenType.GETCHARTK);
        this.tokenMap.put("printf", TokenType.PRINTFTK);
        this.tokenMap.put("return", TokenType.RETURNTK);
        this.tokenMap.put("+", TokenType.PLUS);
        this.tokenMap.put("-", TokenType.MINU);
        this.tokenMap.put("void", TokenType.VOIDTK);
        this.tokenMap.put("*", TokenType.MULT);
        this.tokenMap.put("/", TokenType.DIV);
        this.tokenMap.put("%", TokenType.MOD);
        this.tokenMap.put("<", TokenType.LSS);
        this.tokenMap.put("<=", TokenType.LEQ);
        this.tokenMap.put(">", TokenType.GRE);
        this.tokenMap.put(">=", TokenType.GEQ);
        this.tokenMap.put("==", TokenType.EQL);
        this.tokenMap.put("!=", TokenType.NEQ);
        this.tokenMap.put("=", TokenType.ASSIGN);
        this.tokenMap.put(";", TokenType.SEMICN);
        this.tokenMap.put(",", TokenType.COMMA);
        this.tokenMap.put("(", TokenType.LPARENT);
        this.tokenMap.put(")", TokenType.RPARENT);
        this.tokenMap.put("[", TokenType.LBRACK);
        this.tokenMap.put("]", TokenType.RBRACK);
        this.tokenMap.put("{", TokenType.LBRACE);
        this.tokenMap.put("}", TokenType.RBRACE);
    }


    public TokenList getTokenList() {
        return tokenList;
    }

    public ErrorList getErrorList() {
        return errorList;
    }

    /*--------------------分析部分---------------------*/
    public void analyze() { // 主要方法
        while (curRow < inputList.size()) {
            curStr = inputList.get(curRow);
            if (curCol < curStr.length()) {
                curChar = curStr.charAt(curCol);
                if (curChar == '\n' || curChar == '\r' || curChar == '\t' || curChar == ' ') {
                    goNext();
                } else if (Character.isLetter(curChar) || curChar == '_') {
                    analyzeReservedOrIdent();
                } else if (Character.isDigit(curChar)) {
                    analyzeIntConst();
                } else if (curChar == '\'') {
                    analyzeCharConst();
                } else if (curChar == '\"') {
                    analyzeStringConst();
                } else {
                    analyzeOperator();
                }
            } else {
                curRow++;
                curCol = 0;
            }
        }
    }

    private char getNext() { // 获取下一个字符
        if (curCol + 1 < curStr.length()) {
            return curStr.charAt(curCol + 1);
        }
        return 0;
    }

    private void goNext() { // 指针后移一位，并更新curChar
        curCol++;
        curChar = curCol < curStr.length() ? curStr.charAt(curCol) : 0;
    }

    private void nextRow() { // 读取下一行
        curRow++;
        curCol = 0;
        if (curRow < inputList.size()) {
             curStr = inputList.get(curRow);
             curChar = curCol < curStr.length() ? curStr.charAt(curCol) : 0;
        } else {
            curStr = "";
            curChar = 0;
        }
    }

    private boolean endOfRow() { // 判断是否换行
        return curCol >= curStr.length();
    }

    private void analyzeIntConst() { // 处理整形常量
        int tokenRow = curRow;
        int tokenCol = curCol;
        StringBuilder sb = new StringBuilder();
        sb.append(curChar);
        while (Character.isDigit(getNext())) {
            goNext();
            sb.append(curChar);
        }
        Token token = new Token(TokenType.INTCON, tokenRow, tokenCol, sb.toString());
        tokenList.add(token);
        goNext();
    }

    private void analyzeCharConst() { // 处理字符常量
        int tokenRow = curRow;
        int tokenCol = curCol;
        StringBuilder sb = new StringBuilder();
        sb.append(curChar);
        while (getNext() != 0) {
            goNext();
            sb.append(curChar);
            if (curChar == '\'') { // content包含头尾的单引号
                break;
            }
            if (curChar == '\\') { // 遇到转义符读两个字符
                goNext();
                sb.append(curChar);
            }
        }
        Token token = new Token(TokenType.CHRCON, tokenRow, tokenCol, sb.toString());
        tokenList.add(token);
        goNext();
    }

    private void analyzeStringConst() { // 处理字符串常量
        int tokenRow = curRow;
        int tokenCol = curCol;
        StringBuilder sb = new StringBuilder();
        sb.append(curChar);
        while (getNext() != 0) {
            goNext();
            sb.append(curChar);
            if (curChar == '\"') { // content包含头尾的双引号
                break;
            }
            if (curChar == '\\') { // 遇到转义符读两个字符
                goNext();
                sb.append(curChar);
            }
        }
        Token token = new Token(TokenType.STRCON, tokenRow, tokenCol, sb.toString());
        tokenList.add(token);
        goNext();
    }

    private void analyzeReservedOrIdent() { // 处理保留字和标识符
        int tokenRow = curRow;
        int tokenCol = curCol;
        StringBuilder sb = new StringBuilder();
        sb.append(curChar);
        while (Character.isLetterOrDigit(getNext()) || getNext() == '_') {
            goNext();
            sb.append(curChar);
        }
        String str = sb.toString();
        TokenType tokenType = tokenMap.getOrDefault(str, TokenType.IDENFR);
        Token token = new Token(tokenType, tokenRow, tokenCol, str);
        tokenList.add(token);
        goNext();
    }

    private void analyzeOperator() { // 处理操作符等
        int tokenRow = curRow;
        int tokenCol = curCol;
        StringBuilder sb = new StringBuilder();
        sb.append(curChar);
        if (curChar == '!') {
            if (getNext() == '=') {
                goNext();
                sb.append(curChar);
            }
        } else if (curChar == '&') {
            if (getNext() == '&') {
                goNext();
                sb.append(curChar);
            } else {
                // 报错
                Error error = new Error(ErrorType.a, curRow, curCol);
                errorList.add(error);
            }
            // '&' 当作 '&&' 处理，content记录为 '&&'
            Token token = new Token(tokenMap.get("&&"), tokenRow, tokenCol, "&&");
            tokenList.add(token);
            goNext();
            return; // 提前返回

        } else if (curChar == '|') {
            if (getNext() == '|') {
                goNext();
                sb.append(curChar);
            } else {
                // 报错
                Error error = new Error(ErrorType.a, curRow, curCol);
                errorList.add(error);
            }
            // '|' 当作 '||' 处理，content记录为 '||'
            Token token = new Token(tokenMap.get("||"), tokenRow, tokenCol, "||");
            tokenList.add(token);
            goNext();
            return; // 提前返回

        } else if (curChar == '/') {
            if (getNext() == '/') { // 单行注释
                nextRow();
                return; // 提前返回
            } else if (getNext() == '*') { // 多行注释
                goNext();
                goNext();
                while (true) {
                    char preChar = curChar;
                    goNext();
                    if (endOfRow()) {
                        nextRow();
                        if (curRow >= inputList.size()) { // 文件结束
                            return;
                        }
                        continue;
                    }
                    if (preChar == '*' && curChar == '/') { // 多行注释结尾
                        break;
                    }
                }
                goNext();
                return; // 提前返回
            } // 除号，后面统一处理

        } else if (curChar == '<' || curChar == '>' || curChar == '=') {
            if (getNext() == '=') {
                goNext();
                sb.append(curChar);
            }
        } // else error

        // 除了以上要向后读一位的字符，其余统一处理
        String str = sb.toString();
        Token token = new Token(tokenMap.get(str), tokenRow, tokenCol, str);
        tokenList.add(token);
        goNext();
    }

}