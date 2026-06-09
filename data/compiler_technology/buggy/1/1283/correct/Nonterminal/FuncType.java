package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - FuncType
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class FuncType implements Node{
    public int type;//1:void,2:int,3:char
    public FuncType(int type){
        this.type=type;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        if(type==1) writer.write("VOIDTK void\n");
        else if(type==2) writer.write("INTTK int\n");
        else writer.write("CHARTK char\n");
        writer.write(Grammar.nodeOutput.get(Nodetype.FuncType));
    }
}
