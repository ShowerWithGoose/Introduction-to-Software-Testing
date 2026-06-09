package parse;

import parse.Token;

import java.util.ArrayList;

public class MulExp extends MultiExp<UnaryExp> {
    public MulExp(TokenList list,WrongList wrongs) {
        super(null,null,null,null);
        UnaryExp firstword = null;
        ArrayList<Token> operators = new ArrayList<Token>();
        ArrayList<UnaryExp> operands = new ArrayList<UnaryExp>();
        firstword = new UnaryExp(list,wrongs);
        Token token = list.readNextToken();
        while (token.getType().equals("MULT") ||
                token.getType().equals("DIV") ||
                token.getType().equals("MOD")) {
            operators.add(token);
            operands.add(new UnaryExp(list,wrongs));
            token = list.readNextToken();
        }
        list.unReadToken(1);
        setall(firstword, operators, operands, "<MulExp>");
    }
}
