package frontend.parser.Function;

import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class FuncType {
    private Token funcType; //void int char
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "FuncType";

    public FuncType(TokenList tokens) {
        this.funcType = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        funcType = tokens.nextToken();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType);
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
