package fronted.parser.syntax;

import fronted.lexer.Token;

import java.util.ArrayList;

public interface SynNode {
    boolean isLeaf();

    ArrayList<SynNode> getChildren();

    SynType getType();

    Token getLeaf();

    int getLine();
}
