package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class AddExpParser {
    private TokenListIterator iterator;
    /* AddExp Attributes */
    private MulExp first = null;
    private ArrayList<Token> operators = new ArrayList<>(); // '+' '-'
    private ArrayList<MulExp> mulExpArrayList = new ArrayList<>();
    public AddExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public AddExp AddExpparse() {
        this.mulExpArrayList = new ArrayList<>();
        this.operators = new ArrayList<>();
        MulExpParser mulExpParser = new MulExpParser(this.iterator);
        this.first = mulExpParser.mulExpParse();
        Token token = this.iterator.readNextToken();
        while (token.getType().equals("PLUS") || token.getType().equals("MINU")) {
            this.operators.add(token);
            this.mulExpArrayList.add(mulExpParser.mulExpParse());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        AddExp addExp = new AddExp(this.first, this.operators, this.mulExpArrayList);
        return addExp;
    }
}
