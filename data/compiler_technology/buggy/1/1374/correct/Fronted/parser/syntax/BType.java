package Fronted.parser.syntax;
import Fronted.lexer.Token;

//BType â†’ 'int' | 'char'
public class BType {

    private final String name = "<BType>";

    private Token type = null;

    public BType(Token type) {
        this.type = type;
    }

    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(type);
        return out.toString();
    }

    public Token getType() {
        return type;
    }

    public void setType(Token type) {
        this.type = type;
    }
}
