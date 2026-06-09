package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncType {
    private Token funcType;
    private int lineCnt;

    public FuncType() {
        funcType = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer) {
        funcType = lexer.now();
        lexer.move();
        lineCnt = funcType.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        parserResult.add(funcType.getType().toString() + " " + funcType.getContent());
        parserResult.add("<FuncType>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
