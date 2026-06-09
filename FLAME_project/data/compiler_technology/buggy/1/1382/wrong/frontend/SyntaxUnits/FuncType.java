package frontend.SyntaxUnits;

import frontend.Token;

public class FuncType implements SyntaxUnit {
    private final Token type;


    public FuncType(Token type) {
        this.type = type;
    }

    public String toPrint() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(type.toPrint());
        stringBuilder.append("<FuncType>\n");
        return stringBuilder.toString();
    }
}
