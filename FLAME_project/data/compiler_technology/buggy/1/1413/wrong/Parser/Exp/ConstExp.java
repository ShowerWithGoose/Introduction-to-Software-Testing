package Parser.Exp;

import Parser.TreeNode;

/**
 * @Description:
 * @date 2024/10/11
 */
public class ConstExp implements TreeNode {
    private final String value = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(addExp.print_tree());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
