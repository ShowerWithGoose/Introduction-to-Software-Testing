package parser_part.function;

import lexer_part.Token;
import parser_part.Ident;
import parser_part.Node;
import parser_part.block.Block;
import parser_part.function.funcType.FuncType;

import java.util.ArrayList;

public class FuncDef implements Node {
    private FuncType funcType;
    private Ident ident;
    private Token leftParent;
    private FuncFParams funcFParams;
    private Token rightParent;
    private Block block;

    public FuncDef(FuncType funcType, Ident ident, Token leftParent, FuncFParams funcFParams, Token rightParent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.leftParent = leftParent;
        this.funcFParams = funcFParams;
        this.rightParent = rightParent;
        this.block = block;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(funcType.toString() + ident.toString());
        sb.append(leftParent);
        if (funcFParams != null) {
            sb.append(funcFParams);
        }
        sb.append(rightParent).append(block).append("<FuncDef>\n");
        return sb.toString();
    }
}
