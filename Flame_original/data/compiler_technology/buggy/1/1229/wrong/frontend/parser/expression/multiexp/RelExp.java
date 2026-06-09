package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.unaryexp.UnaryExp;

import java.util.ArrayList;

public class RelExp implements Node {
    //一堆AddExp 通过< > <= >=连接，并且至少有一个addExp
    private final String name = "<RelExp>";
    private AddExp first = null;
    private ArrayList<Token> operators;
    private ArrayList<AddExp> operands;

    private TokenList tokenList;

    public RelExp(TokenList tokenList) {
        this.tokenList = tokenList;
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
    }

    public void parseRelExp(){
        AddExp addExp = new AddExp(tokenList);
        addExp.parseAddExp();
        this.first = addExp;
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.LSS) ||
                tokenList.seeAfterToken(0).getType().equals(TokenType.GRE) ||
                tokenList.seeAfterToken(0).getType().equals(TokenType.LEQ) ||
                tokenList.seeAfterToken(0).getType().equals(TokenType.GEQ)){
            this.operators.add(tokenList.getNextToken());
            addExp = new AddExp(tokenList);
            addExp.parseAddExp();
            this.operands.add(addExp);
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
