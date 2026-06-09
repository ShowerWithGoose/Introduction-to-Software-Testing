package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class EqExpParser {
    private TokenListIterator iterator;
    /* EqExp Attributes */
    private RelExp first;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<RelExp> operands = new ArrayList<>();

    public EqExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public EqExp parseEqExp() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        RelExpParser relExpParser = new RelExpParser(this.iterator);
        this.first = relExpParser.parseRelExp();
        Token next= this.iterator.readNextToken();
        while (next.getValue().equals("==")||next.getValue().equals("!=")) { // '!='
            this.operators.add(next);
            this.operands.add(relExpParser.parseRelExp());
            next = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        EqExp eqExp = new EqExp(this.first, this.operators, this.operands);
        return eqExp;
    }
}
