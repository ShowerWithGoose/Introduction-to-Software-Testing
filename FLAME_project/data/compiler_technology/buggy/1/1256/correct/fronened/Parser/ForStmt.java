package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.beans.Expression;

public class ForStmt {
    private LVal lVal;
    private Token assign;
    private Exp exp;

    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.print());
        sb.append(assign.print());
        sb.append(exp.print());
        sb.append("<ForStmt>\n");
        return sb.toString();
    }

    public static ForStmt parse(TokenIterator iterator) {
        LVal lVal = LVal.parse(iterator);
        Token assign = iterator.next();
        Exp exp = Exp.parse(iterator);
        return new ForStmt(lVal, assign, exp);
    }
}
