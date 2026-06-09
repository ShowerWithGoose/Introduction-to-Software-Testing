package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

import java.util.ArrayList;

public class Block {
    public ArrayList<BlockItem> blockItems;
    public Word lbrace;
    public Word rbrace;
    public Block(){
        blockItems = new ArrayList<>();
    }
}
