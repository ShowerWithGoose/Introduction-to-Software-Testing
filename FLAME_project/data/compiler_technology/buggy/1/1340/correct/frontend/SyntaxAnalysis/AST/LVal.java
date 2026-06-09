package frontend.SyntaxAnalysis.AST;

import frontend.LexicalAnalysis.Word;

public class LVal {
    public Word ident;
    public Exp exp;
    public boolean haveExp;
}
