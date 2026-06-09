package frontend.parser.function;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;

import java.util.ArrayList;

public class FuncFParams implements SyntaxNode {
    public final String name="<FuncFParams>";
    public FuncFParam first;
    public ArrayList<Token> commas = null;
    public ArrayList<FuncFParam> funcFParams = null;
    public FuncFParams(FuncFParam first) {
        this.first = first;
    }
    public FuncFParams(FuncFParam first,
                       ArrayList<Token> commas,
                       ArrayList<FuncFParam> funcFParams) {
        this.first = first;
        this.commas = commas;
        this.funcFParams = funcFParams;
    }
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

    @Override
    public int my_line_num() {
        if(!this.funcFParams.isEmpty()){
            return this.funcFParams.get(this.funcFParams.size()-1).my_line_num();
        }
        else {
            return this.first.my_line_num();
        }
    }
}
