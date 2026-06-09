package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;
import frontend.parser.expression.Exp;

import java.util.ArrayList;

public class FuncRParams implements Node {
    private final String name = "<FuncRParams>";
    private Exp first;
    /* commas 和 exps大小应当相同，且commas应当只有逗号一种Token */
    /* 这里可能需要进行某种验证 */
    private ArrayList<Token> commas;
    private ArrayList<Exp> exps;

    private TokenList tokenList;

    public FuncRParams(TokenList tokenList) {
        this.tokenList = tokenList;
        this.commas = new ArrayList<>();
        this.exps = new ArrayList<>();
    }

    public void parseFuncRParams(){
        Exp exp = new Exp(tokenList);
        exp.parseExp();
        this.first = exp;
        while (tokenList.seeAfterToken(0).getType().equals(TokenType.COMMA)){
            this.commas.add(tokenList.getNextToken());
            exp = new Exp(tokenList);
            exp.parseExp();
            this.exps.add(exp);
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxOutput());
        if (commas != null && exps != null && commas.size() == exps.size()) {
            int len = commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(commas.get(i).syntaxOutput());
                sb.append(exps.get(i).syntaxOutput());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
