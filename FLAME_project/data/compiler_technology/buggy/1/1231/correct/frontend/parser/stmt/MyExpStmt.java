package frontend.parser.stmt;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import nodes.SyntaxNode;

// MyExpStmt      ==>       Exp ';' // i
public class MyExpStmt implements StmtNode {
    private TokenIterator tokens;

    public MyExpStmt(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Exp exp;

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        return sb.toString();
    }

    @Override
    public boolean parse() {
        exp = new Exp(tokens);
        exp.parse();
        children.add(exp);

        ErrorHandler.handleIError(tokens, children);

        return true;
    }

}
