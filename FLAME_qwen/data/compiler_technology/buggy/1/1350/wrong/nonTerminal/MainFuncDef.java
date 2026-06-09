package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
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

    public void parser(Lexer lexer) {
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
            rparent = new Token(Token.Type.RPARENT, ")", lparent.getLineCnt());
            rparent.setIsCorrect(false);
        }
        block = new Block();
        block.parser(lexer);
        lineCnt = inttk.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public void analyze(SymbolTable symbolTable) {
        if (!rparent.getIsCorrect()) {
            symbolTable.addError(rparent.getLineCnt() + " j");
        }
        symbolTable.setReturnFuncType(SymbolTable.ReturnFuncType.INT);
        block.analyzeMain(symbolTable);
    }
}
