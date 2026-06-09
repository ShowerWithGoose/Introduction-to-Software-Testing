package frontend;

import java.util.ArrayList;

public class BranchNode extends Node {
    private UnitType unitType;
    private ArrayList<Node> children;

    public BranchNode(UnitType unitType) {
        this.unitType = unitType;
    }

    public void addChild(Node child) {
        children.add(child);
    }
}
