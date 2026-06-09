package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

import java.util.ArrayList;

public class VarDecl {
    public BType bType;
    public ArrayList<VarDef> varDefList= new ArrayList<>();
    public Word semicn;
}
