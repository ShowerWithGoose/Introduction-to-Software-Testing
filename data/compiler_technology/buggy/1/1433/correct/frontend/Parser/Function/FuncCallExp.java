package frontend.Parser.Function;

import frontend.Lexer.Token;
import frontend.Parser.Declaration.Ident;
import frontend.Parser.Expression.Exp;
import frontend.Parser.Expression.unaryExpEle;

import java.util.ArrayList;

public class FuncCallExp implements unaryExpEle {
    private Ident ident;
    private Token lparentToken;
    private Exp firstFuncRParam;            // 可选
    private ArrayList<Token> commaTokens;   // 可选
    private ArrayList<Exp> funcRParams;     // 可选
    private Token rparentToken;

    public FuncCallExp(Ident ident,
                       Token lparentToken,
                       Exp firstFuncRParam,
                       ArrayList<Token> commaTokens,
                       ArrayList<Exp> funcFRParams,
                       Token rparentToken) {
        this.ident = ident;
        this.lparentToken = lparentToken;
        this.firstFuncRParam = firstFuncRParam;
        this.commaTokens = commaTokens;
        this.funcRParams = funcFRParams;
        this.rparentToken = rparentToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.printString());
        sb.append(lparentToken);
        if (firstFuncRParam != null) {
            sb.append(firstFuncRParam.printString());
            for (int i = 0; i < commaTokens.size(); i++) {
                sb.append(commaTokens.get(i));
                sb.append(funcRParams.get(i).printString());
            }
            sb.append("<" + "FuncRParams" + ">\n");
        }
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        return sb.toString();
    }
}
