import java.util.regex.Pattern;

public class Token {
    public enum TokenType {
        MAINTK(true, "main"),
        CONSTTK(true, "const"),
        INTTK(true, "int"),
        CHARTK(true,"char"),
        BREAKTK(true, "break"),
        CONTINUETK(true, "continue"),
        IFTK(true, "if"),
        ELSETK(true, "else"),
        FORTK(true, "for"),
        GETINTTK(true, "getint"),
        GETCHARTK(true,"getchar"),
        PRINTFTK(true, "printf"),
        RETURNTK(true, "return"),
        VOIDTK(true, "void"),
        //QUOTE(false,"'"),

        IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
        INTCON(false, "[0-9]+"),
        CHRCON(false,"'[\\x00-\\x7F]'"),
        STRCON(false, "\\\"[^\\\"]*\\\""),

        NEQ(false, "!="),
        NOT(false, "!"),
        AND(false, "&"),
        OR(false, "\\|"),
        PLUS(false, "\\+"),
        MINU(false, "-"),

        MULT(false, "\\*"),
        DIV(false, "/"),
        MOD(false, "%"),
        LEQ(false, "<="),
        GEQ(false, ">="),
        LSS(false, "<"),

        GRE(false, ">"),

        EQL(false, "=="),

        ASSIGN(false, "="),
        SEMICN(false, ";"),
        COMMA(false, ","),
        LPARENT(false, "\\("),
        RPARENT(false, "\\)"),
        LBRACK(false, "\\["),
        RBRACK(false, "]"),
        LBRACE(false, "\\{"),
        RBRACE(false, "}");


        private final Pattern pattern;
        private final boolean isGreed;

        TokenType(boolean isGreed, String patternString) {
            this.isGreed = isGreed;
            if (isGreed) {
                pattern = Pattern.compile("^" + patternString + "(?![_A-Za-z0-9])");
            } else {
                pattern = Pattern.compile("^" + patternString);
            }
        }

        public Pattern getPattern() {
            return pattern;
        }
    }

    private TokenType type;
    private String content;
    private int lineIndex;

    public Token(TokenType type, String content, int lineIndex) {
        this.type = type;
        this.content = content;
        this.lineIndex = lineIndex;
    }

    public TokenType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }
}
