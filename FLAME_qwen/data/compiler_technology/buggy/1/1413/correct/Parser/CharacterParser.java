package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/13
 */
public class CharacterParser {
    private TokenListIterator iterator;
    private Token charConst;
    public CharacterParser(TokenListIterator iterator)
    {
        this.iterator=iterator;
    }
    public CharacterClass characterClassParse()
    {
        Token first=iterator.readNextToken();
        if(first.getType().equals("CHRCON")){
            charConst=first;
        }else
        {
            charConst=null;
            System.out.println("缺少chrcon");
        }
        return new CharacterClass(charConst);
    }
}
