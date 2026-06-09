package frontend.Parser.statement;

import frontend.Parser.statement.block.StmtBlock;
import frontend.Parser.statement.stmtfor.StmtFor;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class Stmt
{
    private String type = "<Stmt>";
    private StmtAll stmt;

    public Stmt(StmtAll stmt)
    {
        this.stmt = stmt;
    }

    public Stmt ParseStmt(Tokenlist tokenlist)
    {
        StmtAll stmtAll = null;
        Token token = tokenlist.getToken();
        switch (token.getType())
        {
            case SEMICN:
                StmtExp stmtExp = new StmtExp(null, null);
                stmtAll = stmtExp.ParseStmtExp(tokenlist);
                break;
            case IFTK:
                StmtIf stmtIf = new StmtIf(null, null, null, null, null, null, null);
                stmtAll = stmtIf.ParseStmtIf(tokenlist);
                break;
            case FORTK:
                StmtFor stmtFor = new StmtFor(null, null, null, null, null, null, null, null);
                stmtAll = stmtFor.ParseStmtFor(tokenlist);
                break;
            case BREAKTK:
                StmtBreak stmtBreak = new StmtBreak(null, null);
                stmtAll = stmtBreak.ParseStmtBreak(tokenlist);
                break;
            case CONTINUETK:
                StmtContinue stmtContinue = new StmtContinue(null, null);
                stmtAll = stmtContinue.ParseStmtContinue(tokenlist);
                break;
            case RETURNTK:
                StmtReturn stmtReturn = new StmtReturn(null, null, null);
                stmtAll = stmtReturn.ParseStmtReturn(tokenlist);
                break;
            case PRINTFTK:
                StmtPrintf stmtPrintf = new StmtPrintf(null, null, null, null, null, null, null);
                stmtAll = stmtPrintf.ParseStmtPrintf(tokenlist);
                break;
            case LBRACE:
                StmtBlock stmtBlock = new StmtBlock(null, null, null);
                stmtAll = stmtBlock.ParseStmtBlock(tokenlist);
                break;
            case IDENFR:
                stmtAll = HandleIdent(tokenlist);
                break;
            case LPARENT:
            case PLUS:
            case MINU:
            case INTCON:
            case CHRCON:
                StmtExp stmtExp1 = new StmtExp(null, null);
                stmtAll = stmtExp1.ParseStmtExp(tokenlist);
                break;
            default:
                System.out.println(token.getType() + "  没有对应的Stmt");
        }
        return new Stmt(stmtAll);
    }

    private StmtAll HandleIdent(Tokenlist tokenlist)
    {
        int count = 0;
        int mode = 0;
        boolean flag = false;
        Token token = tokenlist.getToken();
        while (token.getType() != Token.Type.SEMICN && tokenlist.getCur_pos() + 1 < tokenlist.getTokenlist().size())
        {
            tokenlist.ReadNext();
            token = tokenlist.getToken();
            count += 1;
            if (token.getType() == Token.Type.ASSIGN)
            {
                flag = true;
            }
            if (token.getType() == Token.Type.GETINTTK || token.getType() == Token.Type.GETCHARTK)
            {
                mode = 1;
            }
        }
        tokenlist.ReadForwardNum(count);
        StmtAll stmtAll;
        if (flag)
        {
            if (mode == 1)
            {
                StmtGet stmtGet = new StmtGet(null, null, null, null, null, null);
                stmtAll = stmtGet.ParseStmtGet(tokenlist);
            }
            else
            {
                StmtAssign stmtAssign = new StmtAssign(null, null, null, null);
                stmtAll = stmtAssign.ParseAssign(tokenlist);
            }
        }
        else
        {
            StmtExp stmtExp1 = new StmtExp(null, null);
            stmtAll = stmtExp1.ParseStmtExp(tokenlist);
        }
        return stmtAll;
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(stmt.toString());
        sb.append(type + "\n");
        return sb.toString();
    }
}
