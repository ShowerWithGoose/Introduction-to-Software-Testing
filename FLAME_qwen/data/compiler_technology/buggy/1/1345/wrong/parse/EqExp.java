package parse;

import parse.Token;

import java.util.ArrayList;

public class EqExp extends MultiExp<RelExp> {
    public EqExp(TokenList list,WrongList wrongs) {
        super(null,null,null,null);
        RelExp firstword = null;
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<RelExp> operands = new ArrayList<>();
        firstword = new RelExp(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("EQL") || 
                token.getType().equals("NEQ")) { 
            operators.add(token);
            operands.add(new RelExp(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
        setall(firstword, operators, operands, "<EqExp>");
    }
}
