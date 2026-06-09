package parse;

import java.util.ArrayList;

public class LOrExp extends MultiExp<LAndExp> {    
    public LOrExp(TokenList list,WrongList wrongs) {
        super(null,null,null,null);
        LAndExp firstword = null;
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<LAndExp> operands = new ArrayList<>();
        firstword = new LAndExp(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("OR")) { 
            operators.add(token);
            operands.add(new LAndExp(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
        setall(firstword, operators, operands, "<LOrExp>");
    }
}
