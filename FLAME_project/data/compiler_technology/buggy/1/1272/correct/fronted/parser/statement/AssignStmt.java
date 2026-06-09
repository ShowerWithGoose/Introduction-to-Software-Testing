package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Exp;
import fronted.parser.expression.LVal;

public class AssignStmt {
    //自定义
    //LVal '=' Exp ';' // i

    private LVal lVal;

    private Exp exp;


    private static final Token assign = new Token(TokenType.Type.ASSIGN,"=",1);

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    public AssignStmt(LVal lVal,Exp exp) {
        this.lVal = lVal;
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toString());
        sb.append(assign);
        sb.append(exp.toString());
        sb.append(semicn);
        return sb.toString();
    }

    public static AssignStmt parse(TokenList list) {
        LVal lVal = LVal.parse(list);
        if (list.now().getType().equals(TokenType.Type.ASSIGN)) {
            list.next();
        } else {
            System.err.println("Error:AssignmentStmt cannot find =");
        }
        Exp exp = Exp.parse(list);
        if (list.now().getType().equals(TokenType.Type.SEMICN)) {
            list.next();
        } else {
            ErrorList.addError(list.before().getLine(),'i');
        }
        return new AssignStmt(lVal,exp);
    }
}
