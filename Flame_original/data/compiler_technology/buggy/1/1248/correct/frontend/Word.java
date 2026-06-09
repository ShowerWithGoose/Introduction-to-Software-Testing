package frontend;

public class Word {
    private int lineNum;
    private LexType type;
    private String token;
    private int num; // TODO Lexer待完成
    public Word(int lineNum, LexType type, String token, int num) {
        this.lineNum = lineNum;
        this.type = type;
        this.token = token;
        this.num = num;
    }

    public int getLineNum() {
        return lineNum;
    }

    public LexType getType() {
        return type;
    }

    public String getToken() {
        return token;
    }

    public int getNum() {
        return num;
    }

}
