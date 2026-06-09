package fronted.parser.statement;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.others.Block;

public class ContinueStmt {
    //自定义
    //'continue' ';' // i

    private Token Continue;

    private static final Token semicn = new Token(TokenType.Type.SEMICN,";",1);

    public ContinueStmt(Token aContinue) {
        this.Continue = aContinue;
    }

    @Override
    public String toString() {
        return Continue.toString() + semicn;
    }

    public static ContinueStmt parse(TokenList list) {
        Token token = null;
        if (list.now().getType().equals(TokenType.Type.CONTINUETK)) {
            token = list.now();
            list.next();
            if (list.now().getType().equals(TokenType.Type.SEMICN)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'i');
            }
            return new ContinueStmt(token);
        } else {
            System.err.println("Error:ContinueStmt cannot find continue");
            return null;
        }
    }
}
