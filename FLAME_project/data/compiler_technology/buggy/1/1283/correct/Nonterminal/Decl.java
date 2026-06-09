package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - Decl
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class Decl implements Node{
    //Decl â†’ ConstDecl | VarDecl
    public ConstDecl constDecl;
    public VarDecl varDecl;
    public Decl(ConstDecl constDecl,VarDecl varDecl){
        this.constDecl=constDecl;
        this.varDecl=varDecl;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException{
        if(constDecl!=null) constDecl.output(writer);
        else varDecl.output(writer);
        //writer.write(Grammar.nodeOutput.get(Nodetype.Decl));
    }
}
