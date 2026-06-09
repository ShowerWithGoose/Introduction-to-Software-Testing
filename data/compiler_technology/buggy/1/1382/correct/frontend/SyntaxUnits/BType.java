package frontend.SyntaxUnits;

import frontend.Token;

public class BType implements SyntaxUnit {
    private final Token type;

    public BType(Token type) {
        this.type = type;
    }

    public String toPrint() {
        return type.toPrint();
    }
}
