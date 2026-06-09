package nonTerminal;

import frontend.Lexer;

import java.util.ArrayList;

public class ConstExp {
    private AddExp addExp;
    private int lineCnt;

    public ConstExp() {
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
        parserResult.add("<ConstExp>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}
