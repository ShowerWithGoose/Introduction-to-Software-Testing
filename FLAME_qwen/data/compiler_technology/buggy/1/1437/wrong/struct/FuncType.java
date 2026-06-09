package struct;

import token.Token;

/* FuncType â†’ 'void' | 'int' | 'char' */
public class FuncType {
    private final Token type;

    public FuncType(Token type) {
        this.type = type;
    }

    public Token getType() {
        return type;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(type.toString());
        sb.append("<FuncType>\n");
        return sb.toString();
    }
}
