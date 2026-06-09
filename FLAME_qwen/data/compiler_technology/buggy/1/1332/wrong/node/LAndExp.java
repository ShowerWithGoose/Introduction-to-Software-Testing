package node;

import token.Token;

/**
 * ClassName: LAndExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:14
 * @Version 1.0
 */
public class LAndExp extends Node{
    // LAmdExp => EqExp | LAndExp '&&' EqExp
    // LAmdExp => EqExp | EqExp '&&' LAndExp // 右递归
    public EqExp eqExp;
    public Token and;
    public LAndExp lAndExp;

    public LAndExp(EqExp eqExp, Token and, LAndExp lAndExp) {
        this.eqExp = eqExp;
        this.and = and;
        this.lAndExp = lAndExp;
        setLineNo(eqExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(eqExp.getPrintInfo());
        info.append("<LAndExp>\n");
        if(lAndExp != null){
            info.append(and.getPrintInfo());
            info.append(lAndExp.getPrintInfo());
        }
        return info;
    }
}
