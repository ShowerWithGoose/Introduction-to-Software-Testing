package frontend.Parser.Declaration.InitValElements;

import frontend.Lexer.Token;
import frontend.Parser.Declaration.InitValEle;
import frontend.Parser.Expression.ConstExp;
import frontend.Parser.Expression.Exp;

import java.util.ArrayList;

public class ExpArray implements InitValEle {
    private Token lbraceToken;
    private Exp firstExp;         // 可选
    private ArrayList<Token> commaTokens;   // 可选
    private ArrayList<Exp> exps;  // 可选
    private Token rbraceToken;

    public ExpArray(Token lbraceToken,
                    Exp firstExp,
                    ArrayList<Token> commaTokens,
                    ArrayList<Exp> exps,
                    Token rbraceToken) {
        this.lbraceToken = lbraceToken;
        this.firstExp = firstExp;
        this.commaTokens = commaTokens;
        this.exps = exps;
        this.rbraceToken = rbraceToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbraceToken);
        if (firstExp != null) {
            sb.append(firstExp.printString());
            for (int i = 0; i < commaTokens.size(); i++) {
                sb.append(commaTokens.get(i));
                sb.append(exps.get(i).printString());
            }
        }
        sb.append(rbraceToken);
        return sb.toString();
    }
}
