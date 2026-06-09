package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;

public class FuncType implements Node {
    private final String name = "<FuncType>";
    private Token token;

    private TokenList tokenList;

    public FuncType(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseFuncType(){
        Token first = tokenList.getNextToken();
        this.token = first;
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        sb.append(this.name + "\n");
        /* not output BType according to assignment requirement */
        return sb.toString();
    }
}
