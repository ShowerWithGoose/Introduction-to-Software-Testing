package frontend.parser.function.functype;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class FuncTypeParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* FuncType Attributes */
    public FuncTypeEle funcTypeEle = null;

    public FuncTypeParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public FuncType parseFuncType() {
        Token token = this.iterator.readNextToken();
        if (token.type.equals(TokenType.VOIDTK)) { // 'void'
            this.funcTypeEle = new FuncTypeVoid(token);
        } else if (token.type.equals(TokenType.INTTK)) { // 'int'
            this.funcTypeEle = new FuncTypeInt(token);
        }else if(token.type.equals(TokenType.CHARTK)){ // 'char'
            this.funcTypeEle = new FuncTypeChar(token);
        }
        FuncType funcType = new FuncType(this.funcTypeEle);
        return funcType;
    }
}
