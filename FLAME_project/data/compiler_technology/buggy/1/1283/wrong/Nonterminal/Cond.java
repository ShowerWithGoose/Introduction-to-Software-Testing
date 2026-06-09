package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - Cond
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class Cond implements Node{
    //LOrExp
    public LOrExp lOrExp;
    public Cond(LOrExp lOrExp){
        this.lOrExp=lOrExp;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        lOrExp.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.Cond));
    }
}
