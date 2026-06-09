package frontend.parser.func;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.BType;
import frontend.parser.terminal.Ident;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 函数形参		FuncFParam     ==> BType Ident ['[' ']']
public class FuncFParam implements SyntaxNode {
    private final String name = "<FuncFParam>";
    private TokenIterator tokens;

    public FuncFParam(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private ArrayList<SyntaxNode> children = new ArrayList<>();


    private BType bType;
    private Ident ident;
    private boolean isArray;

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public boolean parse() {
        bType = new BType(tokens);
        bType.parse();
        children.add(bType);

        ident = new Ident(tokens);
        ident.parse();
        children.add(ident);

        Token token = tokens.next();
        if (token.getType().equals(TokenType.LBRACK)) {
            children.add(token);
            ErrorHandler.handleKError(tokens, children);
        } else {
            tokens.stepBack(1);
        }
        return true;
    }
}
