package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - Exp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class Exp implements Node{
    //AddExp
    public AddExp addExp;
    public Exp(AddExp addExp){
        this.addExp=addExp;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        addExp.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.Exp));
    }
}
