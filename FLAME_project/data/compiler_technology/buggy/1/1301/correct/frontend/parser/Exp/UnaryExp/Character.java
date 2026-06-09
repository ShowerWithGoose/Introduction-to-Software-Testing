package frontend.parser.Exp.UnaryExp;

import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class Character {
    private Token charConst;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "Character";

    public Character(TokenList tokens) {
        this.charConst = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        charConst = tokens.nextToken();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(charConst);
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
