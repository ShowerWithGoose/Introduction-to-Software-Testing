package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;
import src.syntaxTree.enums.InitValType;

import java.util.ArrayList;

/**
 * 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
 */
public class InitVal extends STNode {
    public InitValType initValType;
    public Exp exp; // 只需一个
    public Token lBrace;
    public ArrayList<Token> commaList;
    public ArrayList<Exp> exps;
    public Token rBrace;
    public Token stringConst;

    public InitVal() {
        this.commaList = new ArrayList<>();
        this.exps = new ArrayList<Exp>();
    }
}
