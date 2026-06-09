package frontend.Parser.statement.stmtfor;

import frontend.Parser.expression.Exp;
import frontend.Parser.expression.primaryexp.LVal;
import frontend.Parser.statement.StmtAssign;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class ForStmt
{
    private String type = "<ForStmt>";
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lVal, Token assign, Exp exp)
    {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    public ForStmt ParseForStmt(Tokenlist tokenlist)
    {
        LVal lVal1 = new LVal(null, null, null, null);
        LVal lVal2 = lVal1.ParseLVal(tokenlist);
        Token assign = tokenlist.getToken();
        tokenlist.ReadNext();
        //tokenlist.ReadNext();
        Exp exp1 = new Exp(null);
        Exp exp2 = exp1.ParseExp(tokenlist);
        //tokenlist.ReadNext();
        return new ForStmt(lVal2, assign, exp2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign.toString());
        sb.append(exp.toString());
        sb.append(type + '\n');
        return sb.toString();
    }
}
