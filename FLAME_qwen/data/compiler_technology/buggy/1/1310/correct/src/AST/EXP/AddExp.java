package src.AST.EXP;

import src.AST.Type.AddOp;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class AddExp {
    private MulExp mulExp;
    private ArrayList<AddOp> addOpList;
    private ArrayList<MulExp> mulExpList;

    public AddExp() {
        this.addOpList = new ArrayList<>();
        this.mulExpList = new ArrayList<>();
    }

    public AddExp analyse() {
        this.mulExp = new MulExp().analyse();
        syntaxList.add("<" + SyntaxType.AddExp + ">");
        //其实通过分析可以发现，AddExp本质上就是多个MulExp组成的，简单画一下就是一个AddExp对应一个MulExp
        while (utils.preRead(1) == WordType.PLUS || utils.preRead(1) == WordType.MINU) {
            if (utils.preRead(1) == WordType.PLUS) {
                utils.read("+");
                this.addOpList.add(AddOp.PLUS);
            } else {
                utils.read("-");
                this.addOpList.add(AddOp.MINU);
            }
            //暂时不考虑报错
            this.mulExpList.add(new MulExp().analyse());
            syntaxList.add("<" + SyntaxType.AddExp + ">");
        }
        return this;
    }
}
