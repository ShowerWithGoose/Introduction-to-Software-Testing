package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Number {
    private Token intcon;
    private int lineCnt;

    public Number() {
        this.intcon = null;
        this.lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        intcon = lexer.now();
        lexer.move();
        lineCnt = intcon.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(intcon.getType().toString() + " " + intcon.getContent());
        parserResult.add("<Number>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
