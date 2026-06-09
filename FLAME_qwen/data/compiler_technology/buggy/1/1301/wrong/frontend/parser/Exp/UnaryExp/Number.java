package frontend.parser.Exp.UnaryExp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class Number {
    private Token intConst;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "Number";

    public Number(TokenList tokens) {
        this.intConst = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        intConst = tokens.nextToken();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(intConst);
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
