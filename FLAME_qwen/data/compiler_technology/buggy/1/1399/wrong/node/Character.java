/********************************************************************************
 * @FileName     : Character.java
 * @Author       :
 * @Description  : 字符
 * @Notice       : Character -> CharConst
 * @Time         : 2024-10-14 10:51
 * @Version      : 0.0
 ********************************************************************************/

package node;

import type.ASTNodeType;
import utils.IOTools;

public class Character implements ASTNode {
    private CharConst charConst;

    public Character(CharConst charConst) {
        this.charConst = charConst;
    }

    @Override
    public void printInfo() {
        this.charConst.printInfo();
        IOTools.parserOutput(ASTNodeType.Character.toString());
    }

    public CharConst getCharConst() {
        return charConst;
    }

    public void setCharConst(CharConst charConst) {
        this.charConst = charConst;
    }
}
