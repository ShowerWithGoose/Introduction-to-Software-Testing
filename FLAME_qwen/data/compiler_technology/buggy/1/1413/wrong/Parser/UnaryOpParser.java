package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/13
 */
public class UnaryOpParser {
    private TokenListIterator iterator;
    private Token op;

    public UnaryOpParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public UnaryOp unaryOpParse()
    {
        Token first=iterator.readNextToken();
        if(first.getValue().equals("+")||first.getValue().equals("-")||first.getValue().equals("!"))
        {
            this.op=first;
        }
        return new UnaryOp(op);
    }

}
