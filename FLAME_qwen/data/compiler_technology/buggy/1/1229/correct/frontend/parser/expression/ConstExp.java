package frontend.parser.expression;

import frontend.lexer.TokenList;
import frontend.parser.declaration.constant.constinitval.ConstInitValIFace;
import frontend.parser.expression.multiexp.AddExp;

public class ConstExp implements ConstInitValIFace {
    private final String name = "<ConstExp>";
    private AddExp addExp;

    private TokenList tokenList;

    public ConstExp(TokenList tokenList){
        this.tokenList = tokenList;
    }

    public void parseConstExp(){
        this.addExp = new AddExp(tokenList);
        this.addExp.parseAddExp();
    }
    //private AddExp addExp;

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
