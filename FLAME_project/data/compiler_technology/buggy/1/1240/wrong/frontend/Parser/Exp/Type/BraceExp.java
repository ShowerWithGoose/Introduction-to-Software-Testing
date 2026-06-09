package frontend.Parser.Exp.Type;

import frontend.Lexer.LexType;

public class BraceExp implements PEinterface{
    private Exp exp;
    private LexType left;
    private LexType right;

    public BraceExp(LexType left, Exp exp, LexType right)
    {
        this.left = left;
        this.exp = exp;
        this.right = right;
    }

    public int getLine()
    {
        return left.getLine();
    }

    public Exp getExp()
    {
        return exp;
    }

    @Override
    public String toString() {
        return left.toString() + exp.toString() + right.toString();
    }
}
