/*package Tree;

import java.util.ArrayList;
import java.util.List;

public class TreeUtils {

    // 递归遍历子树并收集叶节点的字符串
    public static List<String> collectLeafData(MultiTreeNode node) {
        List<String> leafDataList = new ArrayList<>();

        if (node.isLeaf()) {
            // 如果是叶节点，则添加到列表中
            if (node.getData() != null) {
                leafDataList.add(node.getData());
            }
        } else {
            // 否则递归遍历子节点
            for (MultiTreeNode child : node.getChildren()) {
                leafDataList.addAll(collectLeafData(child));
            }
        }

        return leafDataList;
    }
}*/
