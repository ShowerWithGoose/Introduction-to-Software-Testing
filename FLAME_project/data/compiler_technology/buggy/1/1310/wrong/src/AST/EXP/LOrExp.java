package src.AST.EXP;

import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class LOrExp {
    private LAndExp lAndExp;
    private ArrayList<LAndExp> lAndExpList;

    public LOrExp() {
        this.lAndExpList = new ArrayList<>();
    }

    public LOrExp analyse() {
        this.lAndExp = new LAndExp().analyse();
        syntaxList.add("<" + SyntaxType.LOrExp + ">");
        while (utils.preRead(1) == WordType.OR) {
            utils.read("||");
            this.lAndExpList.add(new LAndExp().analyse());
            syntaxList.add("<" + SyntaxType.LOrExp + ">");
        }
        return this;
    }
}
