package fronted.parser.others;

import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.declaration.ConstDecl;
import fronted.parser.declaration.Decl;
import fronted.parser.declaration.VarDef;
import fronted.parser.function.FuncDef;
import fronted.parser.function.MainFuncDef;

import java.util.ArrayList;

public class CompUnit {
    //CompUnit â†’ {Decl} {FuncDef} MainFuncDef

    private ArrayList<Decl> declArrayList;

    private ArrayList<FuncDef> funcDefArrayList;

    private MainFuncDef mainFuncDef;

    private static final String name = "<CompUnit>\n";

    public CompUnit(ArrayList<Decl> declArrayList,
                    ArrayList<FuncDef> funcDefArrayList,
                    MainFuncDef mainFuncDef) {
        this.declArrayList = declArrayList;
        this.funcDefArrayList = funcDefArrayList;
        this.mainFuncDef = mainFuncDef;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : declArrayList) {
            sb.append(decl.toString());
        }
        for (FuncDef def : funcDefArrayList) {
            sb.append(def.toString());
        }
        sb.append(mainFuncDef.toString());
        sb.append(name);
        return sb.toString();
    }

    public static CompUnit parse(TokenList list) {
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        MainFuncDef mainFuncDef = null;
        while (CanConstDecl(list) || CanVarDecl(list)) {
            decls.add(Decl.parse(list));
        }
        //System.out.println(list.now().toString() + list.getAheadOne(1).toString() + list.getAheadOne(2).toString());
        while (CanFuncDef(list)) {
            funcDefs.add(FuncDef.parse(list));
        }
        //System.out.println("CompUnit MainFunc: " + list.now() + list.getAheadOne(1) + list.getAheadOne(2));
        mainFuncDef = MainFuncDef.parse(list);
        return new CompUnit(decls,funcDefs,mainFuncDef);
    }

    private static boolean CanConstDecl(TokenList list) {
        return list.now().getType().equals(TokenType.Type.CONSTTK);
    }

    private static boolean CanVarDecl(TokenList list) {
        return (list.now().getType().equals(TokenType.Type.INTTK)
                || list.now().getType().equals(TokenType.Type.CHARTK)) &&
                list.getAheadOne(1).getType().equals(TokenType.Type.IDENFR) &&
                (!list.hasAhead(2) || !list.getAheadOne(2).getType().equals(TokenType.Type.LPARENT));
    }

    private static boolean CanFuncDef(TokenList list) {
        return (list.now().getType().equals(TokenType.Type.INTTK)
                || list.now().getType().equals(TokenType.Type.CHARTK)
                ||list.now().getType().equals(TokenType.Type.VOIDTK)) &&
                list.getAheadOne(1).getType().equals(TokenType.Type.IDENFR) &&
                (list.hasAhead(2) && list.getAheadOne(2).getType().equals(TokenType.Type.LPARENT));
    }

    private static boolean CanMain(TokenList list) {
        return list.now().getType().equals(TokenType.Type.INTTK)
                && list.getAheadOne(1).getType().equals(TokenType.Type.MAINTK);
    }

}
