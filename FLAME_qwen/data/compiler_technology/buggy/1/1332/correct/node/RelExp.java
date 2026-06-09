package node;

import token.Token;

/**
 * ClassName: RelExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:17
 * @Version 1.0
 */
public class RelExp extends Node{
    // RelExp => AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    // RelExp => AddExp | AddExp ('<' | '>' | '<=' | '>=') RelExp // 右递归

    public AddExp addExp;
    public Token op;
    public RelExp relExp;


    public RelExp(AddExp addExp, Token op, RelExp relExp) {
        this.addExp = addExp;
        this.op = op;
        this.relExp = relExp;
        setLineNo(addExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(addExp.getPrintInfo());
        info.append("<RelExp>\n");
        if(relExp != null){
            info.append(op.getPrintInfo());
            info.append(relExp.getPrintInfo());
        }
        return info;
    }

}
