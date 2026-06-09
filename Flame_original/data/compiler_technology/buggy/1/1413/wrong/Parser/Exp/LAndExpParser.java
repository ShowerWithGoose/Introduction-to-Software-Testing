package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class LAndExpParser {
    private TokenListIterator iterator;
    /* LAndExp Attributes */
    private EqExp firstEqExp = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<EqExp> operands = new ArrayList<>();

    public LAndExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public LAndExp lAndExpParse() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        EqExpParser eqExpParser = new EqExpParser(this.iterator);
        this.firstEqExp  = eqExpParser.parseEqExp();
        Token token = this.iterator.readNextToken();
        while (token.getType().equals("AND")) { // '&&'
            this.operators.add(token);
            this.operands.add(eqExpParser.parseEqExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        return new LAndExp(this.firstEqExp , this.operators, this.operands);
    }
}
