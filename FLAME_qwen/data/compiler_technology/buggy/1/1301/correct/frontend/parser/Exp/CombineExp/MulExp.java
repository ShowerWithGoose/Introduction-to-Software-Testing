package frontend.parser.Exp.CombineExp;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.UnaryExp.UnaryExp;

import java.util.ArrayList;

public class MulExp {
    private UnaryExp firstUnaryExp;
    private ArrayList<Token> operators; //*/%可以没有
    private ArrayList<UnaryExp> unaryExps; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "MulExp";

    public MulExp(TokenList tokens) {
        this.firstUnaryExp = null;
        this.operators = new ArrayList<>();
        this.unaryExps = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstUnaryExp = new UnaryExp(tokens);
        errorNum += firstUnaryExp.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.MULT) || token.equals(LexType.DIV) || token.equals(LexType.MOD)) {
            operators.add(token);
            UnaryExp unaryExp = new UnaryExp(tokens);
            errorNum += unaryExp.parse();
            unaryExps.add(unaryExp);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstUnaryExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        for (int i = 0;i < unaryExps.size();i++) {
            sb.append(operators.get(i)).append(unaryExps.get(i).toSyntaxTree());
            //改造左递归文法，但输出语法树时仍需按照左递归规则输出
            sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        }
        return sb.toString();
    }
}
