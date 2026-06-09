package frontend.Parser.expression.unaryexp;

import frontend.Parser.expression.AllExp;
import frontend.Parser.expression.arithmeticalexp.ArithExpAll;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class UnaryExp implements AllExp, ArithExpAll
{
    private String type = "<UnaryExp>";
    private UnaryAll unaryexp;

    public UnaryExp(UnaryAll unaryexp)
    {
        this.unaryexp = unaryexp;
    }

    public UnaryExp ParserUnary(Tokenlist tokenlist)
    {
        Token token = tokenlist.getToken();
        UnaryAll unaryexp1;
        if (token.getType() == Token.Type.IDENFR && tokenlist.getNextToken().getType() == Token.Type.LPARENT)
        {
            UnaryFunc unaryFunc = new UnaryFunc(null, null, null, null);
            unaryexp1 = unaryFunc.ParseUnaryfunc(tokenlist);
        }
        else if (token.getType() == Token.Type.PLUS || token.getType() == Token.Type.MINU || token.getType() == Token.Type.NOT)
        {
            UnaryOp unaryOp = new UnaryOp(null, null);
            unaryexp1 = unaryOp.ParseUnaryOp(tokenlist);
        }
        else
        {
            UnaryPriExp unaryPriExp = new UnaryPriExp(null);
            unaryexp1 = unaryPriExp.ParseUnaryPriExp(tokenlist);
        }
        return new UnaryExp(unaryexp1);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryexp.toString());
        sb.append(type + "\n");
        return sb.toString();
    }
}
