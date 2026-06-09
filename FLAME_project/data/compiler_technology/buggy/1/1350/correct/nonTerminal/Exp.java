package nonTerminal;

import frontend.Lexer;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Exp {
    private AddExp addExp;
    private int lineCnt;

    public Exp() {
        addExp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        addExp = new AddExp();
        addExp.parser(lexer, errors);
        lineCnt = addExp.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        addExp.output(parserResult);
        parserResult.add("<Exp>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
