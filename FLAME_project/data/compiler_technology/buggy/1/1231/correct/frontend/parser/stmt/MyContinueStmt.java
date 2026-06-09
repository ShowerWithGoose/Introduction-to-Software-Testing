package frontend.parser.stmt;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;

//                 MyContinueStmt    == >       'continue' ';' // i m
public class MyContinueStmt implements StmtNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    MyContinueStmt(TokenIterator tokens) {
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
        Token token = tokens.next();
        children.add(token);

        ErrorHandler.handleIError(tokens, children);
        return true;
    }

}
