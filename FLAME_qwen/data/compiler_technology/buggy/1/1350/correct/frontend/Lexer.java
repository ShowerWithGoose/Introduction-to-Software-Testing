/* 默认没有奇怪的换行问题 */
package frontend;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Lexer {
    private final ArrayList<Token> tokens = new ArrayList<>();
    private boolean is_correct = true;
    private int cur = 0;
    private final List<String> keywords = Arrays.asList("main", "const", "int", "char",
            "break", "continue", "if", "else", "for", "getint", "getchar", "printf",
            "return", "void");
    private final List<String> reservedChars = Arrays.asList("!", "&&", "||", "+","-", "*", "/",
            "%", "<", "<=", ">", ">=", "==", "!=", "=", ";", ",", "(", ")", "[", "]", "{", "}","&","|");

    public Lexer(String testFilePath) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(testFilePath));
        String line;
        int lineCnt = 0;
        boolean is_commented = false;
        while ((line = br.readLine()) != null) {
            lineCnt++;
            int pos = 0;
            if (is_commented) {
                while (pos < line.length()) {
                    if (line.charAt(pos) == '*' && pos != line.length() - 1) {
                        pos++;
                        if (line.charAt(pos) == '/') {
                            is_commented = false;
                            pos++;
                            break;
                        }
                    } else {
                        pos++;
                    }
                }
            }
            while (pos < line.length()) {
                if (line.charAt(pos) == ' ') {
                    pos++;
                } else if (line.charAt(pos) == ';') {
                    tokens.add(new Token(Token.Type.SEMICN, ";", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == ',') {
                    tokens.add(new Token(Token.Type.COMMA, ",", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '(') {
                    tokens.add(new Token(Token.Type.LPARENT, "(", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == ')') {
                    tokens.add(new Token(Token.Type.RPARENT, ")", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '[') {
                    tokens.add(new Token(Token.Type.LBRACK, "[", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == ']') {
                    tokens.add(new Token(Token.Type.RBRACK, "]", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '{') {
                    tokens.add(new Token(Token.Type.LBRACE, "{", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '}') {
                    tokens.add(new Token(Token.Type.RBRACE, "}", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '+') {
                    tokens.add(new Token(Token.Type.PLUS, "+", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '-') {
                    tokens.add(new Token(Token.Type.MINU, "-", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '*') {
                    tokens.add(new Token(Token.Type.MULT, "*", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '/') {   // 小心换行问题
                    pos++;
                    if (line.charAt(pos) == '/') {
                        break;
                    } else if (line.charAt(pos) == '*') {
                        is_commented = true;
                        pos++;
                        while (pos < line.length()) {
                            if (line.charAt(pos) == '*' && pos != line.length() - 1) {
                                pos++;
                                if (line.charAt(pos) == '/') {
                                    is_commented = false;
                                    pos++;
                                    break;
                                }
                            } else {
                                pos++;
                            }
                        }
                    } else {
                        pos--;
                        tokens.add(new Token(Token.Type.DIV, "/", lineCnt));
                    }
                    pos++;
                } else if (line.charAt(pos) == '%') {
                    tokens.add(new Token(Token.Type.MOD, "%", lineCnt));
                    pos++;
                } else if (line.charAt(pos) == '!') {   // 小心换行问题
                    pos++;
                    if (line.charAt(pos) == '=') {
                        tokens.add(new Token(Token.Type.NEQ, "!=", lineCnt));
                    } else {
                        pos--;
                        tokens.add(new Token(Token.Type.NOT, "!", lineCnt));
                    }
                    pos++;
                } else if (line.charAt(pos) == '&') {   // 小心换行问题
                    pos++;
                    if (line.charAt(pos) == '&') {
                        tokens.add(new Token(Token.Type.AND, "&&", lineCnt));
                    } else {
                        pos--;
                        Token temptToken = new Token(Token.Type.AND, "&&", lineCnt);
                        temptToken.setIsCorrect(false);
                        tokens.add(temptToken);
                        is_correct = false;
                    }
                    pos++;
                } else if (line.charAt(pos) == '|') {   // 小心换行问题
                    pos++;
                    if (line.charAt(pos) == '|') {
                        tokens.add(new Token(Token.Type.OR, "||", lineCnt));
                    } else {
                        pos--;
                        Token temptToken = new Token(Token.Type.OR, "||", lineCnt);
                        temptToken.setIsCorrect(false);
                        tokens.add(temptToken);
                        is_correct = false;
                    }
                    pos++;
                } else if (line.charAt(pos) == '<') {   // 小心换行问题
                    pos++;
                    if (line.charAt(pos) == '=') {
                        tokens.add(new Token(Token.Type.LEQ, "<=", lineCnt));
                    } else {
                        pos--;
                        tokens.add(new Token(Token.Type.LSS, "<", lineCnt));
                    }
                    pos++;
                } else if (line.charAt(pos) == '>') {   // 小心换行问题
                    pos++;
                    if (line.charAt(pos) == '=') {
                        tokens.add(new Token(Token.Type.GEQ, ">=", lineCnt));
                    } else {
                        pos--;
                        tokens.add(new Token(Token.Type.GRE, ">", lineCnt));
                    }
                    pos++;
                } else if (line.charAt(pos) == '=') {   // 小心换行问题
                    pos++;
                    if (line.charAt(pos) == '=') {
                        tokens.add(new Token(Token.Type.EQL, "==", lineCnt));
                    } else {
                        pos--;
                        tokens.add(new Token(Token.Type.ASSIGN, "=", lineCnt));
                    }
                    pos++;
                } else {
                    pos = addVariableToken(line, pos, lineCnt);
                }
            }
        }
    }

    private int addVariableToken(String line, int pos, int lineCnt) {
        int p = pos;
        char now = line.charAt(p);
        StringBuilder sb = new StringBuilder();
        sb.append(now);
        p++;
        if (now >= '0' && now <= '9') {
            while (p < line.length() && line.charAt(p) >= '0' && line.charAt(p) <= '9') {
                sb.append(line.charAt(p));
                p++;
            }
            tokens.add(new Token(Token.Type.INTCON, sb.toString(), lineCnt));
        } else if (now == '\'') {
            char tempt = line.charAt(p);
            if (tempt == '\\') {
                sb.append(tempt);
                p++;
            }
            sb.append(line.charAt(p));
            p++;
            sb.append(line.charAt(p));
            p++;
            tokens.add(new Token(Token.Type.CHRCON, sb.toString(), lineCnt));
        } else if (now == '\"') {
            while (p < line.length()) {
                char tempt = line.charAt(p);
                if (tempt == '\"') {
                    sb.append(tempt);
                    p++;
                    break;
                }
                if (tempt == '\\') {
                    sb.append(tempt);
                    p++;
                    sb.append(line.charAt(p));
                    p++;
                } else {
                    sb.append(tempt);
                    p++;
                }
            }
            tokens.add(new Token(Token.Type.STRCON, sb.toString(), lineCnt));
        } else if (now == '_' || (now >= 'a' && now <= 'z') || (now >= 'A' && now <= 'Z')){
            while (p < line.length() && line.charAt(p) != ' ' &&
                    !reservedChars.contains(String.valueOf(line.charAt(p)))) {
                sb.append(line.charAt(p));
                p++;
            }
            if (keywords.contains(sb.toString())) {
                addTkToken(sb.toString(), lineCnt);
            } else {
                tokens.add(new Token(Token.Type.IDENFR, sb.toString(), lineCnt));
            }
        }
        return p;
    }

    private void addTkToken(String str, int lineCnt) {
        if (str.equals("main")) {
            tokens.add(new Token(Token.Type.MAINTK, str, lineCnt));
        } else if (str.equals("const")) {
            tokens.add(new Token(Token.Type.CONSTTK, str, lineCnt));
        } else if (str.equals("int")) {
            tokens.add(new Token(Token.Type.INTTK, str, lineCnt));
        } else if (str.equals("char")) {
            tokens.add(new Token(Token.Type.CHARTK, str, lineCnt));
        } else if (str.equals("break")) {
            tokens.add(new Token(Token.Type.BREAKTK, str, lineCnt));
        } else if (str.equals("continue")) {
            tokens.add(new Token(Token.Type.CONTINUETK, str, lineCnt));
        } else if (str.equals("if")) {
            tokens.add(new Token(Token.Type.IFTK, str, lineCnt));
        } else if (str.equals("else")) {
            tokens.add(new Token(Token.Type.ELSETK, str, lineCnt));
        } else if (str.equals("for")) {
            tokens.add(new Token(Token.Type.FORTK, str, lineCnt));
        } else if (str.equals("getint")) {
            tokens.add(new Token(Token.Type.GETINTTK, str, lineCnt));
        } else if (str.equals("getchar")) {
            tokens.add(new Token(Token.Type.GETCHARTK, str, lineCnt));
        } else if (str.equals("printf")) {
            tokens.add(new Token(Token.Type.PRINTFTK, str, lineCnt));
        } else if (str.equals("return")) {
            tokens.add(new Token(Token.Type.RETURNTK, str, lineCnt));
        } else if (str.equals("void")) {
            tokens.add(new Token(Token.Type.VOIDTK, str, lineCnt));
        }
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public boolean getIsCorrect() {
        return is_correct;
    }

    public void move() {
        cur++;
    }

    public void back() {
        cur--;
    }

    public Token now() {
        return tokens.get(cur);
    }

    public int getCur() {
        return cur;
    }

    public void jump(int des) {
        cur = des;
    }

    public boolean notEnd() {
        return cur < tokens.size();
    }
}
