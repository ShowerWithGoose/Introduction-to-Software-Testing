package frontend.Parser.declaration;

import frontend.Parser.declaration.constant.ConstDecl;
import frontend.Parser.declaration.variable.VarDecl;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

public class Decl
{
    private String type = "<Decl>";
    private DeclAll decl;

    public Decl(DeclAll decl)
    {
        this.decl = decl;
    }

    public Decl ParseDecl(Tokenlist tokenlist)
    {
        DeclAll declAll;
        if (tokenlist.getToken().getType() == Token.Type.CONSTTK)
        {
            ConstDecl constDecl = new ConstDecl(null, null, null, null, null);
            declAll = constDecl.ParseConstDecl(tokenlist);
        }
        else
        {
            VarDecl varDecl = new VarDecl(null, null, null, null);
            declAll = varDecl.ParseVarDecl(tokenlist);
        }
        return new Decl(declAll);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(decl.toString());
        //sb.append(type + "\n");
        return sb.toString();
    }
}
