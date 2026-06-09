package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - FuncRParams
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class FuncRParams implements Node{
    //Exp { ',' Exp }
    public List<Exp> exp;
    public FuncRParams(List<Exp> exp){
        this.exp=exp;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        exp.get(0).output(writer);
        for(int i=1;i<exp.size();i++){
            writer.write("COMMA ,\n");
            exp.get(i).output(writer);
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.FuncRParams));
    }
}
