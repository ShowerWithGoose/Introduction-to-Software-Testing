/********************************************************************************
 * @FileName     : UnaryExp.java
 * @Author       :
 * @Description  : 一元表达式
 * @Notice       : UnaryExp -> PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

public class UnaryExp implements ASTNode {
    private PrimaryExp primaryExp = null;
    private Ident ident = null;
    private Token leftParentToken = null;
    private FuncRParams funcRParams = null;
    private Token rightParentToken = null;
    private UnaryOp unaryOp = null;
    private UnaryExp unaryExp = null;

    public UnaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public UnaryExp(Ident ident, Token leftParentToken, FuncRParams funcRParams, Token rightParentToken) {
        this.ident = ident;
        this.leftParentToken = leftParentToken;
        this.funcRParams = funcRParams;
        this.rightParentToken = rightParentToken;
    }

    public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    @Override
    public void printInfo() {
        if (primaryExp != null) {
            primaryExp.printInfo();
        }
        else if (ident != null) {
            ident.printInfo();
            IOTools.parserOutput(leftParentToken.toString());
            if (funcRParams != null) {
                funcRParams.printInfo();
            }
            IOTools.parserOutput(rightParentToken.toString());
        }
        else {
            unaryOp.printInfo();
            unaryExp.printInfo();
        }
        IOTools.parserOutput(ASTNodeType.UnaryExp.toString());
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }

    public void setPrimaryExp(PrimaryExp primaryExp) {
        this.primaryExp = primaryExp;
    }

    public Ident getIdent() {
        return ident;
    }

    public void setIdent(Ident ident) {
        this.ident = ident;
    }

    public Token getLeftParentToken() {
        return leftParentToken;
    }

    public void setLeftParentToken(Token leftParentToken) {
        this.leftParentToken = leftParentToken;
    }

    public FuncRParams getFuncRParams() {
        return funcRParams;
    }

    public void setFuncRParams(FuncRParams funcRParams) {
        this.funcRParams = funcRParams;
    }

    public Token getRightParentToken() {
        return rightParentToken;
    }

    public void setRightParentToken(Token rightParentToken) {
        this.rightParentToken = rightParentToken;
    }

    public UnaryOp getUnaryOp() {
        return unaryOp;
    }

    public void setUnaryOp(UnaryOp unaryOp) {
        this.unaryOp = unaryOp;
    }

    public UnaryExp getUnaryExp() {
        return unaryExp;
    }

    public void setUnaryExp(UnaryExp unaryExp) {
        this.unaryExp = unaryExp;
    }
}
