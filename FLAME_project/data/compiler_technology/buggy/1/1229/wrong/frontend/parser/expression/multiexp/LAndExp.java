package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

public class LAndExp implements Node {
    //一堆EqExp 通过&&连接，并且至少有一个EqExp
    private final String name = "<LAndExp>";
    private EqExp first = null;
    private ArrayList<Token> operators;
    private ArrayList<EqExp> operands;

    private TokenList tokenList;

    public LAndExp(TokenList tokenList) {
        this.tokenList = tokenList;
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
    }

    public void parseLAndExp(){
        EqExp eqExp = new EqExp(tokenList);
        eqExp.parseEqExp();
        this.first = eqExp;
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.AND)){
            this.operators.add(tokenList.getNextToken());
            eqExp = new EqExp(tokenList);
            eqExp.parseEqExp();
            this.operands.add(eqExp);
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxOutput());
        sb.append(this.name + "\n");
        if (operators != null && operands != null && operators.size() == operands.size()) {
            int len = operators.size();
            for (int i = 0; i < len; i++) {
                sb.append(operators.get(i).syntaxOutput());
                sb.append(operands.get(i).syntaxOutput());
                sb.append(this.name + "\n");
            }
        }
        return sb.toString();
    }
}
