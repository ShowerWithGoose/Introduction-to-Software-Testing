package parser_part.expression.binaryExpression;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.unaryExpression.UnaryExp;
import parser_part.expression.unaryExpression.UnaryExpParser;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class BinaryExpParser {
    private TokenList tokenList;
    private SymbolList symbolList;

    public BinaryExpParser(TokenList tokenList,SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
    }

    public MulExp parseMulExp() {
        UnaryExpParser unaryExpParser = new UnaryExpParser(tokenList,symbolList);
        UnaryExp first = unaryExpParser.parseUnaryExp();
        Token token = tokenList.getNextToken();
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        while (token != null && isMulExpOp(token)) {
            ops.add(token);
            unaryExps.add(unaryExpParser.parseUnaryExp());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        //System.out.println(mulExp.toString());
        return new MulExp(first, ops, unaryExps, "<MulExp>");
    }

    public AddExp parseAddExp() {
        MulExp first = parseMulExp();
        Token token = tokenList.getNextToken();
        ArrayList<MulExp> mulExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        while (token != null && isAddExpOp(token)) {
            ops.add(token);
            mulExps.add(parseMulExp());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        return new AddExp(first, ops, mulExps, "<AddExp>");
    }

    public RelExp parseRelExp() {
        AddExp first = parseAddExp();
        Token token = tokenList.getNextToken();
        ArrayList<Token> ops = new ArrayList<>();
        ArrayList<AddExp> addExps = new ArrayList<>();
        while (isRelExpOp(token)) {
            ops.add(token);
            addExps.add(parseAddExp());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        return new RelExp(first, ops, addExps, "<RelExp>");
    }

    public EqExp parseEqExp() {
        RelExp first = parseRelExp();
        Token token = tokenList.getNextToken();
        ArrayList<RelExp> relExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        while (isEqExpOp(token)) {
            ops.add(token);
            relExps.add(parseRelExp());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        return new EqExp(first, ops, relExps, "<EqExp>");
    }

    public LAndExp parseLAndExp() {
        EqExp first = parseEqExp();
        Token token = tokenList.getNextToken();
        ArrayList<EqExp> eqExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        while (isLAndExpOp(token)) {
            ops.add(token);
            eqExps.add(parseEqExp());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        return new LAndExp(first, ops, eqExps, "<LAndExp>");
    }

    public LOrExp parseLOrExp() {
        LAndExp first = parseLAndExp();
        Token token = tokenList.getNextToken();
        ArrayList<LAndExp> lAndExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        while (isLOrExpOp(token)) {
            ops.add(token);
            lAndExps.add(parseLAndExp());
            token = tokenList.getNextToken();
        }
        tokenList.moveBack(1);
        return new LOrExp(first, ops, lAndExps, "<LOrExp>");
    }

    public boolean isMulExpOp(Token token) {
        return token.getType() == Token.TokenType.MULT ||
                token.getType() == Token.TokenType.DIV ||
                token.getType() == Token.TokenType.MOD;
    }

    public boolean isAddExpOp(Token token) {
        return token.getType() == Token.TokenType.PLUS ||
                token.getType() == Token.TokenType.MINU;
    }

    public boolean isRelExpOp(Token token) {
        return token.getType() == Token.TokenType.LEQ ||
                token.getType() == Token.TokenType.LSS ||
                token.getType() == Token.TokenType.GRE ||
                token.getType() == Token.TokenType.GEQ;
    }

    public boolean isEqExpOp(Token token) {
        return token.getType() == Token.TokenType.EQL ||
                token.getType() == Token.TokenType.NEQ;
    }

    public boolean isLAndExpOp(Token token) {
        return token.getType() == Token.TokenType.AND;
    }

    public boolean isLOrExpOp(Token token) {
        return token.getType() == Token.TokenType.OR;
    }
}
