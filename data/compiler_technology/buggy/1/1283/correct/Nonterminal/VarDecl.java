package Nonterminal;

import Grammar.Grammar;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.*;

/**
 * <p>Project: Compiler - VarDecl
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class VarDecl implements Node{
    //VarDecl â†’ BType VarDef { ',' VarDef } ';'
    public BType bType;
    public List<VarDef> varDef;
    public VarDecl(BType bType,List<VarDef> varDef){
        this.bType=bType;
        this.varDef=varDef;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        bType.output(writer);
        varDef.get(0).output(writer);
        for(int i=1;i<varDef.size();i++){
            writer.write("COMMA ,\n");
            varDef.get(i).output(writer);
        }
        writer.write("SEMICN ;\n");
        writer.write(Grammar.nodeOutput.get(Nodetype.VarDecl));
    }
}
