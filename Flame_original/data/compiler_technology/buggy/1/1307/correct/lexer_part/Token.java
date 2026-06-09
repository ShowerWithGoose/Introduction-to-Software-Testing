package lexer_part;

import java.util.regex.Pattern;

public class Token {
    public enum TokenType {
        MAINTK(true, "main"),
        CONSTTK(true, "const"),
        INTTK(true, "int"),
        CHARTK(true, "char"),
        FLOATTK(true, "float"),
        BREAKTK(true, "break"),
        CONTINUETK(true, "continue"),
        IFTK(true, "if"),
        ELSETK(true, "else"),
        FORTK(true, "for"),
        WHILETK(true, "while"),
        GETINTTK(true, "getint"),
        GETCHARTK(true, "getchar"),
        PRINTFTK(true, "printf"),
        RETURNTK(true, "return"),
        VOIDTK(true, "void"),
        //QUOTE(false,"'"),

        IDENFR(false, "[_A-Za-z][_A-Za-z0-9]*"),
        FLOATCON(false, "[+-]?(\\d+\\.\\d*|\\.\\d+([eE][+-]?\\d+)?|\\d+\\.?\\d*[eE][+-]?\\d+|0[xX](?:\\.[0-9a-fA-F]+|[0-9a-fA-F]+\\.[0-9a-fA-F]*)(?:[pP][+-]?\\d+)?)"),
        INTCON(false, "(0[xX][0-9a-fA-F]+|0[0-7]+|[1-9][0-9]*|0)"),
        CHRCON(false, "'[\\x00-\\x7F]'"),
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
    private boolean endLine;

    public Token(TokenType type, String content, int lineIndex) {
        this.type = type;
        this.content = content;
        this.lineIndex = lineIndex;
        this.endLine = false;
    }

    public TokenType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineIndex() {
        return lineIndex;
    }

    @Override
    public String toString() {
        return type + " " + content + "\n";
    }

    public void setEndLine(boolean endLine) {
        this.endLine = endLine;
    }

    public boolean isEndLine() {
        return endLine;
    }
}
