package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Node;

public class CharConst implements Node {
    private Token token;
    private TokenList tokenList;

    public CharConst(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseCharConst(){
        this.token = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        return sb.toString();
    }
}
