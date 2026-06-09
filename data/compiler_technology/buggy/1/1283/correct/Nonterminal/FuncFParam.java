package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - FuncFParam
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class FuncFParam implements Node{
    //FuncFParam → BType Ident ['[' ']']
    public BType bType;
    public Token IdentToken;
    public boolean hasNext;//有无后续的[]
    public FuncFParam(BType bType,Token IdentToken,boolean hasNext){
        this.bType=bType;
        this.hasNext=hasNext;
        this.IdentToken=IdentToken;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        bType.output(writer);
        writer.write(IdentToken.getOutput());
        if(hasNext){
            writer.write("LBRACK [\n");
            writer.write("RBRACK ]\n");
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.FuncFParam));
    }
}
