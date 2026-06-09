package frontend.parser.Block;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;
import frontend.parser.Exp.UnaryExp.LVal;

public class StmtAssign implements StmtElement {
    private LVal lVal;
    private Token assign;
    private Exp exp;
    private Token semicn;
    private TokenList tokens;
    private int errorNum;

    public StmtAssign(TokenList tokens) {
        this.lVal = null;
        this.assign = null;
        this.exp = null;
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        lVal = new LVal(tokens);
        errorNum += lVal.parse();
        assign = tokens.nextToken();
        exp = new Exp(tokens);
        errorNum += exp.parse();
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
        sb.append(lVal.toSyntaxTree()).append(assign).append(exp.toSyntaxTree());
        if (semicn != null) {
            sb.append(semicn);
        }
        return sb.toString();
    }
}
