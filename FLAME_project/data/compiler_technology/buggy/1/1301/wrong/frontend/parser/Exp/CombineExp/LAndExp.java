package frontend.parser.Exp.CombineExp;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

import java.util.ArrayList;

public class LAndExp {
    private EqExp firstEqExp;
    private ArrayList<Token> operators; //+-可以没有
    private ArrayList<EqExp> eqExps; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "LAndExp";

    public LAndExp(TokenList tokens) {
        this.firstEqExp = null;
        this.operators = new ArrayList<>();
        this.eqExps = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstEqExp = new EqExp(tokens);
        errorNum += firstEqExp.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.AND)) {
            operators.add(token);
            EqExp eqExp = new EqExp(tokens);
            errorNum += eqExp.parse();
            eqExps.add(eqExp);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstEqExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        for (int i = 0;i < eqExps.size();i++) {
            sb.append(operators.get(i)).append(eqExps.get(i).toSyntaxTree());
            //改造左递归文法，但输出语法树时仍需按照左递归规则输出
            sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        }
        return sb.toString();
    }
}
