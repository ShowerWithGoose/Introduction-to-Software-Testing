package frontend.parser.exp.unaryexp;

import frontend.TokenIterator;
import frontend.parser.exp.primaryexp.PrimaryExp;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

//UnaryExp       ==> PrimaryExp | MyFuncCallUnaryExp | MyOpUnaryExp
public class UnaryExp implements SyntaxNode {

    private static String name = "<UnaryExp>";
    private TokenIterator tokens;
    private UnaryExpNode unaryExpNode;

    public UnaryExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        sb.append(unaryExpNode.syntaxPrinter());
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public boolean parse() {
        Token token1 = tokens.next();
        Token token2 = tokens.next();
        tokens.stepBack(2);
        if (matchMyFuncCallUnaryExp(token1, token2)) {
            unaryExpNode = new MyFuncCallUnaryExp(tokens);
        } else if (matchMyOpUnaryExp(token1)) {
            unaryExpNode = new MyOpUnaryExp(tokens);
        } else {
            unaryExpNode = new PrimaryExp(tokens);
        }
        return unaryExpNode.parse();
    }

    private boolean matchMyFuncCallUnaryExp(Token token1, Token token2) {
        return token1.getType().equals(TokenType.IDENFR) && token2.getType().equals(TokenType.LPARENT);
    }

    private boolean matchMyOpUnaryExp(Token token) {
        return UnaryOp.isUnaryOp(token);
    }
}
