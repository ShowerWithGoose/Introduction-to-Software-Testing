package src.AST.EXP;

import src.AST.Type.MulOp;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class MulExp {
    private UnaryExp unaryExp;
    private ArrayList<MulOp> mulOpList;
    private ArrayList<UnaryExp> unaryExpList;

    public MulExp() {
        this.mulOpList = new ArrayList<>();
        this.unaryExpList = new ArrayList<>();
    }

    public MulExp analyse() {
        this.unaryExp = new UnaryExp().analyse();
        syntaxList.add("<" + SyntaxType.MulExp + ">");
        while (utils.preRead(1) == WordType.MULT || utils.preRead(1) == WordType.DIV || utils.preRead(1) == WordType.MOD) {
            if (utils.preRead(1) == WordType.MULT) {
                utils.read("*");
                this.mulOpList.add(MulOp.MULT);
            } else if (utils.preRead(1) == WordType.DIV) {
                utils.read("/");
                this.mulOpList.add(MulOp.DIV);
            } else {
                utils.read("%");
                this.mulOpList.add(MulOp.MOD);
            }
            this.unaryExpList.add(new UnaryExp().analyse());
            syntaxList.add("<" + SyntaxType.MulExp + ">");
        }
        return this;
    }
}
