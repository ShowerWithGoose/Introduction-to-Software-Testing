package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class FuncFParam {
    private BType bType;
    private Token ident;
    private Token lbRack;
    private Token rbRack;

    public FuncFParam(BType bType, Token ident, Token lbRack, Token rbRack) {
        this.bType = bType;
        this.ident = ident;
        this.lbRack = lbRack;
        this.rbRack = rbRack;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType.print());
        sb.append(ident.print());
        if (lbRack != null) {
            sb.append(lbRack.print());
        }
        if (rbRack != null) {
            sb.append(rbRack.print());
        }
        sb.append("<FuncFParam>\n");
        return sb.toString();
    }

    public static FuncFParam parse(TokenIterator iterator) {
        BType bType = BType.parser(iterator);
        Token ident = iterator.next();
        Token token = iterator.next();
        Token lbRack = null;
        Token rbRack = null;
        if (token.getType().equals(Token.Type.LBRACK)) {
            lbRack = token;
            token = iterator.next();
            if (token.getType().equals(Token.Type.RBRACK)) {
                rbRack = token;
            }
            else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'k');
                ErrorList.addError(error);
            }
        }
        else {
            iterator.back();
        }
        return new FuncFParam(bType, ident, lbRack, rbRack);
    }

}
