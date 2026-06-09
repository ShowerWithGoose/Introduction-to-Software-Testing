package frontend.Parser.expression.arithmeticalexp;

import frontend.Parser.expression.unaryexp.UnaryExp;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

import java.util.ArrayList;

public class MulExp
{
    private String type = "<MulExp>";
    private ArrayList<UnaryExp> exps = new ArrayList<>();
    private ArrayList<Token> ops = new ArrayList<>();

    public MulExp(ArrayList<UnaryExp> exps, ArrayList<Token> ops)
    {
        this.exps = exps;
        this.ops = ops;
    }

    public MulExp ParseMulExp(Tokenlist tokenlist)
    {
        ArrayList<UnaryExp> exps1 = new ArrayList<>();
        ArrayList<Token> ops1 = new ArrayList<>();
        UnaryExp unaryExp = new UnaryExp(null);
        exps1.add(unaryExp.ParserUnary(tokenlist));
        //tokenlist.ReadNext();
        while (tokenlist.getToken().getType() == Token.Type.MULT || tokenlist.getToken().getType() == Token.Type.DIV || tokenlist.getToken().getType() == Token.Type.MOD)
        {
            ops1.add(tokenlist.getToken());
            tokenlist.ReadNext();
            exps1.add(unaryExp.ParserUnary(tokenlist));
        }
        return new MulExp(exps1, ops1);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(exps.get(0).toString());
        for (int i = 0; i < ops.size(); i++)
        {
            sb.append("<MulExp>\n");
            sb.append(ops.get(i).toString());
            sb.append(exps.get(i + 1).toString());
        }
        sb.append(type + "\n");
        return sb.toString();
    }
}
