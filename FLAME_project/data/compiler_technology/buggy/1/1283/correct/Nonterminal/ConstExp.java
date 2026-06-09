package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - ConstExp
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class ConstExp implements Node{
    //AddExp
    public AddExp addExp;
    public ConstExp(AddExp addExp){
        this.addExp=addExp;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        addExp.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.ConstExp));
    }
}
