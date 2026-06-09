package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - Block
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class Block implements Node{
    //Block â†’ '{' { BlockItem } '}'
    public List<BlockItem> blockItem;
    public Token rbToken;
    public Block(List<BlockItem> blockItem,Token rbToken){
        this.blockItem=blockItem;
        this.rbToken=rbToken;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        writer.write("LBRACE {\n");
        for(int i=0;i<blockItem.size();i++){
            blockItem.get(i).output(writer);
        }
        writer.write(rbToken.getOutput());
        writer.write(Grammar.nodeOutput.get(Nodetype.Block));
    }
}
