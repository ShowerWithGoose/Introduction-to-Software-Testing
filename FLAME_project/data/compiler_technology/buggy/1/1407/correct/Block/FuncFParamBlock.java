package Block;

import Token.Token;
import Tool.FileController;
import frontend.Parser;

import java.util.List;

public class FuncFParamBlock {
    public BTypeBlock bTypeBlock;
    public Token ident;
    public Token leftBrackets;
    public Token rightBrackets;
    public FuncFParamBlock(BTypeBlock bTypeBlock,Token ident,Token leftBrackets,Token rightBrackets){
        this.bTypeBlock = bTypeBlock;
        this.ident = ident;
        this.leftBrackets = leftBrackets;
        this.rightBrackets = rightBrackets;
    }

    public void print(){
        bTypeBlock.print();
        FileController.printlnParser(ident.toString());
        if(leftBrackets!=null){
            FileController.printlnParser(leftBrackets.toString());
            FileController.printlnParser(rightBrackets.toString());
        }
        FileController.printlnParser(Parser.getBlockType(BlockType.FuncFParam));
    }
}
