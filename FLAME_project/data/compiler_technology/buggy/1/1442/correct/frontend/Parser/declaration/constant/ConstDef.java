package frontend.Parser.declaration.constant;

import frontend.Parser.declaration.constant.consinitval.ConstInitVal;
import frontend.Parser.expression.arithmeticalexp.ConstExp;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class ConstDef
{
    private String type = "<ConstDef>";
    private Token ident;

    private Token lbrack;

    private Token rbrack;

    private Token assign;
    private ConstExp constExp;
    private ConstInitVal constInitVal;

    public ConstDef(Token ident, Token lbrack, Token rbrack, Token assign, ConstExp constExp, ConstInitVal constInitVal)
    {
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
        this.assign = assign;
        this.constExp = constExp;
        this.constInitVal = constInitVal;
    }

    public ConstDef ParseConstDef(Tokenlist tokenlist)
    {
        Token ident = tokenlist.getToken();
        ConstExp constExp1 = null;
        ConstExp constExp2 = new ConstExp(null);
        tokenlist.ReadNext();
        Token lbrack = null;
        Token rbrack = null;
        Token assign = null;
        if (tokenlist.getToken().getType() == Token.Type.LBRACK)
        {
            lbrack = tokenlist.getToken();
            tokenlist.ReadNext();
            constExp1 = constExp2.ParseConstExp(tokenlist);
            //tokenlist.ReadNext();
            if (tokenlist.getToken().getType() != Token.Type.RBRACK)
            {
                Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'k'));
                System.out.println("ConstDef + 缺少一个右中括号");
                tokenlist.ReadForward();
            }
            else
            {
                rbrack = tokenlist.getToken();
            }
            tokenlist.ReadNext();
        }
        if (tokenlist.getToken().getType() != Token.Type.ASSIGN)
        {
            System.out.println("ConstDef + 缺少一个等号");
            tokenlist.ReadForward();
        }
        else
        {
            assign = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        ConstInitVal constInitVal1 = new ConstInitVal(null);
        ConstInitVal constInitVal2 = constInitVal1.ParseConstInitVal(tokenlist);
        return new ConstDef(ident, lbrack, rbrack, assign, constExp1, constInitVal2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (lbrack != null)
        {
            sb.append(lbrack.toString());
            sb.append(constExp.toString());
            sb.append(rbrack.toString());
        }
        sb.append(assign.toString());
        sb.append(constInitVal.toString());
        sb.append(type + "\n");
        return sb.toString();
    }

}
