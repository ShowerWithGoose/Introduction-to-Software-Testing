package frontend.Parser.Declaration.ConstInitValElements;

import frontend.Lexer.Token;
import frontend.Parser.Declaration.ConstInitValEle;
import frontend.Parser.Expression.ConstExp;

import java.util.ArrayList;

public class ConstExpArray implements ConstInitValEle {
    private Token lbraceToken;
    private ConstExp firstConstExp;         // 可选
    private ArrayList<Token> commaTokens;   // 可选
    private ArrayList<ConstExp> constExps;  // 可选
    private Token rbraceToken;

    public ConstExpArray(Token lbraceToken,
                         ConstExp firstConstExp,
                         ArrayList<Token> commaTokens,
                         ArrayList<ConstExp> constExps,
                         Token rbraceToken) {
        this.lbraceToken = lbraceToken;
        this.firstConstExp = firstConstExp;
        this.commaTokens = commaTokens;
        this.constExps = constExps;
        this.rbraceToken = rbraceToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbraceToken);
        if (firstConstExp != null) {
            sb.append(firstConstExp.printString());
            if (!commaTokens.isEmpty()) {
                for (int i = 0; i < commaTokens.size(); i++) {
                    sb.append(commaTokens.get(i));
                    sb.append(constExps.get(i).printString());
                }
            }
        }
        sb.append(rbraceToken);
        return sb.toString();
    }
}
