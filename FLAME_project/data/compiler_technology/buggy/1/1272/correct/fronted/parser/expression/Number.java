package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

public class Number {
    //Number â†’ IntConst

    private Token intConst;

    private static final String name = "<Number>\n";

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    @Override
    public String toString(){
        return intConst.toString() + name;
    }

    public static Number parse(TokenList list){
        if (list.now().getType().equals(TokenType.Type.INTCON)) {
            Token token = list.now();
            list.next();
            return new Number(token);
        } else {
            System.err.println("Error:Character cannot find CharConst");
        }
        return null;
    }
}
