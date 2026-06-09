package frontend.parser.stmt;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.primaryexp.LVal;
import nodes.SyntaxNode;
import nodes.Token;

// MyGetcharStmt     == >       LVal '=' 'getchar''('')'';' // h i j
public class MyGetcharStmt implements StmtNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private LVal lval;

    public MyGetcharStmt(TokenIterator tokens) {
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

        lval = new LVal(tokens);
        lval.parse();
        children.add(lval);

        // '='
        Token token = tokens.next();
        children.add(token);

        // 'getchar'
        token = tokens.next();
        children.add(token);

        // '('
        token = tokens.next();
        children.add(token);

        ErrorHandler.handleJError(tokens, children);
        ErrorHandler.handleIError(tokens, children);
        return true;
    }

}
