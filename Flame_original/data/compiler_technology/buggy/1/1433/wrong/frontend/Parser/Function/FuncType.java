package frontend.Parser.Function;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;

public class FuncType implements ASTNode {
    private Token typeToken;    // 'void' | 'int' | 'char'

    public FuncType(Token typeToken) {
        this.typeToken = typeToken;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(typeToken);
        sb.append("<" + "FuncType" + ">\n");
        return sb.toString();
    }
}
