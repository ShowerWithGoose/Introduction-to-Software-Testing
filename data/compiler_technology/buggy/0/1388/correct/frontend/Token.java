package frontend;

public class Token {
    public String word;
    public LexType type;
    public Integer line;

    public Token(String s, LexType lexType, int curLine) {
        word = s;
        type = lexType;
        line = curLine;
    }
}
