package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

public class AddExp implements Node {
    //一堆MulExp 通过+-连接，并且至少有一个NulExp
    private final String name = "<AddExp>";
    private MulExp first = null;
    private ArrayList<Token> operators;
    private ArrayList<MulExp> operands;

    private TokenList tokenList;

    public AddExp(TokenList tokenList) {
        this.tokenList = tokenList;
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
    }

    public void parseAddExp(){
        MulExp mulExp = new MulExp(tokenList);
        mulExp.parseMulExp();
        this.first = mulExp;
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.PLUS) ||
                tokenList.seeAfterToken(0).getType().equals(TokenType.MINU)){
            this.operators.add(tokenList.getNextToken());
            mulExp = new MulExp(tokenList);
            mulExp.parseMulExp();
            this.operands.add(mulExp);
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
