package frontend.parser.Function;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Exp.Exp;

import java.util.ArrayList;

public class FuncFParams {
    private FuncFParam firstFuncFParam;
    private ArrayList<Token> commas; //,可以没有
    private ArrayList<FuncFParam> funcFParams; //可以没有
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "FuncFParams";

    public FuncFParams(TokenList tokens) {
        this.firstFuncFParam = null;
        this.commas = new ArrayList<>();
        this.funcFParams = new ArrayList<>();
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        firstFuncFParam = new FuncFParam(tokens);
        errorNum += firstFuncFParam.parse();
        Token token = tokens.nextToken();
        while (token.equals(LexType.COMMA)) {
            commas.add(token);
            FuncFParam funcFParam = new FuncFParam(tokens);
            errorNum += funcFParam.parse();
            funcFParams.add(funcFParam);
            token = tokens.nextToken();
        }
        tokens.rollBack(1);
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(firstFuncFParam.toSyntaxTree());
        for (int i = 0;i < funcFParams.size();i++) {
            sb.append(commas.get(i)).append(funcFParams.get(i).toSyntaxTree());
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
