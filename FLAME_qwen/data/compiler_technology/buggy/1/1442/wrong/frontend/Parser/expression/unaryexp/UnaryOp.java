package frontend.Parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class UnaryOp implements UnaryAll
{
    private String type = "<UnaryOp>";
    private Token op;
    private UnaryExp exp;

    public UnaryOp(Token op, UnaryExp exp)
    {
        this.op = op;
        this.exp = exp;
    }

    public UnaryOp ParseUnaryOp(Tokenlist tokenlist)
    {
        Token op1 = tokenlist.getToken();
        tokenlist.ReadNext();
        UnaryExp exp2 = new UnaryExp(null);
        UnaryExp exp1 = exp2.ParserUnary(tokenlist);
        return new UnaryOp(op1, exp1);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(op.toString());
        sb.append(type + "\n");
        sb.append(exp.toString());
        return sb.toString();
    }
}
