package frontend.parser.expression;

import frontend.lexer.TokenList;
import frontend.parser.Node;
import frontend.parser.expression.multiexp.LOrExp;

public class Cond implements Node {
    private final String name = "<Cond>";
    private LOrExp lorExp;

    private TokenList tokenList;

    public Cond(TokenList tokenList) {
        this.tokenList = tokenList;
    }
    public void parseCond(){
        this.lorExp = new LOrExp(tokenList);
        this.lorExp.parseLOrExp();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(lorExp.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
