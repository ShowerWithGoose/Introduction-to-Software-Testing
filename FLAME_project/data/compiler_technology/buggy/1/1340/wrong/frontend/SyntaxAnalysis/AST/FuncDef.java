package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

public class FuncDef {
    public FuncType funcType;
    public Word ident;
    public Word lparent;
    public Word rparent;
    public boolean haveFuncFParams;
    public FuncFParams funcFParams;
    public Block block;
    public void analyse() {

    }
}
