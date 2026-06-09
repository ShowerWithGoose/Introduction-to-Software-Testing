package parse;

import parse.Token;

import java.util.ArrayList;

public class RelExp extends MultiExp<AddExp> {
    public RelExp(TokenList list,WrongList wrongs) {
        super(null,null,null,null);
        AddExp firstword = null;
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<AddExp> operands = new ArrayList<>();
        firstword = new AddExp(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("LSS") || 
                token.getType().equals("GRE") ||
                token.getType().equals("LEQ") || 
                token.getType().equals("GEQ")) { 
            operators.add(token);
            operands.add(new AddExp(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
        setall(firstword, operators, operands, "<RelExp>");
    }
}
