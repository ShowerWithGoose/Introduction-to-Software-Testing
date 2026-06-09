package src.AST.PARAMS;

import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class FuncFParams {
    private FuncFParam funcFParam;
    private ArrayList<Word> commaList;
    private ArrayList<FuncFParam> funcFParamList;

    public FuncFParams() {
        this.commaList = new ArrayList<>();
        this.funcFParamList = new ArrayList<>();
    }

    public FuncFParams analyse() {
        this.funcFParam = new FuncFParam().analyse();
        while (utils.preRead(1) == WordType.COMMA) {
            this.commaList.add(utils.read(","));
            this.funcFParamList.add(new FuncFParam().analyse());
        }
        syntaxList.add("<" + SyntaxType.FuncFParams + ">");
        return this;
    }
}
