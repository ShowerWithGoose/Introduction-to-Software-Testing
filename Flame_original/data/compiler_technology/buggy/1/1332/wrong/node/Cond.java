package node;

/**
 * ClassName: Cond
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:09
 * @Version 1.0
 */
public class Cond extends Node{
    // Cond => LOrExp
    public LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
        setLineNo(lOrExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(lOrExp.getPrintInfo());
        info.append("<Cond>\n");
        return info;
    }
}
