package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - FuncDef
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class FuncDef implements Node{
    //FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block
    public FuncType funcType;
    public Token IdentToken;
    public FuncFParams funcFParams;
    public Block block;
    public FuncDef(FuncType funcType,Token IdentToken,FuncFParams funcFParams,Block block){
        this.funcType=funcType;
        this.IdentToken=IdentToken;
        this.funcFParams=funcFParams;
        this.block=block;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        funcType.output(writer);
        writer.write(IdentToken.getOutput());
        writer.write("LPARENT (\n");
        if(funcFParams!=null){
            funcFParams.output(writer);
        }
        writer.write("RPARENT )\n");
        block.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.FuncDef));
    }
}
