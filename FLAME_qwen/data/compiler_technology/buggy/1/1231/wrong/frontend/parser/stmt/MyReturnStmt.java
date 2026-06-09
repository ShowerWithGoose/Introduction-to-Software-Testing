package frontend.parser.stmt;

import java.util.ArrayList;

import error.ErrorHandler;
import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

//                MyReturnStmt      == >       'return' [Exp] ';' // f i
public class MyReturnStmt implements StmtNode {

    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private Exp exp; // optional

    public MyReturnStmt(TokenIterator tokens) {
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
        // 'return'
        children.add(tokens.next());

        Token token = tokens.next();
        TokenType tokenType = token.getType();
        tokens.stepBack(1);
        switch (tokenType) {
            case LPARENT:
            case INTCON:
            case CHRCON:
            case PLUS:
            case MINU:
            case IDENFR:
                // FIXME: may have bug here
                exp = new Exp(tokens);
                exp.parse();
                children.add(exp);
                break;
            default:
                break;
        }

        ErrorHandler.handleIError(tokens, children);
        return true;

    }

}
