package frontend;

import java.util.ArrayList;

public class FuncFParams {
    private TokenItaretor itaretor;
    private ParserFile file;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();

    public FuncFParams(TokenItaretor itaretor, ParserFile parserFile) {
        this.itaretor = itaretor;
        this.file = parserFile;
    }

    public void getFuncFParams() {
        FuncFParam funcFParam = new FuncFParam(itaretor,file);
        funcFParam.getFuncFParam();
        funcFParams.add(funcFParam);
        Token token = itaretor.getNext();
        while(token.getString().equals(",")) {
            commas.add(token);
            file.addToken(token);
            FuncFParam funcFParam1 = new FuncFParam(itaretor,file);
            funcFParam1.getFuncFParam();
            funcFParams.add(funcFParam1);
            token = itaretor.getNext();
        }
        itaretor.getPrevious(1);
        file.addToken(new Token("<FuncFParams>"));
    }
}
