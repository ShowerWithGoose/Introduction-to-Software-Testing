package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class BType {
    private Token bType;

    private int lineCnt;

    public BType() {
        bType = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        bType = lexer.now();
        lexer.move();
        lineCnt = bType.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public Token getBType() {
        return bType;
    }
}
