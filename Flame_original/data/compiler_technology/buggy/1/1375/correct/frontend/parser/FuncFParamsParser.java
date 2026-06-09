package frontend.parser;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.function.FuncFParam;
import frontend.parser.function.FuncFParamParser;
import frontend.parser.function.FuncFParams;

import java.util.ArrayList;

public class FuncFParamsParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* FunfFParams Attributes */
    public FuncFParam first = null;
    public ArrayList<Token> commas = new ArrayList<>();
    public ArrayList<FuncFParam> funcFParams = new ArrayList<>();

    public FuncFParamsParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }

    public FuncFParams parseFuncFParams() {
        this.commas = new ArrayList<>();
        this.funcFParams = new ArrayList<>();
        FuncFParamParser funcFParamParser = new FuncFParamParser(this.iterator,this.error_tokens);
        this.first = funcFParamParser.parseFuncFParam();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.COMMA)) {
            this.commas.add(token);
            FuncFParamParser funcFParamParser1 = new FuncFParamParser(this.iterator,this.error_tokens);
            this.funcFParams.add(funcFParamParser1.parseFuncFParam());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        return new FuncFParams(this.first, this.commas, this.funcFParams);
    }
}
