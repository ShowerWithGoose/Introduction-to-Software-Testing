package src.syntaxTree.treeNodes;

import src.lexicAnalysis.Token;
import src.syntaxTree.STNode;
import src.syntaxTree.enums.UnaryExpType;

/**
 * 一元表达式 UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
 */
public class UnaryExp extends STNode {
    public UnaryExpType unaryExpType;
    public PrimaryExp primaryExp;
    public Token ident;
    public Token lParent;
    public FuncRParams funcRParams;
    public Token rParent;
    public UnaryOp unaryOp;
    public UnaryExp unaryExp;
}
