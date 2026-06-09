package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

public class MyCharacter {
    // Character â†’ CharConst

    private Token charConst;

    private static final String name = "<Character>\n";

    public MyCharacter(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public String toString(){
        return charConst.toString() + name;
    }

    public static MyCharacter parse(TokenList list){
        if (list.now().getType().equals(TokenType.Type.CHRCON)) {
            Token token = list.now();
            list.next();
            return new MyCharacter(token);
        } else {
            System.err.println("Error:Character cannot find CharConst");
        }
        return null;
    }
}
