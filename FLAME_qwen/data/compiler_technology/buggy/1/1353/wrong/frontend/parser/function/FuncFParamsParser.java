package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

/**
 * FuncFParams 函数形参表类
 * <FuncFParams> -> <FuncFParam> { ',' <FuncFParam> }
 */
public class FuncFParamsParser {
    private TokenListIterator iterator;
    /* FunfFParams Attributes */
    private FuncFParam first = null;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();

    public FuncFParamsParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public FuncFParams parseFuncFParams() {
        this.commas = new ArrayList<>();
        this.funcFParams = new ArrayList<>();
        FuncFParamParser funcFParamParser = new FuncFParamParser(this.iterator);
        this.first = funcFParamParser.parseFuncFParam();
        Token token = this.iterator.next();
        while (token.getTokenType().equals(TokenType.COMMA)) {
            this.commas.add(token);
            this.funcFParams.add(funcFParamParser.parseFuncFParam());
            token = this.iterator.next();
        }
        this.iterator.unRead(1);
        return new FuncFParams(this.first, this.commas, this.funcFParams);
    }
}
