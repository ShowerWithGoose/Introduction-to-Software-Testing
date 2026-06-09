package fronted.Parser.SyntaxTree;

/**
 * @author
 * @Description:
 * @date 2024/10/12 21:26
 */
public class Exp implements SyntaxNode{
    private final String name = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
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
