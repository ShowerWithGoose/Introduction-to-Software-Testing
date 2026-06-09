package frontend.Parser.function;

import frontend.Parser.statement.block.StmtBlock;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class MainFuncDef
{
    private String type = "<MainFuncDef>";
    private Token inttk;
    private Token maintk;
    private Token lparent;
    private Token rparent;
    private StmtBlock stmtBlock;

    public MainFuncDef(Token inttk, Token maintk, Token lparent, Token rparent, StmtBlock stmtBlock)
    {
        this.inttk = inttk;
        this.maintk = maintk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.stmtBlock = stmtBlock;
    }

    public MainFuncDef ParseMainFuncDef(Tokenlist tokenlist)
    {
        Token token1 = tokenlist.getToken();
        tokenlist.ReadNext();
        Token token2 = tokenlist.getToken();
        tokenlist.ReadNext();
        Token lparent = null;
        Token rparent = null;
        if (tokenlist.getToken().getType() != Token.Type.LPARENT)
        {
            System.out.println("MainFuncDef + 缺少一个左小括号");
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
            System.out.println("MainFuncDef + 缺少一个右小括号");
            tokenlist.ReadForward();
        }
        else
        {
            rparent = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        StmtBlock stmtBlock1 = new StmtBlock(null, null, null);
        StmtBlock stmtBlock2 = stmtBlock1.ParseStmtBlock(tokenlist);
        return new MainFuncDef(token1, token2, lparent, rparent, stmtBlock2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(inttk.toString());
        sb.append(maintk.toString());
        if (lparent != null)
        {
            sb.append(lparent.toString());
        }
        if (rparent != null)
        {
            sb.append(rparent.toString());
        }
        sb.append(stmtBlock.toString());
        sb.append(type + "\n");
        return sb.toString();
    }
}
