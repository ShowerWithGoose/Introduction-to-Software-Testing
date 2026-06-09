package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

import java.util.ArrayList;

public class InitVal {
    public InitValType type;
    public ArrayList<Exp> expList;
    public Word stringConst;

    public InitVal(){
        expList = new ArrayList<>();
    }

    public enum InitValType{
        singleExp,
        expList,
        stringConst
    }
}
