package frontend.Parser.Expression;

import frontend.Lexer.Token;
import frontend.Parser.Declaration.Ident;

public class LVal implements primaryExpEle {
    private Ident ident;
    private Token lbrackToken;  // 可选
    private Exp exp;            // 可选
    private Token rbrackToken;  // 可选

    public LVal(Ident ident, Token lbrackToken, Exp exp, Token rbrackToken) {
        this.ident = ident;
        this.lbrackToken = lbrackToken;
        this.exp = exp;
        this.rbrackToken = rbrackToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.printString());
        if (lbrackToken != null) {
            sb.append(lbrackToken);
            sb.append(exp.printString());
            if (rbrackToken != null) {
                sb.append(rbrackToken);
            }
        }
        sb.append("<" + "LVal" + ">\n");
        return sb.toString();
    }
}
