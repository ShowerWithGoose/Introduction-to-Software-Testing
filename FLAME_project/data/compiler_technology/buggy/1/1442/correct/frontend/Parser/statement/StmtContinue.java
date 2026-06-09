package frontend.Parser.statement;

import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class StmtContinue implements StmtAll
{
    private String type = "<Stmt>";
    private Token continuetk;
    private Token semicn;

    public StmtContinue(Token continuetk, Token semicn)
    {
        this.continuetk = continuetk;
        this.semicn = semicn;
    }

    public StmtContinue ParseStmtContinue(Tokenlist tokenlist)
    {
        Token token1 = tokenlist.getToken();
        tokenlist.ReadNext();
        Token semicn = null;
        if (tokenlist.getToken().getType() != Token.Type.SEMICN)
        {
            Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
            //System.out.println("StmtContinue + 缺少一个分号");
            tokenlist.ReadForward();
        }
        else
        {
            semicn = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        return new StmtContinue(token1, semicn);
    }

    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(continuetk.toString());
        if (semicn != null)
        {
            sb.append(semicn.toString());
        }
        return sb.toString();
    }


}
