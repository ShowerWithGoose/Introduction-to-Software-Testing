package parse;

import java.util.ArrayList;

public class LAndExp extends MultiExp<EqExp> {
    public LAndExp(TokenList list,WrongList wrongs) {
        super(null,null,null,null);
        EqExp firstword = null;
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<EqExp> operands = new ArrayList<>();
        firstword = new EqExp(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("AND")) { 
            operators.add(token);
            operands.add(new EqExp(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
        setall(firstword, operators, operands, "<LAndExp>");
    }
}
