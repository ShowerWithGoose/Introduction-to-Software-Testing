package src.AST.PARAMS;

import src.AST.EXP.Exp;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class FuncRParams {
    private Exp exp;
    private ArrayList<Word> commaList;
    private ArrayList<Exp> expList;

    public FuncRParams() {
        this.commaList = new ArrayList<>();
        this.expList = new ArrayList<>();
    }

    public FuncRParams analyse() {
        this.exp = new Exp().analyse();
        while (utils.preRead(1) == WordType.COMMA) {
            this.commaList.add(utils.read(","));
            this.expList.add(new Exp().analyse());
        }
        syntaxList.add("<" + SyntaxType.FuncRParams + ">");
        return this;
    }
}
