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
    private List<V> children = new ArrayList<>();
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
        this.vnType = vnType;
    }

    /**
     * 添加子节点
     * @param v 子节点
     */
    public void addChild(V v) {
        children.add(v);
    }

    /**
     * 重写 toString 方法
     *
     * @return 返回 token 的类型
     */
    @Override
    public String toString() {
        return "<" + vnType.name() + ">";
    }
}
