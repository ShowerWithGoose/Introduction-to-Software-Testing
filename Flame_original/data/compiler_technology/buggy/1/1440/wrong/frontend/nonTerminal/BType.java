package frontend.nonTerminal;

import frontend.token.token;

public class BType {
    public token type;
    public void visit(){
        type.visit();
//        myWriter.writeNonTerminal("BType");
    }
}//基本类型
