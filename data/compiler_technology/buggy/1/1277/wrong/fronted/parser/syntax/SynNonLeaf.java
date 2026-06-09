package fronted.parser.syntax;

import fronted.lexer.Token;

import java.util.ArrayList;

public class SynNonLeaf implements SynNode {
    private final ArrayList<SynNode> children;
    private final SynType type;

    public SynNonLeaf(SynType type, ArrayList<SynNode> children) {
        this.type = type;
        this.children = children;
    }

    @Override
    public boolean isLeaf() {
        return false;
    }

    @Override
    public ArrayList<SynNode> getChildren() {
        return children;
    }

    @Override
    public SynType getType() {
        return type;
    }

    @Override
    public Token getLeaf() {
        return null;
    }

    @Override
    public String toString() {
        String res = "";
        for (SynNode node : children) {
            res += node;
        }
        // <BlockItem>, <Decl>, <BType>
        if (type != SynType.BlockItem && type != SynType.Decl && type != SynType.BType) {
            res += "<" + type + ">" + "\n";
        }
        return res;
    }

    @Override
    public int getLine() {
        return children.get(0).getLine();
    }
}
