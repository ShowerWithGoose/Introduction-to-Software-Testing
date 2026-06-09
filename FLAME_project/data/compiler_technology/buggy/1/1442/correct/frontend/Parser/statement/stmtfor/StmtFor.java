package frontend.Parser.statement.stmtfor;

import frontend.Parser.expression.CondExp;
import frontend.Parser.statement.Stmt;
import frontend.Parser.statement.StmtAll;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

import java.util.ArrayList;

public class StmtFor implements StmtAll
{
    private Token fortk;
    private Token lparent;
    private Token rparent;
    private ForStmt forStmt1;
    private CondExp condExp;
    private ArrayList<Token> semicns;
    private ForStmt forStmt2;
    private Stmt stmt;

    public StmtFor(Token fortk, Token lparent, Token rparent, ForStmt forStmt1, CondExp condExp, ArrayList<Token> semicns, ForStmt forStmt2, Stmt stmt)
    {
        this.fortk = fortk;
        this.lparent = lparent;
        this.rparent = rparent;
        this.forStmt1 = forStmt1;
        this.forStmt2 = forStmt2;
        this.semicns = semicns;
        this.condExp = condExp;
        this.stmt = stmt;
    }

    public StmtFor ParseStmtFor(Tokenlist tokenlist)
    {
        Token fortk = tokenlist.getToken();
        Token lparent = null;
        Token rparent = null;
        tokenlist.ReadNext();
        if (tokenlist.getToken().getType() != Token.Type.LPARENT)
        {
            System.out.println("StmtFor + 缺少一个左小括号");
            tokenlist.ReadForward();
        }
        else
        {
            lparent = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        ForStmt forStmt1 = new ForStmt(null, null, null);
        ForStmt forStmt2 = null;
        ForStmt forStmt3 = null;
        CondExp condExp1 = new CondExp(null);
        CondExp condExp2 = null;
        ArrayList<Token> semicns = new ArrayList<>();
        if (tokenlist.getToken().getType() != Token.Type.SEMICN)
        {
            forStmt2 = forStmt1.ParseForStmt(tokenlist);
            //tokenlist.ReadNext();
            if (tokenlist.getToken().getType() != Token.Type.SEMICN)
            {
                Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
                System.out.println("StmtFor + 缺少一个分号");
                tokenlist.ReadForward();
            }
            else
            {
                semicns.add(tokenlist.getToken());
            }
        }
        else
        {
            semicns.add(tokenlist.getToken());
        }
        tokenlist.ReadNext();
        if (tokenlist.getToken().getType() != Token.Type.SEMICN)
        {
            condExp2 = condExp1.ParseCondExp(tokenlist);
            //tokenlist.ReadNext();
            if (tokenlist.getToken().getType() != Token.Type.SEMICN)
            {
                Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'i'));
                System.out.println("StmtFor + 缺少一个分号");
                tokenlist.ReadForward();
            }
            else
            {
                semicns.add(tokenlist.getToken());
            }
        }
        else
        {
            semicns.add(tokenlist.getToken());
        }
        tokenlist.ReadNext();
        if (tokenlist.getToken().getType() != Token.Type.RPARENT)
        {
            forStmt3 = forStmt1.ParseForStmt(tokenlist);
            //tokenlist.ReadNext();
            if (tokenlist.getToken().getType() != Token.Type.RPARENT)
            {
                Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'k'));
                System.out.println("StmtFor + 缺少一个右小括号");
                tokenlist.ReadForward();
            }
            else
            {
                rparent = tokenlist.getToken();
            }
        }
        else
        {
            rparent = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        Stmt stmt1 = new Stmt(null);
        Stmt stmt2 = stmt1.ParseStmt(tokenlist);
        //tokenlist.ReadNext();
        return new StmtFor(fortk, lparent, rparent, forStmt2, condExp2, semicns, forStmt3, stmt2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(fortk.toString());
        sb.append(lparent.toString());
        if (forStmt1 != null)
        {
            sb.append(forStmt1.toString());
        }
        sb.append(semicns.get(0).toString());
        if (condExp != null)
        {
            sb.append(condExp.toString());
        }
        sb.append(semicns.get(1).toString());
        if (forStmt2 != null)
        {
            sb.append(forStmt2.toString());
        }
        sb.append(rparent.toString());
        sb.append(stmt.toString());
        return sb.toString();
    }
}
