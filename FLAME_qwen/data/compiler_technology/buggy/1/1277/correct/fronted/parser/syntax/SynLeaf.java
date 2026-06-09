package fronted.parser.syntax;

import fronted.lexer.Token;

import java.util.ArrayList;

public class SynLeaf implements SynNode {
    private Token token;
    public SynLeaf(Token token) {
        this.token = token;
    }

    @Override
    public boolean isLeaf() {
        return true;
    }

    @Override
    public ArrayList<SynNode> getChildren() {
        return null;
    }

    @Override
    public SynType getType() {
        return null;
    }

    @Override
    public Token getLeaf() {
        return token;
    }

    @Override
    public String toString() {
        return token.toString();
    }

    @Override
    public int getLine() {
        return token.getLine();
    }
}
