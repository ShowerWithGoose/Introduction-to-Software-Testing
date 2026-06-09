package struct;

import token.Token;

/* BType â†’ 'int' | 'char' */
public class BType {
    private final Token type;

    public BType(Token token) {
        this.type = token;
    }

    public Token getType() {
        return type;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(type.toString());
        // sb.append("<BType>\n");
        return sb.toString();
    }
}
