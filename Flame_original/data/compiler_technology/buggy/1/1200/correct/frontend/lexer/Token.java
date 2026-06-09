package frontend.lexer;

public class Token {
    private LexType type;
    private String content;
    private int lineno;
    private Integer value;

    public Token(LexType type, String content, int lineno, Integer value) {
        this.type = type;
        this.content = content;
        this.lineno = lineno;
        this.value = value;
    }

    public boolean isFirstExp(){
        return type.equals(LexType.IDENFR) ||
                type.equals(LexType.INTCON) ||
                type.equals(LexType.STRCON) ||
                type.equals(LexType.CHRCON) ||
                type.equals(LexType.NOT) ||
                type.equals(LexType.PLUS) ||
                type.equals(LexType.MINU) ||
                type.equals(LexType.LPARENT);
    }

    public LexType getType() {
        return type;
    }

    public String getContent() {
        return content;
    }

    public int getLineno() {
        return lineno;
    }

    public Integer getValue() {
        return value;
    }

    public String getOutPut() {
        return type + " " + content + "\n";
    }
}
