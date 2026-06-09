package frontend;

import assist.Token;
import assist.Reserver;
import java.util.ArrayList;

public class Lexer {
    private ArrayList<Token> tokenList = new ArrayList<>();
    private Reserver reserver;
    private ArrayList<String> input;
    private int[] curPos = {0, 0};
    private int[] lastPos = {0, 0};
    private int maxLine;
    private boolean isEnd;
    private ArrayList<String> errorList;
    private boolean hasError;

    public Lexer(ArrayList<String> testfile) {
        input = testfile;
        maxLine = input.size();
        isEnd = false;
        errorList = new ArrayList<>();
        hasError = false;
        reserver = new Reserver();
    }

    public ArrayList<Token> resolve() {
        while (!isEnd()) {
            getOneToken();
        }
        return tokenList;
    }

    private void getOneToken() {
        while (isBlank()); //跳过空格
        retract();
        char ch = getCur();
        if (isLetterOr_(ch)) {
            StringBuilder splice = new StringBuilder();
            while (isLetterOr_(ch) || Character.isDigit(ch)) {
                splice.append(ch);
                ch = getCur();
            }
            retract();
            String str = splice.toString();
            if (reserver.isReserver(str)) {
                tokenList.add((new Token()).setToken(reserver2Type(str), str, getCurLine()));
            } else {
                tokenList.add((new Token()).setToken(Token.Type.IDENFR, str, getCurLine()));
            }
        } else if (Character.isDigit(ch)) { //假设不会出现前导0,如0123
            StringBuilder splice = new StringBuilder();
            while(Character.isDigit(ch)) {
                splice.append(ch);
                ch = getCur();
            }
            retract();
            tokenList.add((new Token()).setToken(Token.Type.INTCON, splice.toString(), getCurLine()));
        } else if (ch == '\'') { //转义符号连同\一起保存在token的value中
            //todo 转义字符
            StringBuilder splice = new StringBuilder();
            char last = ch;
            ch = getCur();
            while (ch != '\'' || last == '\\') {
                splice.append(ch);
                last = ch;
                ch = getCur();
            }
            tokenList.add((new Token()).setToken(Token.Type.CHRCON, "'" +splice.toString()+"'", getCurLine()));
        } else if (ch == '\"') { //假设ascii码全在合理范围（词法分析只可能出现a类错误），且没有特判\n
            //todo \n
            StringBuilder splice = new StringBuilder();
            ch = getCur();
            while (ch != '\"') {
                splice.append(ch);
                ch = getCur();
            }
            tokenList.add((new Token()).setToken(Token.Type.STRCON, "\""+splice.toString()+"\"", getCurLine()));
        } else if (ch == '!') {
            ch = getCur();
            if (ch == '=') {
                tokenList.add((new Token()).setToken(Token.Type.NEQ, "!=", getCurLine()));
            } else {
                retract();
                tokenList.add((new Token()).setToken(Token.Type.NOT, "!", getCurLine()));
            }
        } else if (ch == '&') {
            ch = getCur();
            if (ch == '&') {
                tokenList.add((new Token()).setToken(Token.Type.AND, "&&", getCurLine()));
            } else {
                retract();
                hasError = true;
                errorList.add((getCurLine()+1) + " " + "a"); //错误类别码为a
                tokenList.add((new Token()).setToken(Token.Type.AND, "&", getCurLine()));
            }
        } else if (ch == '|') {
            ch = getCur();
            if (ch == '|') {
                tokenList.add((new Token()).setToken(Token.Type.OR, "||", getCurLine()));
            } else {
                retract();
                hasError = true;
                errorList.add((getCurLine()+1) + " " + "a"); //错误类别码为a
                tokenList.add((new Token()).setToken(Token.Type.OR, "|", getCurLine()));
            }
        } else if (ch == '+') {
            tokenList.add((new Token()).setToken(Token.Type.PLUS, "+", getCurLine()));
        } else if (ch == '-') {
            tokenList.add((new Token()).setToken(Token.Type.MINU, "-", getCurLine()));
        } else if (ch == '*') {
            tokenList.add((new Token()).setToken(Token.Type.MULT, "*", getCurLine()));
        } else if (ch == '/') { //除法 + 注释
            ch = getCur();
            if (ch == '/') { //单行注释，本次调用该函数未得到新的token
                int line1 = getCurLine();
                while (getCurLine() == line1 && !isEnd()) {
                    ch = getCur();
                }
                if (!isEnd()) {
                    retract();
                }
                return;
            } else if (ch == '*') { //多行注释，本次调用该函数未得到新的token
                int state = 0;
                while (state != 2 && !isEnd()) { //有限状态机
                    ch = getCur();
                    if (ch == '*' && state == 0) {
                        state = 1;
                    } else if (ch == '/' && state == 1) {
                        state = 2;
                    } else if (ch != '*' && state == 1) {
                        state = 0;
                    }
                }
                return;
            } else {
                retract();
                tokenList.add((new Token()).setToken(Token.Type.DIV, "/", getCurLine()));
            }
        } else if (ch == '%') {
            tokenList.add((new Token()).setToken(Token.Type.MOD, "%", getCurLine()));
        } else if (ch == '<') {
            ch = getCur();
            if (ch == '=') {
                tokenList.add((new Token()).setToken(Token.Type.LEQ, "<=", getCurLine()));
            } else {
                retract();
                tokenList.add((new Token()).setToken(Token.Type.LSS, "<", getCurLine()));
            }
        } else if (ch == '>') {
            ch = getCur();
            if (ch == '=') {
                tokenList.add((new Token()).setToken(Token.Type.GEQ, ">=", getCurLine()));
            } else {
                retract();
                tokenList.add((new Token()).setToken(Token.Type.GRE, ">", getCurLine()));
            }
        } else if (ch == '=') {
            ch = getCur();
            if (ch == '=') {
                tokenList.add((new Token()).setToken(Token.Type.EQL, "==", getCurLine()));
            } else {
                retract();
                tokenList.add((new Token()).setToken(Token.Type.ASSIGN, "=", getCurLine()));
            }
        } else if (ch == ';') {
            tokenList.add((new Token()).setToken(Token.Type.SEMICN, ";", getCurLine()));
        } else if (ch == ',') {
            tokenList.add((new Token()).setToken(Token.Type.COMMA, ",", getCurLine()));
        } else if (ch == '(') {
            tokenList.add((new Token()).setToken(Token.Type.LPARENT, "(", getCurLine()));
        } else if (ch == ')') {
            tokenList.add((new Token()).setToken(Token.Type.RPARENT, ")", getCurLine()));
        } else if (ch == '[') {
            tokenList.add((new Token()).setToken(Token.Type.LBRACK, "[", getCurLine()));
        } else if (ch == ']') {
            tokenList.add((new Token()).setToken(Token.Type.RBRACK, "]", getCurLine()));
        } else if (ch == '{') {
            tokenList.add((new Token()).setToken(Token.Type.LBRACE, "{", getCurLine()));
        } else if (ch == '}') {
            tokenList.add((new Token()).setToken(Token.Type.RBRACE, "}", getCurLine()));
        } else if (ch != '\0' && ch != '\n'){
            tokenList.add((new Token()).setToken(Token.Type.ERROR, "", -1));
        }
    }

    private boolean isBlank() {
        char ch = getCur();
        return (ch == 32 || ch == 10 || ch == 9); //空格-32，换行-10，制表-9
    }

    private boolean isLetterOr_(char ch) {
        return (ch == '_' || Character.isLowerCase(ch) || Character.isUpperCase(ch));
    }

    private Token.Type reserver2Type(String reserver) {
        if (reserver.equals("main")) return Token.Type.MAINTK;
        else if (reserver.equals("const")) return Token.Type.CONSTTK;
        else if (reserver.equals("int")) return Token.Type.INTTK;
        else if (reserver.equals("char")) return Token.Type.CHARTK;
        else if (reserver.equals("break")) return Token.Type.BREAKTK;
        else if (reserver.equals("continue")) return Token.Type.CONTINUETK;
        else if (reserver.equals("if")) return Token.Type.IFTK;
        else if (reserver.equals("else")) return Token.Type.ELSETK;
        else if (reserver.equals("for")) return Token.Type.FORTK;
        else if (reserver.equals("getint")) return Token.Type.GETINTTK;
        else if (reserver.equals("getchar")) return Token.Type.GETCHARTK;
        else if (reserver.equals("printf")) return Token.Type.PRINTFTK;
        else if (reserver.equals("return")) return Token.Type.RETURNTK;
        else if (reserver.equals("void")) return Token.Type.VOIDTK;
        else return Token.Type.ERROR;
    }

    private char getCur() { //获得当前符号并更新位置向量
        while (input.get(curPos[0]).isEmpty()) { //跳过空行
            curPos[0]++;
            if (curPos[0] >= maxLine) {
                isEnd = true;
                return '\0';
            }
        }
        char tem = input.get(curPos[0]).charAt(curPos[1]);
        lastPos[0] = curPos[0];
        lastPos[1] = curPos[1];
        if (curPos[1] < (input.get(curPos[0]).length() - 1)) {
            curPos[1]++; //在当前行向后移一个字符
        } else if (curPos[0] < (maxLine - 1)) {
            curPos[0]++;
            curPos[1] = 0; //移到下一行第一个字符
        } else if (!isEnd){
            isEnd = true;
            return tem;
        }
        if (isEnd) return '\0';
        else {
            return tem;
        }
    }

    private int getCurLine() {
        return lastPos[0];
    }

    private void retract() { //回退一个字符
        curPos[0] = lastPos[0];
        curPos[1] = lastPos[1];
        if (lastPos[1] > 0) {
            lastPos[1]--; //在当前行向前移一个字符
        } else if (lastPos[0] > 0) {
            lastPos[0]--;
            while (input.get(lastPos[0]).isEmpty()) {
                lastPos[0]--;
                if (lastPos[0] < 0) {
                    lastPos[0] = 0;
                    lastPos[1] = 0;
                    return;
                }
            }
            lastPos[1] = input.get(lastPos[0]).length()-1; //移到上一行最后一个字符
        }
    }

    private boolean isEnd() {
        return isEnd;
    }

    public ArrayList<String> showErrorList() {
        return errorList;
    }

    public boolean isHasError() {
        return hasError;
    }
}
