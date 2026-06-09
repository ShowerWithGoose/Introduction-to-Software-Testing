package syntaxTree;

public class LOrExp {
    private final LOrExp left;
    private final LAndExp right;

    public LOrExp(LOrExp left, LAndExp right) {
        this.left = left;
        this.right = right;
    }
}
