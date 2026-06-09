package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnit(MainFuncDef mainFuncDef, ArrayList<FuncDef> funcDefs, ArrayList<Decl> decls) {
        this.mainFuncDef = mainFuncDef;
        this.funcDefs = funcDefs;
        this.decls = decls;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < this.decls.size(); i++) {
            sb.append(this.decls.get(i).print());
        }
        for (int i = 0; i < this.funcDefs.size(); i++) {
            sb.append(this.funcDefs.get(i).print());
        }

        sb.append(mainFuncDef.print());
        sb.append("<CompUnit>\n");
        return sb.toString();
    }

    public static CompUnit parse(TokenIterator iterator) {
        Token first = iterator.next();
        Token second = iterator.next();
        Token third = iterator.next();
        ArrayList<Decl> decls = new ArrayList<>();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        while (iterator.hasNext() && !((first.getType().equals(Token.Type.INTTK) && second.getType().equals(Token.Type.MAINTK) && third.getType().equals(Token.Type.LPARENT)))) {
            if (first.getType().equals(Token.Type.CONSTTK)) {
                iterator.back(3);
                Decl decl = Decl.parse(iterator);
                decls.add(decl);
            }
            else if (first.getType().equals(Token.Type.VOIDTK)) {
                iterator.back(3);
                FuncDef funcDef = FuncDef.parse(iterator);
                funcDefs.add(funcDef);
            }
            else if ((first.getType().equals(Token.Type.INTTK) || first.getType().equals(Token.Type.CHARTK)) && third.getType().equals(Token.Type.LPARENT)) {
                iterator.back(3);
                FuncDef funcDef = FuncDef.parse(iterator);
                funcDefs.add(funcDef);
            }
            else {
                iterator.back(3);
                Decl decl = Decl.parse(iterator);
                decls.add(decl);
            }
            first = iterator.next();
            second = iterator.next();
            third = iterator.next();

        }
        iterator.back(3);
        MainFuncDef mainFuncDef = MainFuncDef.parse(iterator);
        return new CompUnit(mainFuncDef, funcDefs, decls);
    }
}
