package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class RelExpParser {
    private TokenListIterator iterator;
    /* RelExp Attributes */
    private AddExp firstAddExp;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<AddExp> operands = new ArrayList<>();

    public RelExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public RelExp parseRelExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        AddExpParser addExpParser = new AddExpParser(this.iterator);
        this.firstAddExp = addExpParser.AddExpparse();
        Token next = this.iterator.readNextToken();
        while (next.getValue().equals("<")||next.getValue().equals(">")||next.getValue().equals("<=")||next.getValue().equals(">=")) { // >=
            this.operators.add(next);
            this.operands.add(addExpParser.AddExpparse());
            next= this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        RelExp relExp = new RelExp(this.firstAddExp, this.operators, this.operands);
        return relExp;
    }
}
