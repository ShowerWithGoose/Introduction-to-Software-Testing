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

    public GramNode token2node(GramNode parent){
        GramNode node = new GramNode();
        node.parent = parent;
        node.leaf = this;
        return node;
    }

    @Override
    public String toString() {
        return type + " " + word + "\n";
    }
}
