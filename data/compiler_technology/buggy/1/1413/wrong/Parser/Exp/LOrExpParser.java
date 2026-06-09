package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/13
 */
public class LOrExpParser {
    private TokenListIterator iterator;
    /* LOrExp Attributes */
    private LAndExp firstLAndExp = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<LAndExp> operands = new ArrayList<>();

    public LOrExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public LOrExp lOrExpParse() {
        this.operands = new ArrayList<>();
        this.operators = new ArrayList<>();
        LAndExpParser landExpParser = new LAndExpParser(this.iterator);
        this.firstLAndExp = landExpParser.lAndExpParse();
        Token token = this.iterator.readNextToken();
        while (token.getType().equals("OR")) { // '||'
            this.operators.add(token);
            this.operands.add(landExpParser.lAndExpParse());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        return new LOrExp(this.firstLAndExp, this.operators, this.operands);
    }

}
