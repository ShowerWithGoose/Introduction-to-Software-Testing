package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - BType
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class BType implements Node{
    //BType â†’ 'int' | 'char'
    public boolean isInt;
    public BType(boolean isInt){
        this.isInt=isInt;
    }
    public void output(BufferedWriter writer) throws IOException {
        if(isInt) writer.write("INTTK int\n");
        else writer.write("CHARTK char\n");
        //writer.write(Grammar.nodeOutput.get(Nodetype.BType));
    }
}
