package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

public class UnaryExp {
    public UnaryExpType type;
    public PrimaryExp primaryExp;
    public Word ident;
    public FuncRParams funcRParams;
    public UnaryOp unaryOp;
    public UnaryExp unaryExp;

    public enum UnaryExpType{
        primaryExp,
        ident,
        UnaryOp
    }
}
