package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxUnit;

import java.util.ArrayList;

public class FuncFParams implements SyntaxUnit {
    private final String name = "<FuncFParams>";
    private FuncFParam first;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> funcFParams;

    public FuncFParams(FuncFParam first, ArrayList<Token> commas,
                      ArrayList<FuncFParam> funcFParams) {
        this.first = first;
        this.commas = commas;
        this.funcFParams = funcFParams;
    }

    @Override
    public String syntaxPrint() {
        //FuncFParams â†’ FuncFParam { ',' FuncFParam }
        StringBuilder sb = new StringBuilder();
        sb.append(first.syntaxPrint());
        if (commas != null && funcFParams != null) {
            for (int i = 0; i < commas.size(); i++) {
                sb.append(commas.get(i).syntaxPrint());
                sb.append(funcFParams.get(i).syntaxPrint());
            }
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}
