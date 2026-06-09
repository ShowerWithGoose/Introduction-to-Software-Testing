package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class ConstDef {
    private Token ident;
    private Token lbRack;
    private ConstExp constExp;
    private Token rbRack;
    private Token assign;
    private ConstInitVal constInitVal;

    public ConstDef(Token ident, Token lbRack, ConstExp constExp, Token rbRack, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lbRack = lbRack;
        this.constExp = constExp;
        this.rbRack = rbRack;
        this.assign = assign;
        this.constInitVal = constInitVal;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident.print());
        if (lbRack != null) {
            sb.append(lbRack.print());
        }
        if (constExp != null) {
            sb.append(constExp.print());
        }
        if (rbRack != null) {
            sb.append(rbRack.print());
        }
        sb.append(assign.print());
        sb.append(constInitVal.print());
        sb.append("<ConstDef>\n");
        return sb.toString();
    }

    public static ConstDef parse(TokenIterator iterator) {
        Token ident = iterator.next();
        Token token = iterator.next();
        Token lbRack = null;
        ConstExp constExp = null;
        Token rbRack = null;
        if (token.getType().equals(Token.Type.LBRACK)) {
            lbRack = token;
            constExp = ConstExp.parse(iterator);
            token = iterator.next();
            if (token.getType().equals(Token.Type.RBRACK)) {
                rbRack = token;
            }
            else {
                iterator.back();
                Error error = new Error(ident.getLine(), 'k');
                ErrorList.addError(error);
            }
        }
        else {
            iterator.back();
        }
        Token assign = iterator.next();
        ConstInitVal constInitVal = ConstInitVal.parse(iterator);
        return new ConstDef(ident, lbRack, constExp, rbRack, assign, constInitVal);
    }
}
