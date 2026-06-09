package frontend.SyntaxAnalysis.AST;

import java.util.ArrayList;

public class AddExp {
    public ArrayList<MulExp> mulExpList;
    public AddExp(){
        mulExpList = new ArrayList<>();
    }
}
