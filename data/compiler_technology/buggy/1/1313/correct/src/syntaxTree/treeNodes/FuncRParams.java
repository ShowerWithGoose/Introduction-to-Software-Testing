package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 函数实参表 FuncRParams → Exp { ',' Exp }
 */
public class FuncRParams extends STNode {
    public Exp exp;
    public ArrayList<Token> commaList;
    public ArrayList<Exp> exps;

    public FuncRParams() {
        this.commaList = new ArrayList<>();
        this.exps = new ArrayList<>();
    }
}
