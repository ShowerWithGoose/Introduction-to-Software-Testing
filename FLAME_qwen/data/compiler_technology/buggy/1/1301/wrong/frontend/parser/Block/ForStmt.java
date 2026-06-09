package frontend.parser.Block;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;
import frontend.parser.Exp.UnaryExp.LVal;

public class ForStmt {
    private LVal lVal;
    private Token assign;
    private Exp exp;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "ForStmt";

    public ForStmt(TokenList tokens) {
        this.lVal = null;
        this.assign = null;
        this.exp = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        lVal = new LVal(tokens);
        errorNum += lVal.parse();
        assign = tokens.nextToken();
        exp = new Exp(tokens);
        errorNum += exp.parse();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toSyntaxTree()).append(assign).append(exp.toSyntaxTree());
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
