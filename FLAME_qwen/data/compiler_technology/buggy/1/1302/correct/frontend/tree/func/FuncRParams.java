package frontend.tree.func;

import frontend.tree.Node;
import frontend.tree.exp.Exp;

import java.util.ArrayList;

/**
 * 函数实参表 FuncRParams → Exp { ',' Exp }
 */
public class FuncRParams extends Node {
    private ArrayList<Exp> params = new ArrayList<>();

    @Override
    public void semanticAnalysis() {
        for (Node child : children) {
            child.semanticAnalysis();
            if (child instanceof Exp) {
                params.add((Exp) child);
            }
        }
    }

    public ArrayList<Exp> getParams() {
        return params;
    }
}
