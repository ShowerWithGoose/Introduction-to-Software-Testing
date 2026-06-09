package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/13 12:51
 */
public class Cond implements SyntaxNode{
    private final String name = "<Cond>";
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.lOrExp.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
