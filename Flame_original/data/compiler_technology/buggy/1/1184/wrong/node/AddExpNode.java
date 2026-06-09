package node;

import java.util.ArrayList;

public class AddExpNode implements TreeNode {
    private ArrayList<TreeNode> nodes;


    public AddExpNode(ArrayList<TreeNode> list) {
        this.nodes = new ArrayList<>();
        if (list.size() == 1) {
            this.nodes = list;
        }
        else {
            TreeNode last0 = list.get(list.size() - 1);
            TreeNode last1 = list.get(list.size() - 2);
            list.remove(last0);
            list.remove(last1);
            nodes.add(new AddExpNode(list));
            nodes.add(last1);
            nodes.add(last0);
        }
    }

    public ArrayList<TreeNode> getNodes() {
        return nodes;
    }

    @Override
    public void print() {
        for (TreeNode t : nodes) {
            t.print();
        }
        System.out.println("<AddExp>");
    }

    public int getLine() {
        return nodes.get(nodes.size() - 1).getLine();
    }
}
