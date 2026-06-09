package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
 */
public class VarDecl extends STNode {
    public BType bType;
    public VarDef varDef;
    public ArrayList<Token> commaList;
    public ArrayList<VarDef> varDefs;
    public Token semicolon;

    public VarDecl() {
        this.commaList = new ArrayList<>();
        this.varDefs = new ArrayList<>();
    }
}
