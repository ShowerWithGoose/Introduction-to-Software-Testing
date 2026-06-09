package front.parser;

import java.util.ArrayList;
import java.util.List;

/**
 * 非终结符类
 */
public class Vn {
    /**
     * 子节点列表
     */
    private List<V> children;
    /**
     * Vn 类型
     */
    private VnType vnType;

    /**
     * Vn 构造方法
     *
     * @param vnType Vn 类型
     */
    public Vn(VnType vnType) {
        children = new ArrayList<>();
        this.vnType = vnType;
    }

    /**
     * 添加子节点
     *
     * @param v 子节点
     */
    public void addChild(V v) {
        children.add(v);
    }

    /**
     * 移除最后的子节点
     */
    public void removeLastChild() {
        children.remove(children.size() - 1);
    }

    /**
     * 获取子节点列表
     *
     * @return 子节点列表
     */
    public List<V> getChildren() {
        return children;
    }

    /**
     * set 子节点列表
     *
     * @param children 子节点列表
     */
    public void setChildren(List<V> children) {
        this.children = children;
    }

    /**
     * 获取 Vn 类型
     *
     * @return Vn 类型
     */
    public VnType getVnType() {
        return vnType;
    }

    /**
     * 重写 toString 方法
     *
     * @return 返回 token 的类型
     */
    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for (V child : children) {
            stringBuilder.append(child).append("\n");
        }
        if (vnType.isPrintable()) {
            stringBuilder.append("<").append(vnType.name()).append(">");
        } else {
            stringBuilder.delete(stringBuilder.length() - 1, stringBuilder.length()); // 删掉多余的换行符
        }
        return stringBuilder.toString();
    }
}
