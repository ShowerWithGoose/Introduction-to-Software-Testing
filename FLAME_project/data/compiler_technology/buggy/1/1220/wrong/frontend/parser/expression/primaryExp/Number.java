package frontend.parser.expression.primaryExp;

import frontend.lexer.Token;

public class Number implements PrimaryExpUnit{
    private String name = "<Number>";
    private Token intConst;

    public Number(Token intConst) {
        this.intConst = intConst;
    }


    @Override
    public String syntaxPrint() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.syntaxPrint());
        sb.append(name + "\n");
        return sb.toString();
    }
}
