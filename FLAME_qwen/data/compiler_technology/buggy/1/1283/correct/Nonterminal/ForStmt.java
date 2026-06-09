package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - ForStmt
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class ForStmt implements Node{
    //LVal '=' Exp
    public LVal lVal;
    public Exp exp;
    public ForStmt(LVal lVal,Exp exp){
        this.lVal=lVal;
        this.exp=exp;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        lVal.output(writer);
        writer.write("ASSIGN =\n");
        exp.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.ForStmt));
    }
}
