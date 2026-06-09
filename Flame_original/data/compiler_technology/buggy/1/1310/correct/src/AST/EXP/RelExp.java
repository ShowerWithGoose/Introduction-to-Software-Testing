package src.AST.EXP;

import src.AST.Type.RelOp;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class RelExp {
    private AddExp addExp;
    private ArrayList<RelOp> relOpList;
    private ArrayList<AddExp> addExpList;

    public RelExp() {
        this.relOpList = new ArrayList<>();
        this.addExpList = new ArrayList<>();
    }

    public RelExp analyse() {
        this.addExp = new AddExp().analyse();
        syntaxList.add("<" + SyntaxType.RelExp + ">");
        while (utils.isRelExp()) {
            if (utils.preRead(1) == WordType.LSS) {
                utils.read("<");
                this.relOpList.add(RelOp.LSS);
            } else if (utils.preRead(1) == WordType.GRE) {
                utils.read(">");
                this.relOpList.add(RelOp.GRE);
            } else if (utils.preRead(1) == WordType.LEQ) {
                utils.read("<=");
                this.relOpList.add(RelOp.LEQ);
            } else {
                utils.read(">=");
                this.relOpList.add(RelOp.GEQ);
            }
            this.addExpList.add(new AddExp().analyse());
            syntaxList.add("<" + SyntaxType.RelExp + ">");
        }
        return this;
    }
}
