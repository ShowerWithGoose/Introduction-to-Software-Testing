package Frontend;

public class Token {
    private LexType type;
    private StringBuilder token;
    private int lineNum;

    public Token() {
        token = new StringBuilder();
        lineNum = 0;
    }

    public void addToken(Character c,int num) {
        token.append(c);
        lineNum = num;
    }

    public void setType(LexType t) {
        type = t;
    }

    public StringBuilder getToken() {
        return token;
    }

    public LexType getType() {
        return type;
    }

    public int getLineNum() {
        return lineNum;
    }
}
