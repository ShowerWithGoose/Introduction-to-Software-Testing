package frontend.parser.expression.unaryExp;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.primaryExp.PrimaryExp;
import frontend.parser.expression.primaryExp.PrimaryExpParser;

public class UnaryExpParser {
    private TokenIterator iterator;

    public UnaryExpParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public UnaryExp parseUnaryExp() {
        //UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
        //PrimaryExp → '(' Exp ')' | LVal | Number | Character
        Token t1 = iterator.getNextToken();
        if (t1.getType() == TokenType.PLUS || t1.getType() == TokenType.MINU
        || t1.getType() == TokenType.NOT) {
            UnaryOp unaryOp = new UnaryOp(t1);
            UnaryExpParser unaryExpParser = new UnaryExpParser(iterator);
            UnaryExp unaryExp = unaryExpParser.parseUnaryExp();
            UnaryExpOp unaryExpOp = new UnaryExpOp(unaryOp, unaryExp);
            return new UnaryExp(unaryExpOp);
        } else if (t1.getType() == TokenType.IDENFR){
            Token t2 = iterator.getNextToken();
            if (t2.getType() == TokenType.LPARENT) {
                //说明这是UnaryExpFunc
                iterator.ungetToken(2);
                UnaryExpFuncParser parser = new UnaryExpFuncParser(iterator);
                UnaryExpFunc unaryExpFunc = parser.parseUnaryExpFunc();
                return new UnaryExp(unaryExpFunc);
            } else {
                //说明这是LVal->Ident['['Exp']']
                iterator.ungetToken(2);
                PrimaryExpParser primaryExpParser = new PrimaryExpParser(iterator);
                PrimaryExp p = primaryExpParser.parsePrimaryExp();
                return new UnaryExp(p);
            }

        } else {
            //primaryExp
            iterator.ungetToken(1);
            PrimaryExpParser primaryExpParser = new PrimaryExpParser(iterator);
            PrimaryExp p = primaryExpParser.parsePrimaryExp();
            return new UnaryExp(p);
        }
    }
}
