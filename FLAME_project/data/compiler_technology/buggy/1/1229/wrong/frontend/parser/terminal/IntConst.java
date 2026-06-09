package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

public class IntConst implements Node {
    private Token token;
    private TokenList tokenList;

    public IntConst(TokenList tokenList) {
        this.tokenList = tokenList;
    }

    public void parseIntConst(){
        this.token = tokenList.getNextToken();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        return sb.toString();
    }
}
