package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - Number
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class Number implements Node{
    //IntConst
    public Token IntConst;
    public Number(Token IntConst){
        this.IntConst=IntConst;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        writer.write(IntConst.getOutput());
        writer.write(Grammar.nodeOutput.get(Nodetype.Number));
    }
}
