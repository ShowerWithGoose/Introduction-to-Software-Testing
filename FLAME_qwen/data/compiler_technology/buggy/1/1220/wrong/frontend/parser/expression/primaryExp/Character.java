package frontend.parser.expression.primaryExp;

import frontend.lexer.Token;

public class Character implements PrimaryExpUnit{
    private String name = "<Character>";
    private Token charConst;

    public Character(Token charConst) {
        this.charConst = charConst;
    }

    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
