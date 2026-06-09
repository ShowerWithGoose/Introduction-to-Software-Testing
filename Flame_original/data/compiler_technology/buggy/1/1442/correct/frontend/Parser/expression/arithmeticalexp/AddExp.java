package frontend.Parser.expression.arithmeticalexp;

import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

import java.util.ArrayList;

public class AddExp
{
    private String type = "<AddExp>";
    private ArrayList<MulExp> exps = new ArrayList<>();
    private ArrayList<Token> ops = new ArrayList<>();

    public AddExp(ArrayList<MulExp> exps, ArrayList<Token> ops)
    {
        this.exps = exps;
        this.ops = ops;
    }

    public AddExp ParseAddExp(Tokenlist tokenlist)
    {
        ArrayList<MulExp> exps1 = new ArrayList<>();
        ArrayList<Token> ops1 = new ArrayList<>();
        MulExp mulExp = new MulExp(null, null);
        exps1.add(mulExp.ParseMulExp(tokenlist));
        //tokenlist.ReadNext();
        while (tokenlist.getToken().getType() == Token.Type.PLUS || tokenlist.getToken().getType() == Token.Type.MINU)
        {
            ops1.add(tokenlist.getToken());
            tokenlist.ReadNext();
            exps1.add(mulExp.ParseMulExp(tokenlist));
        }
        return new AddExp(exps1, ops1);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(exps.get(0).toString());
        for (int i = 0; i < ops.size(); i++)
        {
            sb.append("<AddExp>\n");
            sb.append(ops.get(i).toString());
            sb.append(exps.get(i + 1).toString());
        }
        sb.append(type + "\n");
        return sb.toString();
    }
}
