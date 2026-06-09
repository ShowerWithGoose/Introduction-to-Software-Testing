package frontend.parser.Exp.CombineExp;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

import java.util.ArrayList;

public class RelExp {
    private AddExp firstAddExp;
    private ArrayList<Token> operators; //< > <= >= 可以没有
    private ArrayList<AddExp> addExps; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "RelExp";

    public RelExp(TokenList tokens) {
        this.firstAddExp = null;
        this.operators = new ArrayList<>();
        this.addExps = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstAddExp = new AddExp(tokens);
        errorNum += firstAddExp.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.LSS) || token.equals(LexType.LEQ) || token.equals(LexType.GRE) || token.equals(LexType.GEQ)) {
            operators.add(token);
            AddExp addExp = new AddExp(tokens);
            errorNum += addExp.parse();
            addExps.add(addExp);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstAddExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        for (int i = 0;i < addExps.size();i++) {
            sb.append(operators.get(i)).append(addExps.get(i).toSyntaxTree());
            //改造左递归文法，但输出语法树时仍需按照左递归规则输出
            sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        }
        return sb.toString();
    }
}
