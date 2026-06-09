package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

public class MulExp implements Node {
    /* MulExp Attributes */
    //一堆unaryExp 通过*%/连接，并且至少有一个unaryExp
    private final String name = "<MulExp>";
    private UnaryExp first = null;
    private ArrayList<Token> operators;
    private ArrayList<UnaryExp> operands;

    private TokenList tokenList;

    public MulExp(TokenList tokenList) {
        this.tokenList = tokenList;
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
    }

    public void parseMulExp(){
        UnaryExp unaryExp = new UnaryExp(tokenList);
        unaryExp.parseUnaryExp();
        this.first = unaryExp;
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.MULT) ||
                tokenList.seeAfterToken(0).getType().equals(TokenType.DIV) ||
                tokenList.seeAfterToken(0).getType().equals(TokenType.MOD)){
            this.operators.add(tokenList.getNextToken());
            unaryExp = new UnaryExp(tokenList);
            unaryExp.parseUnaryExp();
            this.operands.add(unaryExp);
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
