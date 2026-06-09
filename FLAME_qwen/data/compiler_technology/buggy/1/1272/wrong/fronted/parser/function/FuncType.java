package fronted.parser.function;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

public class FuncType {
    //FuncType â†’ 'void' | 'int' | 'char'

    private Token type;

    private static final String name = "<FuncType>\n";

    public FuncType(Token type) {
        this.type = type;
    }

    @Override
    public String toString() {
        return type.toString() + name;
    }

    public static FuncType parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.VOIDTK)
                || list.now().getType().equals(TokenType.Type.INTTK)
                || list.now().getType().equals(TokenType.Type.CHARTK)) {
            Token token = list.now();
            list.next();
            return new FuncType(token);
        } else {
            System.err.println("Error:FuncType cannot find type");
        }
        return null;
    }
}

