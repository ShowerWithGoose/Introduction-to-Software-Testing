package src.AST.INIT;

import src.AST.EXP.ConstExp;
import src.AST.EXP.Exp;
import src.AST.Type.InitValType;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;

public class InitVal {
    private InitValType initValType;
    private Exp exp;
    private Word lBrace;
    private ArrayList<Word> commaList;
    private ArrayList<Exp> ExpList;
    private Word rBrace;
    private Word StringConst;

    public InitVal() {
        this.commaList = new ArrayList<>();
        this.ExpList = new ArrayList<>();
    }

    public InitVal analyse() {
        if (utils.preRead(1) == WordType.STRCON) {
            this.initValType = InitValType.StringConst;
            this.StringConst = utils.read("StringConst");
        } else if (utils.preRead(1) == WordType.LBRACE) {
            this.lBrace = utils.read("{");
            if (utils.preRead(2) == WordType.COMMA) {
                this.initValType = InitValType.ExpList;
                this.ExpList.add((new Exp().analyse()));
                while (utils.preRead(1) == WordType.COMMA) {
                    this.commaList.add(utils.read(","));
                    this.ExpList.add(new Exp().analyse());
                }
            } else if (utils.preRead(1) != WordType.RBRACE
                    && utils.preRead(1) != WordType.SEMICN) {
                this.initValType = InitValType.signalExpwithR;
                this.exp = new Exp().analyse();
            } else {
                this.initValType = InitValType.Empty;
            }
            this.rBrace = utils.read("}");
            //注意错误处理
        } else {
            this.initValType = InitValType.signalExp;
            this.exp = new Exp().analyse();
        }
        syntaxList.add("<" + SyntaxType.InitVal + ">");
        return this;
    }
}
