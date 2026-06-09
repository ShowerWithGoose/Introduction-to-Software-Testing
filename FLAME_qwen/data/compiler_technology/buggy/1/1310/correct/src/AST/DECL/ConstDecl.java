package src.AST.DECL;

import src.AST.BType;
import src.AST.DEF.ConstDef;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

import java.util.ArrayList;

public class ConstDecl {
    private boolean signalDef;
    private Word wordConst;
    private BType bType;
    private ConstDef constDef;
    private ArrayList<Word> commaList;
    private ArrayList<ConstDef> constDefList;
    private Word semicolon;

    public ConstDecl() {
        this.signalDef = true;
        this.commaList = new ArrayList<>();
        this.constDefList = new ArrayList<>();
    }

    public ConstDecl analyse() {
        this.wordConst = utils.read("const");
        this.bType = new BType().analyse();
        this.constDef = new ConstDef().analyse();
        while (utils.preRead(1) == WordType.COMMA) {
            this.commaList.add(utils.read(","));
            this.constDefList.add(new ConstDef().analyse());
        }
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        //注意报错
        syntaxList.add("<" + SyntaxType.ConstDecl + ">");
        return this;
    }
}
