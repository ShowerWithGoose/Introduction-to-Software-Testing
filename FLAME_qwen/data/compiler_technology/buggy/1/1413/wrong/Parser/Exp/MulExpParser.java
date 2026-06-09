package Parser.Exp;

import Lexer.Token;
import Lexer.TokenListIterator;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/12
 */
public class MulExpParser {
    private TokenListIterator iterator;
    /* MulExp Attributes */
    private UnaryExp first = null;
    private ArrayList<Token> operators = new ArrayList<>();
    private ArrayList<UnaryExp> unaryExpArrayList = new ArrayList<>();

    public MulExpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public MulExp mulExpParse() {
        this.operators = new ArrayList<>();
        this.unaryExpArrayList = new ArrayList<>();
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.iterator);
        this.first = unaryExpParser.unaryExpParse();
        Token token = this.iterator.readNextToken();
        while (token.getType().equals("MULT") ||
                token.getType().equals("DIV") ||
                token.getType().equals("MOD")) {
            /* token -> * / % */
            this.operators.add(token);
            this.unaryExpArrayList.add(unaryExpParser.unaryExpParse());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        MulExp mulExp = new MulExp(this.first, this.operators, this.unaryExpArrayList);
        return mulExp;
    }
}
