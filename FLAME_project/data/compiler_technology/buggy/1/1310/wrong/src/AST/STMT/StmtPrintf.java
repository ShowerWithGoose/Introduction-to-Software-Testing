package src.AST.STMT;

import src.AST.EXP.Exp;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class StmtPrintf {
    private Word printf;
    private Word lParent;
    private Word StringConst;
    private boolean haveExp;
    private ArrayList<Word> commaList;
    private ArrayList<Exp> expList;
    private Word rParent;
    private Word semicolon;

    public StmtPrintf() {
        this.haveExp = false;
        this.commaList = new ArrayList<>();
        this.expList = new ArrayList<>();
    }

    public StmtPrintf analyse() {
        this.printf = utils.read("printf");
        this.lParent = utils.read("(");
        this.StringConst = utils.read("StringConst");
        if (utils.preRead(1) == WordType.COMMA) {
            this.haveExp = true;
            while (utils.preRead(1) == WordType.COMMA) {
                this.commaList.add(utils.read(","));
                this.expList.add(new Exp().analyse());
            }
        }
        this.rParent = utils.tryReadnext(1, ")", Errortype.j);
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        return this;
    }
}
