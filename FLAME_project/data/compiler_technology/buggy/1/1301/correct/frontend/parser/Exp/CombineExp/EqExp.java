package frontend.parser.Exp.CombineExp;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

import java.util.ArrayList;

public class EqExp {
    private RelExp firstRelExp;
    private ArrayList<Token> operators; //+-可以没有
    private ArrayList<RelExp> relExps; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "EqExp";

    public EqExp(TokenList tokens) {
        this.firstRelExp = null;
        this.operators = new ArrayList<>();
        this.relExps = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstRelExp = new RelExp(tokens);
        errorNum += firstRelExp.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.EQL) || token.equals(LexType.NEQ)) {
            operators.add(token);
            RelExp relExp = new RelExp(tokens);
            errorNum += relExp.parse();
            relExps.add(relExp);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstRelExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        for (int i = 0;i < relExps.size();i++) {
            sb.append(operators.get(i)).append(relExps.get(i).toSyntaxTree());
            //改造左递归文法，但输出语法树时仍需按照左递归规则输出
            sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        }
        return sb.toString();
    }
}
