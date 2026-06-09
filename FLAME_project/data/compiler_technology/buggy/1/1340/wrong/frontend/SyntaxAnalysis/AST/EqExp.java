package frontend.SyntaxAnalysis.AST;

import java.util.ArrayList;

public class EqExp {
    public ArrayList<RelExp> relExpList;

    public EqExp(){
        relExpList = new ArrayList<>();
    }
}
