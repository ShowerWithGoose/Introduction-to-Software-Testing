package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

import java.util.ArrayList;

public class ConstInitVal {
    public ConstInitValType type;
    public ArrayList<ConstExp> constExpList;
    public Word stringConst;

    public ConstInitVal(){
        constExpList = new ArrayList<>();
    }

    public enum ConstInitValType{
        singleConstExp,
        constExpList,
        stringConst
    }
}
