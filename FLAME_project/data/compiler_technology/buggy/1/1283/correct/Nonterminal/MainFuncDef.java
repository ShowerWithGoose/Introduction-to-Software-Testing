package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - MainFuncDef
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class MainFuncDef implements Node{
    //MainFuncDef â†’ 'int' 'main' '(' ')' Block
    public Block block;
    public MainFuncDef(Block block){
        this.block=block;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        writer.write("INTTK int\n");
        writer.write("MAINTK main\n");
        writer.write("LPARENT (\n");
        writer.write("RPARENT )\n");
        block.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.MainFuncDef));
    }
}
