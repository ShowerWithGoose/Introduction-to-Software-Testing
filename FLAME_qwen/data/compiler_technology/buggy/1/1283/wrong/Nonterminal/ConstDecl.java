package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - ConstDecl
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class ConstDecl implements Node{
    //ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';'
    public BType bType;
    public List<ConstDef> constDef;

    public ConstDecl(BType bType, List<ConstDef> constDef){
        this.bType=bType;
        this.constDef=constDef;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        writer.write("CONSTTK const\n");
        bType.output(writer);
        constDef.get(0).output(writer);
        for(int i=1;i<constDef.size();i++){
            writer.write("COMMA ,\n");
            constDef.get(i).output(writer);
        }
        writer.write("SEMICN ;\n");
        writer.write(Grammar.nodeOutput.get(Nodetype.ConstDecl));
    }
}
