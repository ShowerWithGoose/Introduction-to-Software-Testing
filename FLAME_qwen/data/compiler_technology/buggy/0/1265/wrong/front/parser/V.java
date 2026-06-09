package front.parser;

import front.lexer.Token;

/**
 * 语法树上的一个 token
 */
public class V {
    /**
     * 是否为 Vn
     */
    private boolean isVn;
    /**
     * 非终结符信息 | null if 不是 Vn
     */
    private Vn vn;
    /**
     * 终结符信息 | null if 是 Vn
     */
    private Token vt;
    /**
     * 父节点引用
     */
    private V parent;

    /**
     * 构造方法
     *
     * @param isVn 是否为 Vn
     * @param vn   Vn 的信息
     * @param vt   Vt 的信息
     */
    public V(boolean isVn, Vn vn, Token vt) {
        if (isVn) {
            if (vn == null) {
                System.out.println("init vn info!!!");
                return;
            }
            this.vn = vn;
        } else {
            if (vt == null) {
                System.out.println("init vt info!!!");
                return;
            }
            this.vt = vt;
        }
    }

    /**
     * 添加子节点
     *
     * @param v 子节点
     */
    public void addChild(V v) {
        if (!isVn) {
            System.out.println("can not add child to Vt");
            return;
        }
        vn.addChild(v);
        v.parent = this;
    }

    /**
     * 获得父节点
     *
     * @return 父节点引用
     */
    public V getParent() {
        return parent;
    }

    /**
     * 重写 toString 方法
     *
     * @return 一行 Vn 或者 Vt 的输出
     */
    @Override
    public String toString() {
        if (isVn) {
            return vn.toString();
        } else {
            return vt.toString();
        }
    }
}
