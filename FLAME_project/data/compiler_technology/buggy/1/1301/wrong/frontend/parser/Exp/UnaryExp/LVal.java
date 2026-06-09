package frontend.parser.Exp.UnaryExp;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;

public class LVal {
    private Token ident;
    private Token lbrack; //[可以没有
    private Exp exp; //可以没有
    private Token rbrack; //]可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "LVal";

    public LVal(TokenList tokens) {
        this.ident = null;
        this.lbrack = null;
        this.exp = null;
        this.rbrack = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        ident = tokens.nextToken();
        Token token = tokens.nextToken();
        if (token.equals(LexType.LBRACK)) {
            lbrack = token;
            exp = new Exp(tokens);
            errorNum += exp.parse();
            token = tokens.nextToken();
            if (token.equals(LexType.RBRACK)) {
                rbrack = token;
            } else {
                ErrorHandling.printError(tokens.preNonTerminalLineNum(),'k');
                errorNum++;
                tokens.rollBack(1);
            }
        } else {
            tokens.rollBack(1);
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(ident);
        if (lbrack != null) {
            sb.append(lbrack).append(exp);
            if (rbrack != null) {
                sb.append(rbrack);
            }
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
