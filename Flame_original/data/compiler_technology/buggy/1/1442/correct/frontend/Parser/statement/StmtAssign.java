package frontend.Parser.statement;

import frontend.Parser.expression.Exp;
import frontend.Parser.expression.primaryexp.LVal;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class StmtAssign implements StmtAll
{
    private String type = "<Stmt>";
    private LVal lVal;
    private Token assign;
    private Token semicn;
    private Exp exp;

    public StmtAssign(LVal lVal, Token assign, Token semicn, Exp exp)
    {
        this.lVal = lVal;
        this.assign = assign;
        this.semicn = semicn;
        this.exp = exp;
    }

    public StmtAssign ParseAssign(Tokenlist tokenlist)
    {
        LVal lVal1 = new LVal(null, null, null, null);
        LVal lVal2 = lVal1.ParseLVal(tokenlist);
        Token assign = tokenlist.getToken();
        tokenlist.ReadNext();
        //tokenlist.ReadNext();
        Exp exp1 = new Exp(null);
        Exp exp2 = exp1.ParseExp(tokenlist);
        //tokenlist.ReadNext();
        Token semicn = null;
        if (tokenlist.getToken().getType() != Token.Type.SEMICN)
        {
            Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
            System.out.println("StmtAssign + 缺少一个分号");
            tokenlist.ReadForward();
        }
        else
        {
            semicn = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        return new StmtAssign(lVal2, assign, semicn, exp2);
    }

    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign.toString());
        sb.append(exp.toString());
        if (semicn != null)
        {
            sb.append(semicn);
        }
        return sb.toString();
    }
}
