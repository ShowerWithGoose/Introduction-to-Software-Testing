package frontend.parser.function;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.Node;

import java.util.ArrayList;

public class FuncFParams implements Node {
    private final String name = "<FuncFParams>";
    private FuncFParam first;
    private ArrayList<Token> commas; // ',' MAY exist
    private ArrayList<FuncFParam> funcFParams;

    private TokenList tokenList;

    public FuncFParams(TokenList tokenList) {

        this.tokenList = tokenList;
        this.commas = new ArrayList<>();
        this.funcFParams = new ArrayList<>();
    }

    public void parseFuncFParams(){
        FuncFParam funcFParam = new FuncFParam(tokenList);
        funcFParam.parseFuncFParam();
        this.first = funcFParam;
        Token token = tokenList.seeAfterToken(0);
        while (token.getType().equals(TokenType.COMMA)){
            this.commas.add(tokenList.getNextToken());
            FuncFParam funcFParam1 = new FuncFParam(tokenList);
            funcFParam1.parseFuncFParam();
            this.funcFParams.add(funcFParam1);
            token = tokenList.seeAfterToken(0);
        }
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.first.syntaxOutput());
        if (this.commas != null && this.funcFParams != null &&
                this.commas.size() == this.funcFParams.size()) {
            int len = this.commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).syntaxOutput());
                sb.append(this.funcFParams.get(i).syntaxOutput());
            }
        }
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
