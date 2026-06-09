/********************************************************************************
 * @FileName     : ConstDecl.java
 * @Author       :
 * @Description  : 常量声明
 * @Notice       : ConstDecl -> 'const' BType ConstDef { ',' ConstDef } ';'
 * @Time         : 2024-10-14 10:50
 * @Version      : 0.0
 ********************************************************************************/

package node;

import frontend.Token;
import type.ASTNodeType;
import utils.IOTools;


import java.util.List;


public class ConstDecl implements ASTNode {
    private Token constTk;
    private BType bType;
    private List<ConstDef> constDefList;
    private List<Token> commaList;
    private Token semicnTk;

    public ConstDecl(Token constTk, BType bType, List<ConstDef> constDefList, List<Token> commaList, Token semicnTk) {
        this.constTk = constTk;
        this.bType = bType;
        this.constDefList = constDefList;
        this.commaList = commaList;
        this.semicnTk = semicnTk;
    }

    @Override
    public void printInfo() {
        IOTools.parserOutput(constTk.toString());
        bType.printInfo();
        constDefList.get(0).printInfo();
        for (int i = 1; i < constDefList.size(); i++) {
            IOTools.parserOutput(commaList.get(i - 1).toString());
            constDefList.get(i).printInfo();
        }
        IOTools.parserOutput(semicnTk.toString());
        IOTools.parserOutput(ASTNodeType.ConstDecl.toString());
    }
}
