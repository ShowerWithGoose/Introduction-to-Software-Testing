package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
 */
public class FuncFParams extends STNode {
    public FuncFParam funcFParam;
    public ArrayList<Token> commaList;
    public ArrayList<FuncFParam> funcFParams;

    public FuncFParams() {
        this.commaList = new ArrayList<>();
        this.funcFParams = new ArrayList<FuncFParam>();
    }
}
