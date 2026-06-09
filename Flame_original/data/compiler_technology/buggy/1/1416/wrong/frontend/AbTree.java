package frontend;

import java.util.ArrayList;

public class AbTree {
    private Pair val;
    private final ArrayList<AbTree> nodes;

    public AbTree() {
        this.nodes = new ArrayList<>();
    }

    public void setVal(Pair pair) {
        this.val = pair;
    }

    public void addNode(AbTree abTree) {
        this.nodes.add(abTree);
    }

    public Pair getVal() {
        return val;
    }

    public ArrayList<AbTree> getNodes() {
        return nodes;
    }
}
