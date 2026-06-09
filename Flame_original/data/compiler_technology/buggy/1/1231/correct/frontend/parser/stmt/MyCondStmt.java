package frontend.parser.stmt;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.Cond;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// MyCondStmt        == >      'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j

public class MyCondStmt implements StmtNode {

    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Cond cond;
    private Stmt ifStmt;
    private Stmt elseStmt; //optional

    public MyCondStmt(TokenIterator tokens) {
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
        // 'if'
        children.add(token);

        token = tokens.next();
        // '('
        children.add(token);

        // 'Cond'
        cond = new Cond(tokens);
        cond.parse();
        children.add(cond);

        ErrorHandler.handleJError(tokens, children);

        ifStmt = new Stmt(tokens);
        ifStmt.parse();
        children.add(ifStmt);

        token = tokens.next();
        // 'else'
        if (token.getType().equals(TokenType.ELSETK)) {
            children.add(token);

            elseStmt = new Stmt(tokens);
            elseStmt.parse();
            children.add(elseStmt);
        } else {
            tokens.stepBack(1);
        }
        return true;
    }
}
