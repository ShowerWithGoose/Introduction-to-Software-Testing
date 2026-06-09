package frontend.Parser.declaration.variable;

import frontend.Parser.declaration.constant.ConstDef;
import frontend.Parser.declaration.constant.consinitval.ConstInitVal;
import frontend.Parser.declaration.variable.variableinitval.VarInitVal;
import frontend.Parser.expression.arithmeticalexp.ConstExp;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class VarDef
{
    private String type = "<VarDef>";
    private Token ident;
    private Token lbrack;

    private Token rbrack;

    private Token assign;
    private ConstExp constExp;
    private VarInitVal varInitVal;

    public VarDef(Token ident, Token lbrack, Token rbrack, Token assign, ConstExp constExp, VarInitVal varInitVal)
    {
        this.ident = ident;
        this.lbrack = lbrack;
        this.rbrack = rbrack;
        this.assign = assign;
        this.constExp = constExp;
        this.varInitVal = varInitVal;
    }

    public VarDef ParseVarDef(Tokenlist tokenlist)
    {
        Token ident = tokenlist.getToken();
        ConstExp constExp1 = null;
        ConstExp constExp2 = new ConstExp(null);
        VarInitVal varInitVal1 = new VarInitVal(null);
        VarInitVal varInitVal2 = null;
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
                System.out.println("VarDef + 缺少一个右中括号");
                tokenlist.ReadForward();
            }
            else
            {
                rbrack = tokenlist.getToken();
            }
            tokenlist.ReadNext();
        }
        if (tokenlist.getToken().getType() == Token.Type.ASSIGN)
        {
            assign = tokenlist.getToken();
            tokenlist.ReadNext();
            varInitVal2 = varInitVal1.ParseVarInitVal(tokenlist);
        }
        return new VarDef(ident, lbrack, rbrack, assign, constExp1, varInitVal2);
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
        if (assign != null)
        {
            sb.append(assign.toString());
            sb.append(varInitVal.toString());
        }
        sb.append(type + "\n");
        return sb.toString();
    }
}
