package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class FuncType {
    private Token funcType;


    public FuncType(Token funcType) {
        this.funcType = funcType;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.print());
        sb.append("<FuncType>\n");
        return sb.toString();
    }

    public static FuncType parse(TokenIterator iterator) {
        Token funcType = iterator.next();
        return new FuncType(funcType);
    }
}
