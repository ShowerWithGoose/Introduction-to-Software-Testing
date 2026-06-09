package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;
import src.syntaxTree.enums.ConstInitValType;

import java.util.ArrayList;

/**
 * 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
 */
public class ConstInitVal extends STNode {
    public ConstInitValType constInitValType;
    public ConstExp constExp; // 只需一个
    public Token lBrace;
    public ArrayList<Token> commaList;
    public ArrayList<ConstExp> constExps;
    public Token rBrace;
    public Token stringConst;

    public ConstInitVal() {
        this.commaList = new ArrayList<>();
        this.constExps = new ArrayList<ConstExp>();
    }
}
