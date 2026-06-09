package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class FuncFParamsParser {
    private TokenIterator iterator;
    private FuncFParam first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();

    public FuncFParamsParser(TokenIterator iterator) {
        this.iterator = iterator;
    }

    public FuncFParams parseFuncFParams() {
        // FuncFParams â†’ FuncFParam { ',' FuncFParam }
        FuncFParamParser funcFParamParser = new FuncFParamParser(iterator);
        first = funcFParamParser.parseFuncFParam();
        Token t1 = iterator.getNextToken();
        while (t1.getType() == TokenType.COMMA) {
            commas.add(t1);
            FuncFParamParser funcFParamParser1 = new FuncFParamParser(iterator);
            funcFParams.add(funcFParamParser1.parseFuncFParam());
            t1 = iterator.getNextToken();
        }

        iterator.ungetToken(1);
        return new FuncFParams(first, commas, funcFParams);
    }
}
