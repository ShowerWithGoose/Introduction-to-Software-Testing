package frontend.parser.Function;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class FuncFParam {
    private Token btype; //int char
    private Token ident;
    private Token lbrack; //[可以没有
    private Token rbrack; //]可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "FuncFParam";

    public FuncFParam(TokenList tokens) {
        this.btype = null;
        this.ident = null;
        this.lbrack = null;
        this.rbrack = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        btype = tokens.nextToken();
        ident = tokens.nextToken();
        Token token = tokens.nextToken();
        if (token.equals(LexType.LBRACK)) {
            lbrack = token;
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
        sb.append(btype).append(ident);
        if (lbrack != null) {
            sb.append(lbrack);
            if (rbrack != null) {
                sb.append(rbrack);
            }
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
