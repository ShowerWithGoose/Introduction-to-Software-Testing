package frontend.parser.Exp.UnaryExp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class UnaryOp {
    private Token operator; //+-!
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "UnaryOp";

    public UnaryOp(TokenList tokens) {
        this.operator = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        operator = tokens.nextToken();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(operator);
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
