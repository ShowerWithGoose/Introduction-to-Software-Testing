package parse;

import java.util.ArrayList;

public class AddExp extends MultiExp<MulExp>{
    public AddExp(TokenList list,WrongList wrongs) {
        super(null,null,null,null);
        MulExp firstword = null;
        ArrayList<Token> operators = new ArrayList<>();
        ArrayList<MulExp> operands = new ArrayList<>();
        firstword = new MulExp(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("PLUS") ||
                token.getType().equals("MINU")) {
            operators.add(token);
            operands.add(new MulExp(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
        setall(firstword, operators, operands, "<AddExp>");
    }
}
