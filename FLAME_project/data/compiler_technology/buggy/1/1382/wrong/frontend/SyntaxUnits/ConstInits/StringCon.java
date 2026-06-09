package frontend.SyntaxUnits.ConstInits;

import frontend.Token;

public class StringCon implements ConstInitUnit{
    private final Token string;

    public StringCon(Token string) {
        this.string = string;
    }

    @Override
    public String toPrint() {
        return string.toPrint();
    }
}
