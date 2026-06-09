package Parser.Exp;

import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/13
 */
public class Exp implements TreeNode {
    private final String name = "<Exp>";
    private AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
    }

    public AddExp getAddExp() {
        return addExp;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.addExp.print_tree());
        sb.append(this.name).append("\n");
        return sb.toString();
    }
}
