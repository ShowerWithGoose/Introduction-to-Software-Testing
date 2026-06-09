package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class UnaryExp {
    private PrimaryExp primaryExp;
    private Token ident;
    private Token lParent;
    private FuncRParams funcRParams;
    private Token rParent;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp, Token ident, Token lParent, FuncRParams funcRParams, Token rParent, UnaryOp unaryOp, UnaryExp unaryExp) {
        this.primaryExp = primaryExp;
        this.ident = ident;
        this.lParent = lParent;
        this.funcRParams = funcRParams;
        this.rParent = rParent;
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    public String print() {
        StringBuilder str = new StringBuilder();
        if (primaryExp != null) {
            str.append(primaryExp.print());
        }
        if (ident != null) {
            str.append(ident.print());
        }
        if (lParent != null) {
            str.append(lParent.print());
        }
        if (funcRParams != null) {
            str.append(funcRParams.print());
        }
        if (rParent != null) {
            str.append(rParent.print());
        }
        if (unaryOp != null) {
            str.append(unaryOp.print());
        }
        if (unaryExp != null) {
            str.append(unaryExp.print());
        }
        str.append("<UnaryExp>\n");
        return str.toString();
    }

    public static UnaryExp parse(TokenIterator iterator) {
        PrimaryExp primaryExp = null;
        Token ident = null;
        Token lParent = null;
        FuncRParams funcRParams = null;
        Token rParent = null;
        UnaryOp unaryOp = null;
        UnaryExp unaryExp = null;
        Token first = iterator.next();
        Token second = iterator.next();
        if (first.getType().equals(Token.Type.IDENFR) && second.getType().equals(Token.Type.LPARENT)) {
            ident = first;
            lParent = second;
            Token token = iterator.next();
            if (token.getType().equals(Token.Type.IDENFR) || token.getType().equals(Token.Type.LPARENT) || token.getType().equals(Token.Type.INTCON) || token.getType().equals(Token.Type.CHRCON)
                    || token.getType().equals(Token.Type.AND) || token.getType().equals(Token.Type.MINU) || token.getType().equals(Token.Type.NOT)) {
                iterator.back();
                funcRParams = funcRParams.parse(iterator);
            }
            else {
                iterator.back();
            }
            token = iterator.next();
            if (token.getType().equals(Token.Type.RPARENT)) {
                rParent = token;
            }
            else {
                iterator.back();
                Error error = new Error(iterator.now_line(), 'j');
                ErrorList.addError(error);
            }
        }
        else if (first.getType().equals(Token.Type.PLUS) || first.getType().equals(Token.Type.MINU) || first.getType().equals(Token.Type.NOT)) {
            iterator.back(2);
            unaryOp = UnaryOp.parse(iterator);
            unaryExp = UnaryExp.parse(iterator);
        }
        else {
            iterator.back(2);
            primaryExp = PrimaryExp.parse(iterator);
        }
        return new UnaryExp(primaryExp,ident,lParent,funcRParams,rParent,unaryOp,unaryExp);
    }

}
