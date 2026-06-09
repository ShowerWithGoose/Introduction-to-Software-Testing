package node;

import token.Token;

/**
 * ClassName: EqExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:15
 * @Version 1.0
 */
public class EqExp extends Node{
    // EqExp => RelExp | EqExp ('==' | '!=') RelExp
    // EqExp => RelExp | RelExp ('==' | '!=') EqExp // 右递归

    public RelExp relExp;
    public Token op;
    public EqExp eqExp;

    public EqExp(RelExp relExp) {
        this.relExp = relExp;
        setLineNo(relExp);
    }

    public EqExp(RelExp relExp, Token op, EqExp eqExp) {
        this.relExp = relExp;
        this.op = op;
        this.eqExp = eqExp;
        setLineNo(relExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(relExp.getPrintInfo());
        info.append("<EqExp>\n");
        if(eqExp != null){
            info.append(op.getPrintInfo());
            info.append(eqExp.getPrintInfo());
        }
        return info;
    }
}
