package nonTerminal;

import frontend.Lexer;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Cond {
    private LOrExp lOrExp;
    private int lineCnt;

    public Cond() {
        lOrExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        lOrExp = new LOrExp();
        lOrExp.parser(lexer, errors);
        lineCnt = lOrExp.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        lOrExp.output(parserResult);
        parserResult.add("<Cond>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
