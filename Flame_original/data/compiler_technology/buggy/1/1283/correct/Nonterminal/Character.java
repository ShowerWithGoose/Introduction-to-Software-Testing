package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - Character
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class Character implements Node{
    //CharConst
    public Token CharConst;
    public Character(Token CharConst){
        this.CharConst=CharConst;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        writer.write(CharConst.getOutput());
        writer.write(Grammar.nodeOutput.get(Nodetype.Character));
    }
}
