package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - LOrExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class LOrExp implements Node{
    //LAndExp | LOrExp '||' LAndExp
    //LAndExp{||' LAndExp}
    public List<LAndExp> lAndExp;
    public LOrExp(List<LAndExp> lAndExp){
        this.lAndExp=lAndExp;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        lAndExp.get(0).output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.LOrExp));
        for(int i=1;i<lAndExp.size();i++){
            writer.write("OR ||\n");
            lAndExp.get(i).output(writer);
            writer.write(Grammar.nodeOutput.get(Nodetype.LOrExp));
        }

    }
}
