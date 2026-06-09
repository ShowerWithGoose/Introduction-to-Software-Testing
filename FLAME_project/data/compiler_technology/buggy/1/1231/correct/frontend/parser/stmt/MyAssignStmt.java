package frontend.parser.stmt;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import frontend.parser.exp.primaryexp.LVal;
import nodes.SyntaxNode;
import nodes.Token;

/*
 * MyAssignStmt   ==>       LVal '=' Exp ';'
*/
public class MyAssignStmt implements StmtNode {
    private TokenIterator tokens;

    public MyAssignStmt(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private LVal lVal;
    private Exp exp;

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        return sb.toString();
    }

    @Override
    public boolean parse() {
        lVal = new LVal(tokens);
        lVal.parse();
        children.add(lVal);

        Token token = tokens.next();
        children.add(token);

        exp = new Exp(tokens);
        exp.parse();
        children.add(exp);

        ErrorHandler.handleIError(tokens, children);
        return true;
    }

}
