package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.others.Block;

public class BreakStmt {
    //自定义
    //'break' ';'//i

    private Token Break;

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    public BreakStmt(Token aBreak) {
        this.Break = aBreak;
    }

    @Override
    public String toString() {
        return Break.toString() + semicn;
    }

    public static BreakStmt parse(TokenList list) {
        Token token = null;
        if (list.now().getType().equals(TokenType.Type.BREAKTK)) {
            token = list.now();
            list.next();
            if (list.now().getType().equals(TokenType.Type.SEMICN)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'i');
            }
            return new BreakStmt(token);
        } else {
            System.err.println("Error:BreakStmt cannot find break");
            return null;
        }
    }
}
