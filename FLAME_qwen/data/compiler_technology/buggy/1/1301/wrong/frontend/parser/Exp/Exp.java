package frontend.parser.Exp;

import frontend.lexer.TokenList;
import frontend.parser.Exp.CombineExp.AddExp;

public class Exp {
    private AddExp addExp;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "Exp";

    public Exp(TokenList tokens) {
        this.addExp = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        addExp = new AddExp(tokens);
        errorNum += addExp.parse();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(addExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
