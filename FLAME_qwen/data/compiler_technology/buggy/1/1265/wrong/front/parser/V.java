package front.parser;

import front.lexer.Token;
import front.lexer.TokenType;

import java.util.List;

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
        this.isVn = isVn;
        parent = null;
        if (isVn) {
            if (vn == null) {
                return;
            }
            this.vn = vn;
        } else {
            if (vt == null) {
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
        if (isVn) {
            vn.addChild(v);
            v.parent = this;
        }
    }

    /**
     * 移除最后的子节点
     */
    public void removeLastChild() {
        vn.removeLastChild();
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
     * 获取子节点列表
     *
     * @return 子节点列表
     */
    public List<V> getChildren() {
        return vn.getChildren();
    }

    /**
     * set 子节点列表
     *
     * @param children 子节点列表
     */
    public void setChildren(List<V> children) {
        vn.setChildren(children);
    }

    /**
     * 检验 V 是否为某些类型
     *
     * @param vnTypeList    检验的 Vn 类型
     * @param tokenTypeList 检验的 Vt 类型
     * @return 检验结果
     */
    public boolean inType(List<VnType> vnTypeList, List<TokenType> tokenTypeList) {
        return isVn && vnTypeList != null && vnTypeList.contains(vn.getVnType())
                || !isVn && tokenTypeList != null && tokenTypeList.contains(vt.getTokenType());
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
