package frontend.parser.Exp;

import frontend.lexer.TokenList;
import frontend.parser.Exp.CombineExp.LOrExp;

public class Cond {
    private LOrExp lOrExp;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "Cond";

    public Cond(TokenList tokens) {
        this.lOrExp = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        lOrExp = new LOrExp(tokens);
        errorNum += lOrExp.parse();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(lOrExp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
