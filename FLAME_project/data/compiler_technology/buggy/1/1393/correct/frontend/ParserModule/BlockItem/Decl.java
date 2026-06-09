package frontend.ParserModule.BlockItem;


import ErrorsModule.ErrorCollect;
import ErrorsModule.ErrorData;
import frontend.LexerModule.Lexer;

import java.util.ArrayList;

public class Decl implements BlockItem{
    public boolean isConst;
    public Lexer bType;
    public ArrayList<VarDef> varDefs = new ArrayList<>();
    public int errorLocate;

    public Decl(boolean isConst, Lexer bType, VarDef varDef) {
        this.isConst = isConst;
        this.bType = bType;
        this.varDefs.add(varDef);
        this.errorLocate = -1;
    }

    public void addVarDef(VarDef def) {
        varDefs.add(def);
    }

    public void setErrorLocate(int errorLocate) {
        this.errorLocate = errorLocate;
    }

    public void printRes() {
        if (isConst) {
            System.out.println("CONSTTK const");
        }
        System.out.println(bType);
        int i = 0;
        for (VarDef varDef : varDefs) {
            varDef.printRes(isConst);
            if (i == varDefs.size() - 1) {
                break;
            }
            i++;
            System.out.println("COMMA ,");
        }
        System.out.println("SEMICN ;");
        if (isConst) {
            System.out.println("<ConstDecl>");
        } else {
            System.out.println("<VarDecl>");
        }
    }


    public void checkGrammarError(){
        for(VarDef def:varDefs){
            def.checkGrammarError();
        }
        if(errorLocate!=-1){
            ErrorCollect.addErrorData(new ErrorData(errorLocate,'i'));
        }
    }
}
