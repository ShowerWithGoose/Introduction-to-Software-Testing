package frontend.Tree;

public class ConstDef {
    private Ident ident;

    private ConstExp constExp;

    private ConstInitVal constInitVal;

    public ConstDef(Ident ident,ConstExp constExp,ConstInitVal constInitVal){
        this.ident=ident;
        this.constExp=constExp;
        this.constInitVal=constInitVal;
    }
    public ConstDef(Ident ident,ConstInitVal constInitVal){
        this.ident=ident;
        this.constInitVal=constInitVal;
    }
}
