package Block;

import Tool.FileController;
import frontend.Parser;

public class ConstExpBlock {
    public AddExpBlock addExpBlock;
    public ConstExpBlock(AddExpBlock addExpBlock){
        this.addExpBlock = addExpBlock;
    }

    public void print(){
        addExpBlock.print();
        FileController.printlnParser(Parser.getBlockType(BlockType.ConstExp));
    }
}
