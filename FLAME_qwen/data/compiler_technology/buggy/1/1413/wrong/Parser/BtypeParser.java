package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

/**
* @Description:
* @date 2024/10/11
*/
public class BtypeParser {
    private Token bType;
    private TokenListIterator iterator;
    public BtypeParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public BType BtypeParse()
    {
        Token first=iterator.readNextToken();
        if(first.getValue().equals("int"))
        {
            bType=first;
            return new BType(first);
        } else if (first.getValue().equals("char")) {
            bType=first;
            return new BType(first);
        }else {
            System.out.println("bType怎么可能会有第三者");
            return null;
        }
    }
}
