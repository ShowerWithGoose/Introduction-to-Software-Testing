package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.UnaryExp.LVal;

public class StmtGetInt implements StmtElement {
    private LVal lVal;
    private Token assign;
    private Token getint;
    private Token lparent;
    private Token rparent;
    private Token semicn;
    private TokenList tokens;
    private int errorNum;

    public StmtGetInt(TokenList tokens) {
        this.lVal = null;
        this.assign = null;
        this.getint = null;
        this.lparent = null;
        this.rparent = null;
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        lVal = new LVal(tokens);
        errorNum += lVal.parse();
        assign = tokens.nextToken();
        getint = tokens.nextToken();
        lparent = tokens.nextToken();
        Token token = tokens.nextToken();
        if (token.equals(LexType.RPARENT)) {
            rparent = token;
        } else {
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'j');
            errorNum++;
            tokens.rollBack(1);
        }
        token = tokens.nextToken();
        if (token.equals(LexType.SEMICN)) {
            semicn = token;
        } else {
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'i');
            errorNum++;
            tokens.rollBack(1);
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(lVal.toSyntaxTree()).append(assign).append(getint).append(lparent);
        if (rparent != null) {
            sb.append(rparent);
        }
        if (semicn != null) {
            sb.append(semicn);
        }
        return sb.toString();
    }
}
