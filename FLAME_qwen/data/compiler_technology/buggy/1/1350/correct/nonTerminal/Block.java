package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Block {
    private Token lbrace;
    private ArrayList<BlockItem> blockItems;
    private Token rbrace;
    private int lineCnt;

    public Block() {
        lbrace = null;
        blockItems = new ArrayList<>();
        rbrace = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        lbrace = lexer.now();
        lexer.move();
        while (lexer.now().getType() != Token.Type.RBRACE) {
            BlockItem blockItem = new BlockItem();
            blockItem.parser(lexer, errors);
            blockItems.add(blockItem);
        }
        rbrace = lexer.now();
        lexer.move();
        lineCnt = lbrace.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(lbrace.getType().toString() + " " + lbrace.getContent());
        for (BlockItem blockItem : blockItems) {
            blockItem.output(parserResult);
        }
        parserResult.add(rbrace.getType().toString() + " " + rbrace.getContent());
        parserResult.add("<Block>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}