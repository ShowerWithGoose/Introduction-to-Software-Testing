package frontend.Parser.SyntaxNode;

public class Cond implements SyntaxNode {
    private final String name = "<Cond>";
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String toString() {
        return lOrExp.toString() + name + "\n";
    }
}
