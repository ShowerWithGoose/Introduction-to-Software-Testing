package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class LOrExp implements Node {
    //一堆LAndExp 通过||连接，并且至少有一个LAndExp
    private final String name = "<LOrExp>";
    private LAndExp first = null;
    private ArrayList<Token> operators;
    private ArrayList<LAndExp> operands;

    private TokenList tokenList;

    public LOrExp(TokenList tokenList) {
        this.tokenList = tokenList;
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
    }

    public void parseLOrExp(){
        LAndExp lAndExp = new LAndExp(tokenList);
        lAndExp.parseLAndExp();
        this.first = lAndExp;
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.OR)){
            this.operators.add(tokenList.getNextToken());
            lAndExp = new LAndExp(tokenList);
            lAndExp.parseLAndExp();
            this.operands.add(lAndExp);
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
