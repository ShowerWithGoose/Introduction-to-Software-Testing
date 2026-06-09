package frontend.Parser.declaration;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;

public class BType implements GrammarNode {
    private final String grammarName = "<BType>";
    private Token token;

    public BType(Token token) {
        this.token = token;
    }

    public String grammarOutput(){
        return this.token.grammarOutput();
    }
}
