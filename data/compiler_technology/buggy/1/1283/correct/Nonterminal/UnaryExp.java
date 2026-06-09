package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - UnaryExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class UnaryExp implements Node{
    //PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public PrimaryExp primaryExp;
    public Token IdentToken;
    public FuncRParams funcRParams;
    public UnaryOp unaryOp;
    public UnaryExp unaryExp;
    public UnaryExp(PrimaryExp primaryExp,Token IdentToken,FuncRParams funcRParams,UnaryOp unaryOp,UnaryExp unaryExp){
        this.funcRParams=funcRParams;
        this.primaryExp=primaryExp;
        this.unaryExp=unaryExp;
        this.unaryOp=unaryOp;
        this.IdentToken=IdentToken;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        if(primaryExp!=null) primaryExp.output(writer);
        else if(IdentToken!=null){
            writer.write(IdentToken.getOutput());
            writer.write("LPARENT (\n");
            if(funcRParams!=null) funcRParams.output(writer);
            writer.write("RPARENT )\n");
        }
        else if(unaryOp!=null){
            unaryOp.output(writer);
            unaryExp.output(writer);
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.UnaryExp));
    }
}
