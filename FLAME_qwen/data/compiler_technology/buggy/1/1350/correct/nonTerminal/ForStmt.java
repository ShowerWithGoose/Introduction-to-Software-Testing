package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ForStmt {
    private LVal lVal;
    private Token assign;
    private Exp exp;
    private int lineCnt;

    public ForStmt() {
        lVal = null;
        assign = null;
        exp = null;
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        lVal = new LVal();
        lVal.parser(lexer, errors);
        assign = lexer.now();
        lexer.move();
        exp = new Exp();
        exp.parser(lexer, errors);
        lineCnt = lVal.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        lVal.output(parserResult);
        parserResult.add(assign.getType().toString() + " " + assign.getContent());
        exp.output(parserResult);
        parserResult.add("<ForStmt>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
