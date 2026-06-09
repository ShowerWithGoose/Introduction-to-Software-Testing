package frontend.parser.Exp.CombineExp;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

import java.util.ArrayList;

public class LOrExp {
    private LAndExp firstLAndExp;
    private ArrayList<Token> operators; //+-可以没有
    private ArrayList<LAndExp> lAndExps; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "LOrExp";

    public LOrExp(TokenList tokens) {
        this.firstLAndExp = null;
        this.operators = new ArrayList<>();
        this.lAndExps = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstLAndExp = new LAndExp(tokens);
        errorNum += firstLAndExp.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.OR)) {
            operators.add(token);
            LAndExp lAndExp = new LAndExp(tokens);
            errorNum += lAndExp.parse();
            lAndExps.add(lAndExp);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstLAndExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        for (int i = 0;i < lAndExps.size();i++) {
            sb.append(operators.get(i)).append(lAndExps.get(i).toSyntaxTree());
            //改造左递归文法，但输出语法树时仍需按照左递归规则输出
            sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        }
        return sb.toString();
    }
}
