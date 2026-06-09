package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;

import java.util.ArrayList;

/**
 * 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
 */
public class ConstDecl extends STNode {
    public Token tokenConst; // 'const'
    public BType bType;
    public ConstDef constDef;
    public ArrayList<Token> commaList; // ','
    public ArrayList<ConstDef> constDefs;
    public Token semicolon; // ';'

    public ConstDecl() {
        this.commaList = new ArrayList<>();
        this.constDefs = new ArrayList<>();
    }
}
