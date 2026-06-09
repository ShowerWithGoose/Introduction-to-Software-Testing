package node;

import java.util.ArrayList;

public class LOrExpNode implements TreeNode{
    private ArrayList<TreeNode> nodes;
    public LOrExpNode(ArrayList<TreeNode> list) {
        this.nodes = new ArrayList<>();
        if (list.size() == 1) {
            this.nodes = list;
        }
        else {
            TreeNode last0 = list.get(list.size() - 1);
            TreeNode last1 = list.get(list.size() - 2);
            list.remove(last0);
            list.remove(last1);
            nodes.add(new LOrExpNode(list));
            nodes.add(last1);
            nodes.add(last0);
        }
    }

    @Override
    public void print() {
        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<LOrExp>");
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }
}
