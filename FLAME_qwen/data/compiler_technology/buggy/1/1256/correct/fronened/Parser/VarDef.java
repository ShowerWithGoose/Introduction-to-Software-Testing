package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class VarDef {
    private Token ident;
    private Token lbRack;
    private ConstExp constExp;
    private Token rbRack;
    private Token assign;
    private InitVal initVal;


    public VarDef(Token ident, Token lbRack, ConstExp constExp, Token rbRack, Token assign, InitVal initVal) {
        this.ident = ident;
        this.lbRack = lbRack;
        this.constExp = constExp;
        this.rbRack = rbRack;
        this.assign = assign;
        this.initVal = initVal;
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
        if (assign != null) {
            sb.append(assign.print());
        }
        if (initVal != null) {
            sb.append(initVal.print());
        }
        sb.append("<VarDef>\n");
        return sb.toString();
    }

    public static VarDef parse(TokenIterator iterator) {
        Token ident = iterator.next();
        Token lbRack = null;
        ConstExp constExp = null;
        Token rbRack = null;
        Token assign = null;
        InitVal initVal = null;
        Token token = iterator.next();
        if (token.getType().equals(Token.Type.LBRACK)) {
            lbRack = token;
            constExp = ConstExp.parse(iterator);
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
        token = iterator.next();
        if (token.getType().equals(Token.Type.ASSIGN)) {
            assign = token;
            initVal = InitVal.parse(iterator);
        }
        else {
            iterator.back();
        }

        return new VarDef(ident, lbRack, constExp, rbRack, assign, initVal);
    }
}
