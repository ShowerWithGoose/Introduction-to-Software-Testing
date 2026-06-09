package src.AST;

import src.AST.DECL.Decl;
import src.AST.DEF.FuncDef;
import src.AST.DEF.MainFuncDef;
import src.fronted.LexicAnalysis.WordType;
import src.fronted.SyntaxAnalysis.SyntaxType;

import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.syntaxList;
import static src.fronted.SyntaxAnalysis.SyntaxAnalysis.utils;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> declList;
    private ArrayList<FuncDef> funcDefList;
    private MainFuncDef mainFuncDef;

    public CompUnit() {
        this.declList = new ArrayList<>();
        this.funcDefList = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public CompUnit analyse() {
        //这里while条件里面都只是预读，没有实际改变cur的值。
        while (utils.preRead(1) == WordType.CONSTTK
                || (utils.isBType(utils.preRead(1))
                && utils.preRead(2) == WordType.IDENFR
                && utils.preRead(3) != WordType.LPARENT)) {
            this.declList.add(new Decl().analyse());
        }
        while (utils.preRead(1) == WordType.VOIDTK
                || (utils.isBType(utils.preRead(1))
                && utils.preRead(2) == WordType.IDENFR
                && utils.preRead(3) == WordType.LPARENT)) {
            this.funcDefList.add(new FuncDef().analyse());
        }
        //也就是说，按照文法所有的函数必须写在main函数之前。
        this.mainFuncDef = new MainFuncDef().analyse();
        syntaxList.add("<" + SyntaxType.CompUnit + ">");
        return this;
    }

}
