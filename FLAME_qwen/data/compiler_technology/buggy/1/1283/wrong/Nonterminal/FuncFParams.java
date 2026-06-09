package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - FuncFParams
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class FuncFParams implements Node{
    //FuncFParams â†’ FuncFParam { ',' FuncFParam }
    public List<FuncFParam> funcFParam;
    public FuncFParams(List<FuncFParam> funcFParam){
        this.funcFParam=funcFParam;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        funcFParam.get(0).output(writer);
        for(int i=1;i<funcFParam.size();i++){
            writer.write("COMMA ,\n");
            funcFParam.get(i).output(writer);
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.FuncFParams));
    }
}
