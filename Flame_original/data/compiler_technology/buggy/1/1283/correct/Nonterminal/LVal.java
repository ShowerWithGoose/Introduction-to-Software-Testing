package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - LVal
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class LVal implements Node{
    //Ident ['[' Exp ']']
    public Token IdentToken;
    public Exp exp;
    public LVal(Token IdentToken,Exp exp){
        this.IdentToken=IdentToken;
        this.exp=exp;
    }
    public void output(BufferedWriter writer) throws IOException {
        writer.write(IdentToken.getOutput());
        if(exp!=null){
            writer.write("LBRACK [\n");
            exp.output(writer);
            writer.write("RBRACK ]\n");
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.LVal));
    }
}
