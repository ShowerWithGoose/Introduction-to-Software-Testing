package src.AST.EXP;

import src.AST.Type.EqOp;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class EqExp {
    private RelExp relExp;
    private ArrayList<EqOp> eqOpList;
    private ArrayList<RelExp> relExpList;

    public EqExp() {
        this.eqOpList = new ArrayList<>();
        this.relExpList = new ArrayList<>();
    }

    public EqExp analyse() {
        this.relExp = new RelExp().analyse();
        syntaxList.add("<" + SyntaxType.EqExp + ">");
        while (utils.preRead(1) == WordType.EQL
                || utils.preRead(1) == WordType.NEQ) {
            if (utils.preRead(1) == WordType.EQL) {
                utils.read("==");
                this.eqOpList.add(EqOp.EQL);
            } else {
                utils.read("!=");
                this.eqOpList.add(EqOp.NEQ);
            }
            this.relExpList.add(new RelExp().analyse());
            syntaxList.add("<" + SyntaxType.EqExp + ">");
        }
        return this;
    }
}
