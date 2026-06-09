package node;

import token.Token;

/**
 * ClassName: LOrExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 16:09
 * @Version 1.0
 */
public class LOrExp extends Node{
    // LOrExp => LAndExp | LOrExp '||' LAndExp
    // LOrExp => LAndExp | LAndExp '||' LOrExp // 右递归
    public LAndExp lAndExp;
    public Token or;
    public LOrExp lOrExp;

    public LOrExp(LAndExp lAndExp, Token or, LOrExp lOrExp) {
        this.lAndExp = lAndExp;
        this.or = or;
        this.lOrExp = lOrExp;
        setLineNo(lAndExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(lAndExp.getPrintInfo());
        info.append("<LOrExp>\n");
        if(lOrExp != null){
            info.append(or.getPrintInfo());
            info.append(lOrExp.getPrintInfo());
        }
        return info;
    }
}
