package fronted.parser.statement;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Exp;
import fronted.parser.expression.LVal;
import fronted.parser.others.Block;

public class ForStmt {
    //ForStmt â†’ LVal '=' Exp

    private LVal lVal;

    private Exp exp;

    private static final String name = "<ForStmt>\n";

    private static final Token assign = new Token(TokenType.Type.ASSIGN,"=",1);

    public ForStmt(LVal lVal, Exp exp) {
        this.lVal = lVal;
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign);
        sb.append(exp.toString());
        sb.append(name);
        return sb.toString();

    }

    public static ForStmt parse(TokenList list) {
        LVal lVal = LVal.parse(list);
        if (list.now().getType().equals(TokenType.Type.ASSIGN)) {
            list.next();
        } else {
            System.err.println("Error:ForStmt cannot find =");
        }
        Exp exp = Exp.parse(list);
        return new ForStmt(lVal,exp);
    }
}
