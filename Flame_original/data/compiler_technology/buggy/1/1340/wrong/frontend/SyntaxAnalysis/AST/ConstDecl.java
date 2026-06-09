package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

import java.util.ArrayList;

public class ConstDecl {
    public Word const0;
    public BType bType;
    public ArrayList<ConstDef> constDefList;
    public Word semicn;
    public ConstDecl(){
        constDefList = new ArrayList<>();
    }
}
