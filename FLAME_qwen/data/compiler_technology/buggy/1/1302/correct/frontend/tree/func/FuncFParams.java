package frontend.tree.func;

import frontend.tree.Node;

import java.util.ArrayList;

/**
 * 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
 */
public class FuncFParams extends Node {
    private final ArrayList<FuncFParam> params = new ArrayList<>();

    @Override
    public void semanticAnalysis() {
        for (Node child : getChildren()) {
            child.semanticAnalysis();
            if (child instanceof FuncFParam) {
                params.add((FuncFParam) child);
            }
        }
    }

    public ArrayList<FuncFParam> getParams() {
        return params;
    }
}
