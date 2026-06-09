package frontend.parser.ast.exp;

import frontend.lexer.Token;

public class Number implements PExp {
    private String type = "<Number>";
    private Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }

    public int getLineno() {
        return intConst.getLineno();
    }

    public String getOutput() {
        return intConst.getOutput() + type + "\n";
    }

    public String getError() {
        StringBuilder out = new StringBuilder();
        return out.toString();
    }

}
