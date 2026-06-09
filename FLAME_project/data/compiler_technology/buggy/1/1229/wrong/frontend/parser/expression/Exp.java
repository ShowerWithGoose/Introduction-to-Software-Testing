package frontend.parser.expression;

import frontend.lexer.TokenList;
import frontend.parser.declaration.variable.initval.InitValIFace;
import frontend.parser.expression.multiexp.AddExp;

public class Exp implements InitValIFace {
    private final String name = "<Exp>";
    private AddExp addExp;

    private TokenList tokenList;

    public Exp(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseExp(){
        this.addExp = new AddExp(tokenList);
        this.addExp.parseAddExp();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.addExp.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
