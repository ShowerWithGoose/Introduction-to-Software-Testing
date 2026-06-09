package frontend.Parser.statement;

import frontend.Parser.expression.primaryexp.LVal;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class StmtGet implements StmtAll
{
    private String type = "<Stmt>";
    private LVal lVal;
    private Token assign;
    private Token gettk;

    private Token lparent;
    private Token rparent;
    private Token semicn;

    public StmtGet(LVal lVal, Token assign, Token gettk, Token lparent, Token rparent, Token semicn)
    {
        this.gettk = gettk;
        this.assign = assign;
        this.lVal = lVal;
        this.lparent = lparent;
        this.rparent = rparent;
        this.semicn = semicn;
    }

    public StmtGet ParseStmtGet(Tokenlist tokenlist)
    {
        LVal lVal1 = new LVal(null, null, null, null);
        LVal lVal2 = lVal1.ParseLVal(tokenlist);
        Token assign = tokenlist.getToken();
        tokenlist.ReadNext();
        Token token1 = tokenlist.getToken();
        tokenlist.ReadNext();
        Token lparent = null;
        Token rparent = null;
        Token semicn = null;
        if (tokenlist.getToken().getType() != Token.Type.LPARENT)
        {
            System.out.println("StmtGet + 缺少一个左小括号");
            tokenlist.ReadForward();
        }
        else
        {
            lparent = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        if (tokenlist.getToken().getType() != Token.Type.RPARENT)
        {
            Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'j'));
            System.out.println("StmtGet + 缺少一个右小括号");
            tokenlist.ReadForward();
        }
        else
        {
            rparent = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        if (tokenlist.getToken().getType() != Token.Type.SEMICN)
        {
            Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
            System.out.println("StmtGet + 缺少一个分号");
            tokenlist.ReadForward();
        }
        else
        {
            semicn = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        return new StmtGet(lVal2, assign, token1, lparent, rparent, semicn);
    }

    @Override
    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign.toString());
        sb.append(gettk.toString());
        sb.append(lparent.toString());
        sb.append(rparent.toString());
        if (semicn != null)
        {
            sb.append(semicn.toString());
        }
        return sb.toString();
    }

}
