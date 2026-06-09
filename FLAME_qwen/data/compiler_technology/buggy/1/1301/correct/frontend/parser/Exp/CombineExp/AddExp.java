package frontend.parser.Exp.CombineExp;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

import java.util.ArrayList;

public class AddExp {
    private MulExp firstMulExp;
    private ArrayList<Token> operators; //+-可以没有
    private ArrayList<MulExp> mulExps; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "AddExp";

    public AddExp(TokenList tokens) {
        this.firstMulExp = null;
        this.operators = new ArrayList<>();
        this.mulExps = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstMulExp = new MulExp(tokens);
        errorNum += firstMulExp.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.PLUS) || token.equals(LexType.MINU)) {
            operators.add(token);
            MulExp mulExp = new MulExp(tokens);
            errorNum += mulExp.parse();
            mulExps.add(mulExp);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstMulExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        for (int i = 0;i < mulExps.size();i++) {
            sb.append(operators.get(i)).append(mulExps.get(i).toSyntaxTree());
            //改造左递归文法，但输出语法树时仍需按照左递归规则输出
            sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        }
        return sb.toString();
    }
}
