package frontend.parser.declaration;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;

public class BType implements Node {
    private final String name = "<BType>";
    private Token token; // not must be INTTK CHARTK

    private TokenList tokenList;

    public BType(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseBType(){
        Token first = tokenList.getNextToken();
        this.token = first;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        /* not output BType according to assignment requirement */
        return sb.toString();
    }
}
