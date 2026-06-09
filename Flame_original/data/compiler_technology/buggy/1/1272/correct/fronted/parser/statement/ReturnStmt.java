package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.expression.Exp;
import fronted.parser.expression.LVal;
import fronted.parser.others.Block;

public class ReturnStmt {
    //自定义
    //'return' [Exp] ';' // i

    private Token Return;

    private Exp exp;

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    public ReturnStmt(Token token,Exp exp) {
        this.Return = token;
        this.exp = exp;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(Return.toString());
        if (exp != null) {
            sb.append(exp.toString());
        }
        sb.append(semicn);
        return sb.toString();
    }

    public static ReturnStmt parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.RETURNTK)) {
            Token r = list.now();
            list.next();
            Exp exp = null;
            Token first = list.now();
            //System.out.println("Return first: " + first.toString());
            if (list.now().getType().equals(TokenType.Type.SEMICN)) {
                list.next();
            } else if (first.getType().equals(TokenType.Type.LPARENT) ||
                    first.getType().equals(TokenType.Type.INTCON) ||
                    first.getType().equals(TokenType.Type.CHRCON) ||
                    (first.getType().equals(TokenType.Type.IDENFR) && list.hasAhead(1)
                            && list.getAheadOne(1).getType().equals(TokenType.Type.LPARENT)) ||
                    first.getType().equals(TokenType.Type.PLUS) ||
                    first.getType().equals(TokenType.Type.MINU) ||
                    first.getType().equals(TokenType.Type.NOT)){
                //exp打头不是LVal的情况
                exp = Exp.parse(list);
                if (list.now().getType().equals(TokenType.Type.SEMICN)) {
                    list.next();
                } else {
                    ErrorList.addError(list.before().getLine(),'i');
                }
            } else if (first.getType().equals(TokenType.Type.IDENFR)) {
                //可能是LVal
                //防止是assignStmt或者getIntCharStmt
                int pos = list.getPos();
                LVal tmp = LVal.parse(list);
                if (!list.now().getType().equals(TokenType.Type.ASSIGN)) {
                    //说明肯定不是assignStmt或者getIntCharStmt
                    list.setPos(pos);
                    exp = Exp.parse(list);
                    if (list.now().getType().equals(TokenType.Type.SEMICN)) {
                        list.next();
                    } else {
                        ErrorList.addError(list.before().getLine(),'i');
                    }
                } else {
                    //说明不是exp,属于exp和;都缺少
                    list.setPos(pos);
                    ErrorList.addError(list.before().getLine(),'i');
                }
            } else {
                //Exp和;均不存在
                ErrorList.addError(list.before().getLine(),'i');
            }
            return new ReturnStmt(r,exp);
        } else {
            System.err.println("Error:ReturnStmt cannot find return");
            return null;
        }
    }
}
