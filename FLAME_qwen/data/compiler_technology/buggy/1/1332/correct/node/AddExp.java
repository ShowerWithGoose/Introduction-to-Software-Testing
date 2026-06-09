package node;

import token.Token;

/**
 * ClassName: AddExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:02
 * @Version 1.0
 */
public class AddExp extends Node {
    // AddExp -> MulExp | AddExp ('+' | '−') MulExp // 文法
    // AddExp -> MulExp | MulExp ('+' | '−') AddExp // 右递归
    // AddExp -> MulExp (('+' | '−') AddExp | ε) // 建树方式，但打印不是这么打印的
    public MulExp mulExp;
    public AddExp addExp;
    public Token op; // 如果按递归，不用List

    public AddExp(MulExp mulExp, AddExp addExp, Token op) {
        this.mulExp = mulExp;
        this.addExp = addExp;
        this.op = op;
        setLineNo(mulExp);
    }

    public StringBuilder getPrintInfo() {
        StringBuilder info = new StringBuilder();
        info.append(mulExp.getPrintInfo());
        info.append("<AddExp>\n");
        if (addExp != null) {
            info.append(op.getPrintInfo());
            info.append(addExp.getPrintInfo());
        }
        return info;
    }

}
