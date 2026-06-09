package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

public class UnaryOp {
    //UnaryOp → '+' | '−' | '!' 注：'!'仅出现在条件表达式中

    private Token token;

    private static final String name = "<UnaryOp>\n";

    public UnaryOp(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        return this.token.toString() + name;
    }

    public static UnaryOp parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.PLUS)
                || list.now().getType().equals(TokenType.Type.MINU)
                || list.now().getType().equals(TokenType.Type.NOT)) {
            Token token = list.now();
            list.next();
            return new UnaryOp(token);
        } else {
            System.err.println("Error:UnaryOp error");
            return null;
        }
    }
}
