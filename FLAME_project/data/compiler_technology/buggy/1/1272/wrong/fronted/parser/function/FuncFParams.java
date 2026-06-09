package fronted.parser.function;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class FuncFParams {
    // FuncFParams â†’ FuncFParam { ',' FuncFParam }

    private ArrayList<FuncFParam> params;

    private static final String name = "<FuncFParams>\n";

    private static final Token comma = new Token(TokenType.Type.COMMA,",",1);

    public FuncFParams( ArrayList<FuncFParam> params) {
        this.params = params;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(params.get(0).toString());
        int num = params.size();
        for (int i = 1; i<num;i=i+1) {
            sb.append(comma);
            sb.append(params.get(i).toString());
        }
        sb.append(name);
        return sb.toString();
    }

    public static FuncFParams parse(TokenList list) {
        ArrayList<FuncFParam> params = new ArrayList<>();
        FuncFParam funcFParam = FuncFParam.parse(list);
        params.add(funcFParam);
        while (list.now().getType().equals(TokenType.Type.COMMA)) {
            list.next();
            params.add(FuncFParam.parse(list));
        }
        return new FuncFParams(params);
    }
}
