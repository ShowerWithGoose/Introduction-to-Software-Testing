package frontend.SyntaxUnits.VarInits;

import frontend.Token;

public class InitString implements VarInitUnit  {
    private final Token string;

    public InitString(Token string) {
        this.string = string;
    }

    @Override
    public String toPrint() {
        return string.toPrint();
    }
}
