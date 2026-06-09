package frontend.nonTerminal;

import frontend.nonTerminal.Stmt.Stmt;

public class BlockItem {
    public Decl decl;
    public Stmt stmt;

    public void visit(){
        if(decl!=null)decl.visit();
        else stmt.visit();
//        myWriter.writeNonTerminal("BlockItem");
    }
}//语句块项
