package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * Stmt â†’ 'printf''('StringConst {','Exp}')'';' // i j
 */
public class StmtPrintf extends STNode {
    public Token printf;
    public Token lParent;
    public Token stringConst;
    public ArrayList<Token> commaList;
    public ArrayList<Exp> exps;
    public Token rParent;
    public Token semicolon;

    public StmtPrintf() {
        this.commaList = new ArrayList<>();
        this.exps = new ArrayList<Exp>();
    }
}
