package frontend.parser.expression.primaryexp;

import frontend.lexer.TokenList;
import frontend.parser.terminal.IntConst;

public class Number implements PrimaryExpIFace{
    private final String name = "<Number>";
    private IntConst intConst;

    private TokenList tokenList;

    public Number(TokenList tokenList) {
        this.tokenList = tokenList;
    }
    public void parseNumber(){
        this.intConst = new IntConst(tokenList);
        this.intConst.parseIntConst();
    }
    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
