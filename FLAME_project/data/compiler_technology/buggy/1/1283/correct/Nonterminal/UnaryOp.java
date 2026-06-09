package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - UnaryOp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class UnaryOp implements Node{
    //'+' | 'âˆ’' | '!'
    public int type;
    public UnaryOp(int type){
        this.type=type;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        if(type==1) writer.write("PLUS +\n");
        else if(type==2) writer.write("MINU -\n");
        else  writer.write("NOT !\n");
        writer.write(Grammar.nodeOutput.get(Nodetype.UnaryOp));
    }
}
