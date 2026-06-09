package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - BlockItem
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class BlockItem implements Node{
    //BlockItem â†’ Decl | Stmt
    public Decl decl;
    public Stmt stmt;
    public BlockItem(Decl decl,Stmt stmt){
        this.decl=decl;
        this.stmt=stmt;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        if(decl!=null) decl.output(writer);
        else stmt.output(writer);
        //writer.write(Grammar.nodeOutput.get(Nodetype.BlockItem));
    }
}
