package Parser.Func;

import Lexer.Token;
import Lexer.TokenListIterator;

/**
 * @Description:
 * @date 2024/10/13
 */
public class FuncTypeParser {
    private TokenListIterator iterator;
    private Token funcType;

    public FuncTypeParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }
    public FuncType funcTypeParse()
    {
        Token first=iterator.readNextToken();
        if(first.getValue().equals("void")||first.getValue().equals("int")||first.getValue().equals("char"))
        {
            this.funcType=first;
        }else {
            System.out.println("不是哥们functype都能错");
        }
        return new FuncType(this.funcType);
    }
}
