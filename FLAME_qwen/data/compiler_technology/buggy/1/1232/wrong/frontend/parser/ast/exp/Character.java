package frontend.parser.ast.exp;

import frontend.lexer.Token;

public class Character implements PExp {
    private String type = "<Character>";
    private Token charConst;

    public Character(Token intConst) {
        this.charConst = intConst;
    }

    public int getLineno() {
        return charConst.getLineno();
    }

    public String getOutput() {
        return charConst.getOutput() + type + "\n";
    }

    public String getError() {
        return "";
    }

}
