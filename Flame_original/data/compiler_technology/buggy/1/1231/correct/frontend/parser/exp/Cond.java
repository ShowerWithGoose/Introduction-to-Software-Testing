package frontend.parser.exp;

import frontend.TokenIterator;
import nodes.SyntaxNode;

// 条件表达式		Cond           ==> LOrExp
public class Cond implements SyntaxNode {
    private static String name = "<Cond>";
    private TokenIterator tokens;

    public Cond(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private LOrExp lOrExp;

    @Override
    public String syntaxPrinter() {
        return lOrExp.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        lOrExp = new LOrExp(tokens);
        return lOrExp.parse();
    }

}
