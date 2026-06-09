package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class StmtBreak implements StmtElement {
    private Token breakTk;
    private Token semicn;
    private TokenList tokens;
    private int errorNum;

    public StmtBreak(TokenList tokens) {
        this.breakTk = null;
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        breakTk = tokens.nextToken();
        Token token = tokens.nextToken();
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
        sb.append(breakTk);
        if (semicn != null) {
            sb.append(semicn);
        }
        return sb.toString();
    }
}
