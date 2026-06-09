package frontend.parser.exp.primaryexp;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import nodes.SyntaxNode;
import nodes.Token;

// MyParenPrimaryExp == > '(' Exp ')' // j
public class MyParenPrimaryExp implements PrimaryExpNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Exp exp;

    public MyParenPrimaryExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        return sb.toString();
    }

    @Override
    public boolean parse() {
        Token token = tokens.next(); // consume '('
        children.add(token);

        exp = new Exp(tokens);
        exp.parse();
        children.add(exp);

        ErrorHandler.handleJError(tokens, children);
        return true;
    }

}
