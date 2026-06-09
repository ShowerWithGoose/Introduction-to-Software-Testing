package frontend;

import java.util.ArrayList;

public class Decl {
    private ArrayList<ConstDecl> constDecls;
    private ArrayList<VarDecl> varDecls;
    private ParserFile file;
    private TokenItaretor itaretor;
    public Decl(ParserFile file, TokenItaretor itaretor) {
        this.constDecls = new ArrayList<>();
        this.varDecls = new ArrayList<>();
        this.file = file;
        this.itaretor = itaretor;
    }

    public void getDecl() {
        Token first = itaretor.getNext();
        if(first.getType().equals("CONSTTK")) {
            ConstDecl constDecl = new ConstDecl(itaretor, first, file);
            constDecl.getConstDecl();
            constDecls.add(constDecl);
        } else {
            VarDecl varDecl = new VarDecl(itaretor,first,file);
            varDecl.getVarDecl();
            varDecls.add(varDecl);
        }
    }


}
