package frontend.parser.exp.primaryexp;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import frontend.parser.terminal.Ident;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 左值表达式		LVal           ==> Ident ['[' Exp ']'] // c k
public class LVal implements PrimaryExpNode {
    private final String name = "<LVal>";
    private TokenIterator tokens;

    public LVal(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Ident ident;
    private Exp exp; // optional

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public boolean parse() {
        ident = new Ident(tokens);
        ident.parse();
        children.add(ident);

        Token token = tokens.next();
        if (token.getType().equals(TokenType.LBRACK)) {
            // array
            // '['
            children.add(token);

            exp = new Exp(tokens);
            exp.parse();
            children.add(exp);

            ErrorHandler.handleKError(tokens, children);
        } else {
            // not array
            tokens.stepBack(1);
        }

        return true;
    }

}
