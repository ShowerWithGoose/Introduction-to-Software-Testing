package node;

/**
 * ClassName: Exp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:49
 * @Version 1.0
 */
public class Exp extends Node{
    // Exp -> AddExp
    public AddExp addExp;

    public Exp(AddExp addExp) {
        this.addExp = addExp;
        setLineNo(addExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(addExp.getPrintInfo());
        info.append("<Exp>\n");
        return info;
    }


}
