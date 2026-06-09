package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/12 16:42
 */
public class ConstExp implements SyntaxNode{
    private final String name = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.addExp.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
