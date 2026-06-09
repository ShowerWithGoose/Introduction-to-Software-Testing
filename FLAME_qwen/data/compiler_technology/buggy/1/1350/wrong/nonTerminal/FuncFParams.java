package nonTerminal;

import frontend.Lexer;
import frontend.SymbolTable;
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

    public void parser(Lexer lexer) {
        funcFParam = new FuncFParam();
        funcFParam.parser(lexer);
        while (lexer.now().getType() == Token.Type.COMMA) {
            Token comma = lexer.now();
            commas.add(comma);
            lexer.move();
            FuncFParam temptFuncFParam = new FuncFParam();
            temptFuncFParam.parser(lexer);
            funcFParams.add(temptFuncFParam);
        }
        lineCnt = funcFParam.getLineCnt();
    }

    public int getLineCnt() {
        return lineCnt;
    }

    public FuncFParam getFuncFParam() {
        return funcFParam;
    }

    public ArrayList<FuncFParam> getFuncFParams() {
        return funcFParams;
    }

    public void analyze(SymbolTable symbolTable) {
        funcFParam.analyze(symbolTable);
        for (FuncFParam param : funcFParams) {
            param.analyze(symbolTable);
        }
    }
}