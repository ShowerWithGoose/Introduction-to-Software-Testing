package frontend.parser.expression.primary;

import frontend.lexer.Token;

public class Character implements PExp {
    private final String name = "<Character>";
    private Token chrCon;

    public Character(Token chrCon) {
        this.chrCon = chrCon;
    }

    @Override
    public int getLineno() {
        return chrCon.getLineno();
    }

    @Override
    public String getOutPut() {
        return chrCon.getOutPut() + name + "\n";
    }

    @Override
    public String getError() {
        return "";
    }
}
