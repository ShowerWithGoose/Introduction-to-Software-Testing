package Symbol;

import node.Token;
import node.TreeNode;

public class SignalNode implements Signal {
    private TreeNode node;
    private SignalType type;
    private String ident;

    public SignalNode(TreeNode node,SignalType type) {
        this.node = node;
        this.type = type;
        this.ident = ((Token) node).getIdent();
    }


    public boolean equalIdent(String i) {
        if (i.equals(ident)) {
            return true;
        }
        return false;
    }

    public SignalType getType() {
        return type;
    }

    @Override
    public void print() {
        System.out.print(ident + " " + type + "\n");
    }
}
