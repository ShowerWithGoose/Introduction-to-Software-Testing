package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

public class VarDef {
    public Word ident;
    public Word lbrack;
    public Word rbrack;
    public boolean haveInitVal;
    public Word assign;
    public ConstExp constExp;
    public InitVal initVal;

}
