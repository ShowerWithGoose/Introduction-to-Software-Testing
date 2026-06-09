package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

public class PrimaryExp {
    public PrimaryExpType type;
    public Exp exp;
    public LVal lVal;
    public Word number;
    public Word character;
    public enum PrimaryExpType{
        exp,
        lVal,
        Number,
        Character
    }
}
