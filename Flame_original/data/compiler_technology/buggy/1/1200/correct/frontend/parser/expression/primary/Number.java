package frontend.parser.expression.primary;

import frontend.lexer.Token;

public class Number implements PExp {
    private final String name = "<Number>";
    private Token intCon;

    public Number(Token intCon) {
        this.intCon = intCon;
    }

    @Override
    public int getLineno() {
        return intCon.getLineno();
    }

    @Override
    public String getOutPut() {
        return intCon.getOutPut() + name + "\n";
    }

    @Override
    public String getError() {
        return "";
    }
}
