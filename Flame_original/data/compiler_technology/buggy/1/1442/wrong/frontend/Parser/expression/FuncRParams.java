package frontend.Parser.expression;

import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

import java.util.ArrayList;

public class FuncRParams implements AllExp
{
    private String type = "<FuncRParams>";
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParams(ArrayList<Token> commas, ArrayList<Exp> exps)
    {
        this.commas = commas;
        this.exps = exps;
    }

    public FuncRParams ParseFuncRParams(Tokenlist tokenlist)
    {
        ArrayList<Token> commas1 = new ArrayList<>();
        ArrayList<Exp> exps1 = new ArrayList<>();
        Exp exp = new Exp(null);
        tokenlist.ReadNext();
        if (tokenlist.getToken().getType() != Token.Type.RPARENT && tokenlist.getToken().getLine() == tokenlist.getForwardToken().getLine())
        {
            exps1.add(exp.ParseExp(tokenlist));
        }
        //tokenlist.ReadNext();
        while (tokenlist.getToken().getType().equals(Token.Type.COMMA))
        {
            commas1.add(tokenlist.getToken());
            tokenlist.ReadNext();
            exps1.add(exp.ParseExp(tokenlist));
            //tokenlist.ReadNext();
        }
        FuncRParams funcRParams = new FuncRParams(commas1, exps1);
        return funcRParams;
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        if (!exps.isEmpty())
        {
            sb.append(exps.get(0).toString());
            for (int i = 0; i < commas.size(); i++)
            {
                sb.append(commas.get(i).toString());
                sb.append(exps.get(i + 1).toString());
            }
            sb.append(type + "\n");
        }

        return sb.toString();
    }
}
