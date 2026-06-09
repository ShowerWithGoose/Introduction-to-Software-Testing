package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - PrimaryExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class PrimaryExp implements Node{
    //'(' Exp ')' | LVal | Number | Character
    public Exp exp;
    public LVal lVal;
    public Number number;
    public Character character;
    public PrimaryExp(Exp exp,LVal lVal,Number number,Character character){
        this.exp=exp;
        this.lVal=lVal;
        this.number=number;
        this.character=character;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        if(exp!=null){
            writer.write("LPARENT (\n");
            exp.output(writer);
            writer.write("RPARENT )\n");
        }
        else if(lVal!=null) lVal.output(writer);
        else if(number!=null) number.output(writer);
        else character.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.PrimaryExp));
    }
}
