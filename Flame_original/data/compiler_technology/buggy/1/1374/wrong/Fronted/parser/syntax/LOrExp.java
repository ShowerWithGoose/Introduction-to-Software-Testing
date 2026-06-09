package Fronted.parser.syntax;

import Fronted.lexer.Token;

import java.util.ArrayList;

// LOrExp â†’ LAndExp | LOrExp '||' LAndExp
public class LOrExp {

    private static final String name = "<LOrExp>";

    private ArrayList<LAndExp> lAndExpList;

    private ArrayList<Token> operationList;

    public LOrExp(ArrayList<LAndExp> lAndExpList, ArrayList<Token> operationList) {
        this.lAndExpList = lAndExpList;
        this.operationList = operationList;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(lAndExpList.get(0));
        for(int i = 0; i < lAndExpList.size() -1; i++){
            out.append(name).append("\n");
            out.append(operationList.get(i));
            out.append(lAndExpList.get(i + 1));
        }
        out.append(name).append("\n");
        return out.toString();
    }
}
