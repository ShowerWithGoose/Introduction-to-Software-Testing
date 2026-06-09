package src.AST.DECL;

import src.AST.BType;
import src.AST.DEF.VarDef;
import src.ErrorHandle.Errortype;
import src.fronted.LexicAnalysis.Word;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import java.util.ArrayList;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

public class VarDecl {
    private BType btype;
    private VarDef varDef;
    private ArrayList<Word> commaList;
    private ArrayList<VarDef> varDefList;
    private Word semicolon;

    public VarDecl() {
        this.commaList = new ArrayList<>();
        this.varDefList = new ArrayList<>();
    }

    public VarDecl analyse() {
        this.btype = new BType().analyse();
        this.varDef = new VarDef().analyse();
        while (utils.preRead(1) == WordType.COMMA) {
            this.commaList.add(utils.read(","));
            this.varDefList.add(new VarDef().analyse());
        }
        this.semicolon = utils.tryReadnext(1, ";", Errortype.i);
        //注意报错
        syntaxList.add("<" + SyntaxType.VarDecl + ">");
        return this;
    }

}
