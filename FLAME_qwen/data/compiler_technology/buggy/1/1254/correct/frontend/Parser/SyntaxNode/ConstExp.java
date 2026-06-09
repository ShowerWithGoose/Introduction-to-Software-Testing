package frontend.Parser.SyntaxNode;

public class ConstExp implements SyntaxNode {
    private final String name = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString() {
        return addExp.toString() + name + "\n";
    }
}
