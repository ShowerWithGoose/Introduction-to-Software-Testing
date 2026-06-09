/********************************************************************************
 * @FileName     : VarDef.java
 * @Author       :
 * @Description  : 变量定义
 * @Notice       : VarDef -> Ident { '[' ConstExp ']' } | Ident { '[' ConstExp ']' } '=' InitVal
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class VarDef implements ASTNode {

    private Ident ident;
    private List<Token> leftBrackets;
    private List<ConstExp> constExpNodes;
    private List<Token> rightBrackets;
    private Token assign;
    private InitVal initVal;

    public VarDef(Ident ident, List<Token> leftBrackets, List<ConstExp> constExpNodes, List<Token> rightBrackets, Token assign, InitVal initVal) {
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.constExpNodes = constExpNodes;
        this.rightBrackets = rightBrackets;
        this.assign = assign;
        this.initVal = initVal;
    }

    @Override
    public void printInfo() {
        ident.printInfo();
        for (int i = 0; i < leftBrackets.size(); i++) {
            IOTools.parserOutput(leftBrackets.get(i).toString());
            constExpNodes.get(i).printInfo();
            IOTools.parserOutput(rightBrackets.get(i).toString());
        }
        if (initVal != null) {
            IOTools.parserOutput(assign.toString());
            initVal.printInfo();
        }
        IOTools.parserOutput(ASTNodeType.VarDef.toString());
    }

    public Ident getIdent() {
        return ident;
    }

    public void setIdent(Ident ident) {
        this.ident = ident;
    }

    public List<Token> getLeftBrackets() {
        return leftBrackets;
    }

    public void setLeftBrackets(List<Token> leftBrackets) {
        this.leftBrackets = leftBrackets;
    }

    public List<ConstExp> getConstExpNodes() {
        return constExpNodes;
    }

    public void setConstExpNodes(List<ConstExp> constExpNodes) {
        this.constExpNodes = constExpNodes;
    }

    public List<Token> getRightBrackets() {
        return rightBrackets;
    }

    public void setRightBrackets(List<Token> rightBrackets) {
        this.rightBrackets = rightBrackets;
    }

    public Token getAssign() {
        return assign;
    }

    public void setAssign(Token assign) {
        this.assign = assign;
    }

    public InitVal getInitVal() {
        return initVal;
    }

    public void setInitVal(InitVal initVal) {
        this.initVal = initVal;
    }
}
