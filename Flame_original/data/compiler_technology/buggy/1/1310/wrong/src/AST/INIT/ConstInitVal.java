package src.AST.INIT;

import src.AST.EXP.ConstExp;
import src.AST.Type.InitValType;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class ConstInitVal {
    private InitValType initValType;
    private ConstExp constExp;
    private Word lBrace;
    private ArrayList<Word> commaList;
    private ArrayList<ConstExp> ConstExpList;
    private Word rBrace;
    private Word StringConst;

    public ConstInitVal() {
        this.commaList = new ArrayList<>();
        this.ConstExpList = new ArrayList<>();
    }

    public ConstInitVal analyse() {
        if (utils.preRead(1) == WordType.STRCON) {
            this.initValType = InitValType.StringConst;
            this.StringConst = utils.read("StringConst");
        } else if (utils.preRead(1) == WordType.LBRACE) {
            this.lBrace = utils.read("{");
            if (utils.preRead(2) == WordType.COMMA) {
                this.initValType = InitValType.ExpList;
                this.ConstExpList.add(new ConstExp().analyse());
                //这里忘了第一个应该是ConstExp而不是逗号
                while (utils.preRead(1) == WordType.COMMA) {
                    this.commaList.add(utils.read(","));
                    this.ConstExpList.add(new ConstExp().analyse());
                }
            } else if (utils.preRead(1) != WordType.RBRACE
                    && utils.preRead(1) != WordType.SEMICN) {
                this.initValType = InitValType.signalExpwithR;
                this.constExp = new ConstExp().analyse();
            } else {
                this.initValType = InitValType.Empty;
            }
            this.rBrace = utils.read("}");
        } else {
            this.initValType = InitValType.signalExp;
            this.constExp = new ConstExp().analyse();
        }
        syntaxList.add("<" + SyntaxType.ConstInitVal + ">");
        return this;
    }
}
