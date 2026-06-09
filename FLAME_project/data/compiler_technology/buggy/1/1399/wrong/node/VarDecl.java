/********************************************************************************
 * @FileName     : VarDecl.java
 * @Author       :
 * @Description  : 变量声明
 * @Notice       : VarDecl -> BType VarDef { ',' VarDef } ';'
 * @Time         : 2024-10-14 10:50
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.LexType;
import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;

import java.util.List;

public class VarDecl implements ASTNode{

    private BType bTypeNode;
    private List<VarDef> varDefs;
    private List<Token> commas;
    private Token semicn;

    public VarDecl(BType bTypeNode, List<VarDef> varDefs, List<Token> commas, Token semicn) {
        this.bTypeNode = bTypeNode;
        this.varDefs = varDefs;
        this.commas = commas;
        this.semicn = semicn;
    }

    // 判断是否是 VarDecl
    public static boolean isVarDecl(LexType lType) {
        return BType.isBType(lType);
    }

    @Override
    public void printInfo() {
        bTypeNode.printInfo();
        varDefs.get(0).printInfo();
        for (int i = 1; i < varDefs.size(); i++) {
            IOTools.parserOutput(commas.get(i - 1).toString());
            varDefs.get(i).printInfo();
        }
        IOTools.parserOutput(semicn.toString());
        IOTools.parserOutput(ASTNodeType.VarDecl.toString());
    }

    public BType getbTypeNode() {
        return bTypeNode;
    }

    public void setbTypeNode(BType bTypeNode) {
        this.bTypeNode = bTypeNode;
    }

    public List<VarDef> getVarDefs() {
        return varDefs;
    }

    public void setVarDefs(List<VarDef> varDefs) {
        this.varDefs = varDefs;
    }

    public List<Token> getCommas() {
        return commas;
    }

    public void setCommas(List<Token> commas) {
        this.commas = commas;
    }

    public Token getSemicn() {
        return semicn;
    }

    public void setSemicn(Token semicn) {
        this.semicn = semicn;
    }
}
