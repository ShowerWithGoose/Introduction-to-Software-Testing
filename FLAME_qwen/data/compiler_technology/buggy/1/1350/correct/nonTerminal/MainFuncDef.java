package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class MainFuncDef {
    private Token inttk;
    private Token maintk;
    private Token lparent;
    private Token rparent;
    private Block block;
    private int lineCnt;

    public MainFuncDef() {
        inttk = null;
        maintk = null;
        lparent = null;
        rparent = null;
        block = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        inttk = lexer.now();
        lexer.move();
        maintk = lexer.now();
        lexer.move();
        lparent = lexer.now();
        lexer.move();
        if (lexer.now().getType() == Token.Type.RPARENT) {
            rparent = lexer.now();
            lexer.move();
        } else {
            errors.add(lparent.getLineCnt() + " j");
        }
        block = new Block();
        block.parser(lexer, errors);
        lineCnt = inttk.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(inttk.getType().toString() + " " + inttk.getContent());
        parserResult.add(maintk.getType().toString() + " " + maintk.getContent());
        parserResult.add(lparent.getType().toString() + " " + lparent.getContent());
        parserResult.add(rparent.getType().toString() + " " + rparent.getContent());
        block.output(parserResult);
        parserResult.add("<MainFuncDef>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
