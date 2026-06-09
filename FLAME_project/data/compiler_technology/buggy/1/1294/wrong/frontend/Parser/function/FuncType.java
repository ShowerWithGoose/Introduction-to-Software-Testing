package frontend.Parser.function;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;

public class FuncType implements GrammarNode {
    private final String grammarName = "<FuncType>";
    private Token token;
    public FuncType(Token token) {
        this.token = token;
    }

    @Override
    public String grammarOutput() {
        StringBuilder sb= new StringBuilder();
        sb.append(this.token.grammarOutput());
        sb.append(grammarName).append("\n");
        return sb.toString();
    }
}
