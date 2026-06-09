package node;

import token.Token;

/**
 * ClassName: ForStmt
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 19:47
 * @Version 1.0
 */
public class ForStmt extends Node{
    // ForStmt => LVal '=' Exp
    public LVal lVal;
    public Token assign;
    public Exp exp;


    public ForStmt(LVal lVal, Token assign, Exp exp) {
        this.lVal = lVal;
        this.assign = assign;
        this.exp = exp;
        setLineNo(lVal);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(lVal.getPrintInfo());
        info.append(assign.getPrintInfo());
        info.append(exp.getPrintInfo());
        info.append("<ForStmt>\n");
        return info;
    }
}
