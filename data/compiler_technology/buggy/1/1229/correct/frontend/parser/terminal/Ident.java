package frontend.parser.terminal;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

public class Ident implements Node {
    private Token token;
    private TokenList tokenList;

    public Ident(TokenList tokenList){
        this.tokenList = tokenList;
    }

    public void parseIdent(){
        this.token = tokenList.getNextToken();
    }

    public String getName() {
        return this.token.getContent();
    }

    public int getLineNum() {
        return this.token.getLineNum();
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(token.syntaxOutput());
        return sb.toString();
    }

    @Override
    public String toString() {
        return this.token.getContent();
    }
}
