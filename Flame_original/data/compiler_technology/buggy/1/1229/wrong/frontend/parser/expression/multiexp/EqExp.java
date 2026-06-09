package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class EqExp implements Node {
    //一堆RelExp 通过== !=连接，并且至少有一个RelExp
    private final String name = "<EqExp>";
    private RelExp first = null;
    private ArrayList<Token> operators;
    private ArrayList<RelExp> operands;

    private TokenList tokenList;

    public EqExp(TokenList tokenList) {
        this.tokenList = tokenList;
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
    }

    public void parseEqExp(){
        RelExp relExp = new RelExp(tokenList);
        relExp.parseRelExp();
        this.first = relExp;
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.EQL) ||
                tokenList.seeAfterToken(0).getType().equals(TokenType.NEQ)){
            this.operators.add(tokenList.getNextToken());
            relExp = new RelExp(tokenList);
            relExp.parseRelExp();
            this.operands.add(relExp);
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
