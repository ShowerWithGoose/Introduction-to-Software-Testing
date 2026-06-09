package fronted.parser.expression;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

public class LVal {
    // LVal â†’ Ident ['[' Exp ']'] // k

    private Token ident;

    private static final Token leftBrack = new Token(TokenType.Type.LBRACK,"[",1);

    private static final Token rightBrack = new Token(TokenType.Type.RBRACK,"]",1);

    private Exp exp;

    private static final String name = "<LVal>\n";

    public LVal(Token ident, Exp exp) {
        this.ident = ident;
        this.exp = exp;
    }

    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(ident.toString());
        if (exp != null) {
            sb.append(leftBrack);
            sb.append(exp.toString());
            sb.append(rightBrack);
        }
        sb.append(name);
        return sb.toString();
    }

    public static LVal parse(TokenList list){
        if (!list.now().getType().equals(TokenType.Type.IDENFR)) {
            System.err.println("Error:LVal cannot find a ident");
        } else {
            Token ident = list.now();
            list.next();
            Exp exp = null;
            if (list.now().getType().equals(TokenType.Type.LBRACK)) {
                list.next();
                exp = Exp.parse(list);
                if (list.now().getType().equals(TokenType.Type.RBRACK)) {
                    list.next();
                } else {
                    ErrorList.addError(list.before().getLine(),'k');
                }
            }
            return new LVal(ident,exp);
        }
        return null;
    }
}
