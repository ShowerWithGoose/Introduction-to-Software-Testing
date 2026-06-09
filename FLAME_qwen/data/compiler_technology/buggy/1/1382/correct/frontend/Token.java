package frontend;

public class Token {
    private LexType lexType;
    private Long value;
    private String str;
    private int lineNum;

    public Token(LexType lexType,  Long value, String str, int lineNum) {
        this.str = str;
        this.value = value;
        this.lexType = lexType;
        this.lineNum = lineNum;
    }

    public LexType getLexType() {
        return lexType;
    }

    public String getStr() {
        return str;
    }

    public int getLineNum() {
        return lineNum;
    }

    public String toPrint() {
        return lexType + " " + str +  "\n";
    }
}
