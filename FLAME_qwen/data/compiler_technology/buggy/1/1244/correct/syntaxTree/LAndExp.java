package syntaxTree;

public class LAndExp {
    private final LAndExp left;
    private final EqExp right;

    public LAndExp(LAndExp left, EqExp right) {
        this.left = left;
        this.right = right;
    }
}
