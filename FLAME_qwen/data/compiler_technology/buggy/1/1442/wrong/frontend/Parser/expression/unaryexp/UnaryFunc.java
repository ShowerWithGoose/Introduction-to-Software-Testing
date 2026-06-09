package frontend.Parser.expression.unaryexp;

import frontend.Parser.expression.FuncRParams;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Tokenlist;
import frontend.lexer.Token;

import java.util.ArrayList;

public class UnaryFunc implements UnaryAll
{
    private Token name;
    private Token lparent;
    private Token rparent;
    private FuncRParams funcRParams;

    public UnaryFunc(Token name, Token lparent, Token rparent, FuncRParams funcRParams)
    {
        this.name = name;
        this.lparent = lparent;
        this.rparent = rparent;
        this.funcRParams = funcRParams;
    }

    public UnaryFunc ParseUnaryfunc(Tokenlist tokenlist)
    {
        Token name1 = tokenlist.getToken();
        tokenlist.ReadNext();
        Token lparent = tokenlist.getToken();
        Token rparent = null;
        FuncRParams funcRParams1 = new FuncRParams(null, null);
        FuncRParams funcRParams2 = funcRParams1.ParseFuncRParams(tokenlist);
        if (tokenlist.getToken().getType() == Token.Type.RPARENT)
        {
            rparent = tokenlist.getToken();
            tokenlist.ReadNext();
        }
        else
        {
            Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'j'));
            System.out.println("MainFuncDef + 缺少一个右小括号");
        }
        return new UnaryFunc(name1, lparent, rparent, funcRParams2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(name.toString());
        sb.append(lparent.toString());
        sb.append(funcRParams.toString());
        if (rparent != null)
        {
            sb.append(rparent.toString());
        }
        return sb.toString();
    }
}
