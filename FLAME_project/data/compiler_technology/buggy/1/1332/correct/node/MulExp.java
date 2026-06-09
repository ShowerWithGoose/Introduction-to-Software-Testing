package node;

import token.Token;

/**
 * ClassName: MulExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:06
 * @Version 1.0
 */
public class MulExp extends Node{
    // MulExp -> UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    // MulExp -> UnaryExp | UnaryExp ('*' | '/' | '%') MulExp  // 右递归
    // MulExp -> UnaryExp (('*' | '/' | '%') MulExp | ε) // 建树方式，但打印不是这么打印的
    public UnaryExp unaryExp;
    public Token op;
    public MulExp mulExp;

    public MulExp(UnaryExp unaryExp, Token op, MulExp mulExp) {
        this.unaryExp = unaryExp;
        this.op = op;
        this.mulExp = mulExp;
        setLineNo(unaryExp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        info.append(unaryExp.getPrintInfo());
        info.append("<MulExp>\n");
        if(mulExp != null){
            info.append(op.getPrintInfo());
            info.append(mulExp.getPrintInfo());
        }
        return info;
    }
}

