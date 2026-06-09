package src.AST.EXP;

import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class LAndExp {
    private EqExp eqExp;
    private ArrayList<EqExp> eqExpList;

    public LAndExp() {
        this.eqExpList = new ArrayList<>();
    }

    public LAndExp analyse() {
        this.eqExp = new EqExp().analyse();
        syntaxList.add("<" + SyntaxType.LAndExp + ">");
        while (utils.preRead(1) == WordType.AND) {
            utils.read("&&");
            this.eqExpList.add(new EqExp().analyse());
            syntaxList.add("<" + SyntaxType.LAndExp + ">");
        }
        return this;
    }
}
