package frontend.parser.declaration;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.init.ConstInitVal;
import frontend.parser.init.ConstInitValParser;

public class ConstDefParser {
    private TokenIterator iterator;
    private Token ident = null;
    private Token leftBracket = null; //[
    private ConstExp constExp = null;
    private Token rightBracket = null; //]
    private Token assign = null; //=
    private ConstInitVal constInitVal = null;

    public ConstDefParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public ConstDef parseConstDef() {
        //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        ident = iterator.getNextToken();
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.LBRACK) {
            leftBracket = t1;
            ConstExpParser constExpParser = new ConstExpParser(iterator);
            constExp = constExpParser.parseConstExp();
            Token t2 = iterator.getNextToken();
            if (t2.getType() == TokenType.RBRACK) {
                rightBracket = t2;
            } else {
                //缺少右中括号
                rightBracket = null;
                iterator.ungetToken(2);
                Token t3 = iterator.getNextToken();
                Error error = new Error(t3.getLineNum(), "k");
                ErrorList.addErrorList(error);
            }
        } else {
            leftBracket = null;
            rightBracket = null;
            iterator.ungetToken(1);
        }

        Token t3 = iterator.getNextToken();
        if (t3.getType() != TokenType.ASSIGN) {
            System.out.println("parseConstDef WA!-1");
            return null;
        } else {
            assign = t3;
            ConstInitValParser constInitValParser = new ConstInitValParser(iterator);
            constInitVal = constInitValParser.parseConstInitVal();
            return new ConstDef(ident, leftBracket, constExp, rightBracket, assign, constInitVal);
        }
    }
}
