package frontend.parser.Block;

import frontend.lexer.Token;
import frontend.lexer.TokenList;

public class StmtSemicn implements StmtElement {
    private Token semicn; //不管错误与否都必须有，不然变成空行了
    private TokenList tokens;
    private int errorNum;

    public StmtSemicn(TokenList tokens) {
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        semicn = tokens.nextToken();
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(semicn);
        return sb.toString();
    }
}
