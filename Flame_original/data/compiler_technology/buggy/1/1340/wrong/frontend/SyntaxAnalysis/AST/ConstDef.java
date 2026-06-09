package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

public class ConstDef {
    public Word ident;
    public boolean haveConstExp;
    public Word lbrack;
    public ConstExp constExp;
    public Word rbrack;
    public Word assign;
    public ConstInitVal constInitVal;

}
