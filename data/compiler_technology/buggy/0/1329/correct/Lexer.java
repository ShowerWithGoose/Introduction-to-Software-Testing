import java.util.Objects;

public class Lexer {
    private final String input;
    private int pos = 0; //指针
    private String leiBie;
    private int zhushi;
    private int ifEnd;
    private int right = 1;
    private String curToken;
    private String charSet = "!&|+-*/%<>=(){}[];,";
    private String charSet1 = "'\"";

    public Lexer(String input, int zhushi) {
        this.input = input;
        this.zhushi = zhushi;
        this.ifEnd = 0;
        this.next();
    }

    public void next() {
        if (pos == input.length()) {
            ifEnd = 1;
            return;
        }
        if (zhushi == 1) {
            ifEnd = 1;
            this.zhushi = 0;
            return;
        } else if (zhushi == -1) {
            if (input.charAt(pos) == '*' && input.charAt(pos + 1) == '/') {
                pos = pos + 2;
                this.zhushi = 0;
            } else {
                pos = pos + 1;
            }
            next();
        } else {
            char c = input.charAt(pos);
            if (Character.isDigit(c)) { //Java内置的方法，用于判断一个字符是否为数字字符。
                curToken = getNumber();
            } else if (Character.isWhitespace(c)) {
                pos += 1;
                next();
                //curToken = String.valueOf(c); //String.valueOf(c) 是一个静态方法，接受一个 char 参数，并返回一个表示该字符的字符串。
            } else if (charSet.indexOf(c) >= 0) {
                curToken = getFuhao();
            } else if (charSet1.indexOf(c) >= 0) {
                curToken = getBianliang();
            } else {
                curToken = getStr();
            }
        }
    }

    private String getFuhao() {
        StringBuilder sb = new StringBuilder();
        if (charSet.indexOf(input.charAt(pos)) != 6) {
            sb.append(input.charAt(pos));
            pos++;
            if (pos < input.length()) {
                if (charSet.indexOf(input.charAt(pos)) == 10 && charSet.indexOf(input.charAt(pos - 1)) == 0) {
                    sb.append(input.charAt(pos));
                    pos++; //!=
                } else if (charSet.indexOf(input.charAt(pos - 1)) == 1 && charSet.indexOf(input.charAt(pos)) == 1) {
                    sb.append(input.charAt(pos));
                    pos++; //&&
                } else if (charSet.indexOf(input.charAt(pos - 1)) == 2 && charSet.indexOf(input.charAt(pos)) == 2) {
                    sb.append(input.charAt(pos));
                    pos++; ////
                } else if (charSet.indexOf(input.charAt(pos - 1)) == 8 && charSet.indexOf(input.charAt(pos)) == 10) {
                    sb.append(input.charAt(pos));
                    pos++; //<=
                } else if (charSet.indexOf(input.charAt(pos - 1)) == 9 && charSet.indexOf(input.charAt(pos)) == 10) {
                    sb.append(input.charAt(pos));
                    pos++; //>=
                } else if (charSet.indexOf(input.charAt(pos - 1)) == 10 && charSet.indexOf(input.charAt(pos)) == 10) {
                    sb.append(input.charAt(pos));
                    pos++; //==
                }
            }
        } else {
            sb.append(input.charAt(pos));
            pos++;
            if (pos < input.length()) {
                if (charSet.indexOf(input.charAt(pos)) == 6) {
                    this.zhushi = 1;
                    pos = pos + 1;
                } else if (charSet.indexOf(input.charAt(pos)) == 5) {
                    this.zhushi = -1;
                    pos = pos + 1;
                }
            }
        }
        setLeiBie1(sb.toString());
        return sb.toString();
    }

    private String getStr() {
        StringBuilder sb = new StringBuilder();
        while (pos < input.length() && !Character.isWhitespace(input.charAt(pos)) &&
                charSet.indexOf(input.charAt(pos)) < 0 &&
                charSet1.indexOf(input.charAt(pos)) < 0) {
            sb.append(input.charAt(pos));
            ++pos;
        }
        setLeiBie(sb.toString());
        return sb.toString();
    }

    private String getNumber() {
        StringBuilder sb = new StringBuilder();
        while (pos < input.length() && Character.isDigit(input.charAt(pos))) {
            sb.append(input.charAt(pos));
            ++pos;
        }
        leiBie = "INTCON";
        return sb.toString();
    }

    private String getBianliang() {
        StringBuilder sb = new StringBuilder();
        sb.append(input.charAt(pos));
        pos++;
        while (pos < input.length() && charSet1.indexOf(input.charAt(pos)) < 0) {
            sb.append(input.charAt(pos));
            if (input.charAt(pos) == '\\') {
                ++pos;
                sb.append(input.charAt(pos));
            }
            ++pos;
        }
        sb.append(input.charAt(pos));
        if (charSet1.indexOf(input.charAt(pos)) == 0) {
            leiBie = "CHRCON";
        } else {
            leiBie = "STRCON";
        }
        ++pos;
        return sb.toString();
    }

    public int ifZhushi() {
        return zhushi;
    }

    public String peek() {
        return this.curToken;
    }

    public String getLeiBie() {
        return leiBie;
    }

    public int getIfEnd() {
        return ifEnd;
    }

    public int getRight() {
        return right;
    }

    public void setRight() {
        this.right = 1;
    }

    private void setLeiBie(String str) {
        if (Objects.equals(str, "main")) {
            leiBie = "MAINTK";
        } else if (Objects.equals(str, "const")) {
            leiBie = "CONSTTK";
        } else if (Objects.equals(str, "int")) {
            leiBie = "INTTK";
        } else if (Objects.equals(str, "char")) {
            leiBie = "CHARTK";
        } else if (Objects.equals(str, "break")) {
            leiBie = "BREAKTK";
        } else if (Objects.equals(str, "continue")) {
            leiBie = "CONTINUETK";
        } else if (Objects.equals(str, "if")) {
            leiBie = "IFTK";
        } else if (Objects.equals(str, "else")) {
            leiBie = "ELSETK";
        } else if (Objects.equals(str, "for")) {
            leiBie = "FORTK";
        } else if (Objects.equals(str, "getint")) {
            leiBie = "GETINTTK";
        } else if (Objects.equals(str, "getchar")) {
            leiBie = "GETCHARTK";
        } else if (Objects.equals(str, "printf")) {
            leiBie = "PRINTFTK";
        } else if (Objects.equals(str, "return")) {
            leiBie = "RETURNTK";
        } else if (Objects.equals(str, "void")) {
            leiBie = "VOIDTK";
        } else {
            leiBie = "IDENFR";
        }
    }

    private void setLeiBie1(String str) {
        if (Objects.equals(str, "!")) {
            leiBie = "NOT";
        } else if (Objects.equals(str, "&&")) {
            leiBie = "AND";
        } else if (Objects.equals(str, "&")) {
            this.right = 0;
            leiBie = "AND";
        } else if (Objects.equals(str, "||")) {
            leiBie = "OR";
        } else if (Objects.equals(str, "|")) {
            this.right = 0;
            leiBie = "OR";
        } else if (Objects.equals(str, "+")) {
            leiBie = "PLUS";
        } else if (Objects.equals(str, "-")) {
            leiBie = "MINU";
        } else if (Objects.equals(str, "*")) {
            leiBie = "MULT";
        } else if (Objects.equals(str, "/")) {
            leiBie = "DIV";
        } else if (Objects.equals(str, "%")) {
            leiBie = "MOD";
        } else if (Objects.equals(str, "<")) {
            leiBie = "LSS";
        } else if (Objects.equals(str, "<=")) {
            leiBie = "LEQ";
        } else if (Objects.equals(str, ">")) {
            leiBie = "GRE";
        } else if (Objects.equals(str, ">=")) {
            leiBie = "GEQ";
        } else if (Objects.equals(str, "==")) {
            leiBie = "EQL";
        } else if (Objects.equals(str, "!=")) {
            leiBie = "NEQ";
        } else if (Objects.equals(str, "=")) {
            leiBie = "ASSIGN";
        } else if (Objects.equals(str, ";")) {
            leiBie = "SEMICN";
        } else if (Objects.equals(str, ",")) {
            leiBie = "COMMA";
        } else if (Objects.equals(str, "(")) {
            leiBie = "LPARENT";
        } else if (Objects.equals(str, ")")) {
            leiBie = "RPARENT";
        } else if (Objects.equals(str, "[")) {
            leiBie = "LBRACK";
        } else if (Objects.equals(str, "]")) {
            leiBie = "RBRACK";
        } else if (Objects.equals(str, "{")) {
            leiBie = "LBRACE";
        } else if (Objects.equals(str, "}")) {
            leiBie = "RBRACE";
        } else {
            leiBie = null;
        }
    }
}
