package fronted.parser.declaration;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.Node;
import fronted.parser.SyntaxType;
import fronted.parser.TokenNode;

public class BType {

    //BType -> 'int' | 'char'
    private Token token;

    public BType(Token token) {
        this.token = token;
    }

    @Override
    public String toString() {
        if (this.token.getType() == TokenType.Type.INTTK) {
            return token.toString();
        } else if (this.token.getType() == TokenType.Type.CHARTK) {
            return token.toString();
        } else {
            System.err.println("BType error!");
        }
        return "ERROR";
    }

    public Token getToken() {
        return token;
    }

    public static BType parse(TokenList list){
        if (!list.hasToken()) {
            System.err.println("BType : there is no token left");
        } else {
            Token token1 = list.now();
            if (list.now().getType().equals(TokenType.Type.INTTK)) {
                list.next();
                BType type = new BType(token1);
                return type;
            } else if (token1.getType().equals(TokenType.Type.CHARTK)) {
                list.next();
                BType type = new BType(token1);
                return type;
            } else {
                System.err.println("BType : parse error!");
            }
        }
        return null;
    }


}
