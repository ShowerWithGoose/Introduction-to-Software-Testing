package nonTerminal;

import frontend.Lexer;
import frontend.Token;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class FuncFParams {
    private FuncFParam funcFParam;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> funcFParams;
    private int lineCnt;

    public FuncFParams() {
        funcFParam = null;
        commas = new ArrayList<>();
        funcFParams = new ArrayList<>();
        lineCnt = 0;
    }

    public void parser(Lexer lexer, ArrayList<String> errors) {
        funcFParam = new FuncFParam();
        funcFParam.parser(lexer, errors);
        while (lexer.now().getType() == Token.Type.COMMA) {
            Token comma = lexer.now();
            commas.add(comma);
            lexer.move();
            FuncFParam temptFuncFParam = new FuncFParam();
            temptFuncFParam.parser(lexer, errors);
            funcFParams.add(temptFuncFParam);
        }
        lineCnt = funcFParam.getLineCnt();
    }

    public void output(ArrayList<String> parserResult) {
        funcFParam.output(parserResult);
        for (int i = 0; i < funcFParams.size(); i++) {
            parserResult.add(commas.get(i).getType().toString() + " " + commas.get(i).getContent());
            funcFParams.get(i).output(parserResult);
        }
        parserResult.add("<FuncFParams>");
    }

    public int getLineCnt() {
        return lineCnt;
    }
}