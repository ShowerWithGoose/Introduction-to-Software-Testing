package Parser.Exp;

import Parser.TreeNode;

import java.util.TreeMap;

/**
 * @Description:
 * @date 2024/10/13
 */
public class Cond implements TreeNode {
    private final String value = "<Cond>";
    private LOrExp lorExp;

    public Cond(LOrExp lorExp) {
        this.lorExp = lorExp;
    }

    @Override
    public String print_tree() {
        StringBuilder sb=new StringBuilder();
        sb.append(this.lorExp.print_tree());
        sb.append(this.value).append("\n");
        return sb.toString();
    }
}
