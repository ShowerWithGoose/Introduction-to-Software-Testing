package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Exp;

public class ExpStmt {
    //自定义
    //[Exp] ';' // i

    private Exp exp;

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    public ExpStmt(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        if (exp != null) {
            stringBuilder.append(exp.toString());
        }
        stringBuilder.append(semicn);
        return stringBuilder.toString();
    }

    public static ExpStmt parse(TokenList list) {
        Exp exp = null;
        if (list.now().getType().equals(TokenType.Type.SEMICN)) {
            list.next();
        } else {
            exp = Exp.parse(list);
            if (list.now().getType().equals(TokenType.Type.SEMICN)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'i');
            }
        }
        return new ExpStmt(exp);
    }

}
