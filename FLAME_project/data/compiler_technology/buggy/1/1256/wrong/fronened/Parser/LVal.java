package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class LVal {
    private Token ident;
    private Token lbRack;
    private Exp exp;
    private Token rbRack;


    public LVal(Token ident, Token lbRack, Exp exp, Token rbRack) {
        this.ident = ident;
        this.lbRack = lbRack;
        this.exp = exp;
        this.rbRack = rbRack;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.print());
        if (lbRack != null) {
            sb.append(lbRack.print());
        }
        if (exp != null) {
            sb.append(exp.print());
        }
        if (rbRack != null) {
            sb.append(rbRack.print());
        }
        sb.append("<LVal>\n");
        return sb.toString();
    }

    public static LVal parse(TokenIterator iterator) {
        Token ident = iterator.next();
        Token token = iterator.next();
        Token lbRack = null;
        Exp exp = null;
        Token rbRack = null;
        if (token.getType().equals(Token.Type.LBRACK)) {
            lbRack = token;
            exp = Exp.parse(iterator);
            token = iterator.next();
            if (token.getType().equals(Token.Type.RBRACK)) {
                rbRack = token;
            }
            else {
                iterator.back();
                Error error = new Error(iterator.now_line(),'k');
                ErrorList.addError(error);
            }
        }
        else {
            iterator.back();
        }
        return new LVal(ident, lbRack, exp, rbRack);
    }

}
