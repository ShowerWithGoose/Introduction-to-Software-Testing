package frontend.parser.func;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

//函数类型		FuncType       ==> 'void' | 'int' | 'char'
public class FuncType implements SyntaxNode {
    private String name = "<FuncType>";
    private TokenIterator tokens;

    private Token token;

    public FuncType(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return token.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        token = tokens.next();
        if (token.getType() == TokenType.VOIDTK || token.getType() == TokenType.INTTK
                || token.getType() == TokenType.CHARTK) {
            return true;
        } else {
            tokens.stepBack(1);
            return false;
        }
    }

}
