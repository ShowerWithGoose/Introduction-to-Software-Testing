package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - LAndExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class LAndExp implements Node{
    //EqExp | LAndExp '&&' EqExp
    //EqExp{'&&' EqExp}
    public List<EqExp> eqExp;
    public LAndExp(List<EqExp> eqExp){
        this.eqExp=eqExp;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        eqExp.get(0).output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.LAndExp));
        for(int i=1;i<eqExp.size();i++) {
            writer.write("AND &&\n");
            eqExp.get(i).output(writer);
            writer.write(Grammar.nodeOutput.get(Nodetype.LAndExp));
        }
    }
}
