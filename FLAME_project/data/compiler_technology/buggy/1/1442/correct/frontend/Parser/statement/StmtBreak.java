package frontend.Parser.statement;

import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class StmtBreak implements StmtAll
{
    private String type = "<Stmt>";
    private Token breaktk;
    private Token semicn;

    public StmtBreak(Token breaktk, Token semicn)
    {
        this.breaktk = breaktk;
        this.semicn = semicn;
    }

    public StmtBreak ParseStmtBreak(Tokenlist tokenlist)
    {
        Token token1 = tokenlist.getToken();
        tokenlist.ReadNext();
        Token semicn = null;
        if (tokenlist.getToken().getType() != Token.Type.SEMICN)
        {
            Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
            System.out.println("StmtBreak + 缺少一个分号");
            tokenlist.ReadForward();
        }
        else
        {
            semicn = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        return new StmtBreak(token1, semicn);
    }

    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(breaktk.toString());
        if (semicn != null)
        {
            sb.append(semicn.toString());
        }
        return sb.toString();
    }

}
