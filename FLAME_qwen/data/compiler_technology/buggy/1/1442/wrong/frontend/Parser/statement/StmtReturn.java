package frontend.Parser.statement;

import frontend.Parser.expression.Exp;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class StmtReturn implements StmtAll
{
    private String type = "<Stmt>";
    private Token returntk;
    private Exp exp;
    private Token semicn;

    public StmtReturn(Token returntk, Exp exp, Token semicn)
    {
        this.returntk = returntk;
        this.exp = exp;
        this.semicn = semicn;
    }

    public StmtReturn ParseStmtReturn(Tokenlist tokenlist)
    {
        Token token1 = tokenlist.getToken();
        tokenlist.ReadNext();
        Exp exp1 = new Exp(null);
        Exp exp2 = null;
        Token semicn = null;
        if (tokenlist.getToken().getType() != Token.Type.SEMICN && tokenlist.getToken().getLine() == tokenlist.getForwardToken().getLine())
        {
            exp2 = exp1.ParseExp(tokenlist);
            //tokenlist.ReadNext();
            if (tokenlist.getToken().getType() != Token.Type.SEMICN)
            {
                Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
                System.out.println("StmtReturn + 缺少一个分号");
                tokenlist.ReadForward();
            }
            else
            {
                semicn = tokenlist.getToken();
            }
            tokenlist.ReadNext();
        }
        else
        {
            if (tokenlist.getToken().getType() == Token.Type.SEMICN)
            {
                semicn = tokenlist.getToken();
                tokenlist.ReadNext();
            }
            else
            {
                Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
                System.out.println("StmtReturn + 缺少一个分号");
            }
        }
        return new StmtReturn(token1, exp2, semicn);
    }

    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(returntk.toString());
        if (exp != null)
        {
            sb.append(exp.toString());
        }
        if (semicn != null)
        {
            sb.append(semicn.toString());
        }
        return sb.toString();
    }

}
