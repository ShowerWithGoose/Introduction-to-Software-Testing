package frontend.parser.declaration;

import frontend.error.Error;
import frontend.error.ErrorList;
import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;
import frontend.parser.init.InitVal;
import frontend.parser.init.InitValParser;

public class VarDefParser {
    private TokenIterator iterator;
    private Token ident = null;
    private Token leftBracket = null; //[
    private ConstExp constExp = null;
    private Token rightBracket = null; //]
    private Token assign = null; //=
    private InitVal initVal = null;

    public VarDefParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public VarDef parseVarDef() {
        // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
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
                iterator.ungetToken(2);
                Token t3 = iterator.getNextToken();
                Error error = new Error(t3.getLineNum(), "k");
                ErrorList.addErrorList(error);
            }
        } else {
            //没有中括号
            iterator.ungetToken(1);
        }
        Token t4 = iterator.getNextToken();
        if (t4.getType() != TokenType.ASSIGN) {
            //not init
            iterator.ungetToken(1);
            return new VarDef(ident, leftBracket, constExp, rightBracket);
        } else {
            assign = t4;
            InitValParser initValParser = new InitValParser(iterator);
            initVal = initValParser.parseInitVal();
            return new VarDef(ident, leftBracket, constExp, rightBracket, assign, initVal);
        }
    }
}
