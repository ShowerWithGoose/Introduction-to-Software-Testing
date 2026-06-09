package node;

import token.Token;

/**
 * ClassName: UnaryExp
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:25
 * @Version 1.0
 */
public class UnaryExp extends Node{
    // UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public PrimaryExp primaryExp;

    // invoke function
    public Token ident;
    public Token lparent;
    // parameters (optional)
    public FuncRParams funcRParams;
    public Token rparent;

    public UnaryOp unaryOp;
    public UnaryExp unaryExp;

    // UnaryExp -> PrimaryExp
    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
        setLineNo(primaryExp);
    }
    // UnaryExp -> Ident '(' [FuncRParams] ')'
    public UnaryExp(Token ident, Token lparent, Token rparent, FuncRParams funcRParams) {
        this.ident = ident;
        this.lparent = lparent;
        this.rparent = rparent;
        this.funcRParams = funcRParams;
        setLineNo(ident);
    }

    // UnaryExp -> UnaryOp UnaryExp
    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
        setLineNo(unaryOp);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        if(primaryExp != null) {
            info.append(primaryExp.getPrintInfo());
        }else if(ident != null){
            info.append(ident.getPrintInfo());
            info.append(lparent.getPrintInfo());
            if(funcRParams != null){
                info.append(funcRParams.getPrintInfo());
            }
            info.append(rparent.getPrintInfo());
        }else{
            info.append(unaryOp.getPrintInfo());
            info.append(unaryExp.getPrintInfo());
        }
        info.append("<UnaryExp>\n");
        return info;
    }

}
