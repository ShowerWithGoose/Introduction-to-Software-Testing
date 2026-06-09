package node;

/**
 * ClassName: ConstExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:54
 * @Version 1.0
 */
public class ConstExp extends Node{
    // ConstExp -> AddExp
    public AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
        setLineNo(addExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(addExp.getPrintInfo());
        info.append("<ConstExp>\n");
        return info;
    }
}
