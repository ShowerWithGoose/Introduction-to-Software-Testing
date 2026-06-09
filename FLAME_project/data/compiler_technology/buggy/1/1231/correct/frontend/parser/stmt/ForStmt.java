package frontend.parser.stmt;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import frontend.parser.exp.primaryexp.LVal;
import nodes.SyntaxNode;
import nodes.Token;

/*
 *语句		    ForStmt        ==> LVal '=' Exp
*/
public class ForStmt implements SyntaxNode {
    private static String name = "<ForStmt>";
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private LVal lVal;
    private Exp exp;

    public ForStmt(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        sb.append(name + "\n");
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
        return true;
    }

}
