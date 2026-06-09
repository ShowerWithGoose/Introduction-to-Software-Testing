package fronted.parser.expression;

import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class AddExp {
    //AddExp → MulExp | AddExp ('+' | '−') MulExp

    //AddExp → MulExp { ('+' | '−') MulExp }

    private ArrayList<Token> AddSubList;

    private ArrayList<MulExp> mulExpArrayList;

    //@ensure AddSubList.length = mulExpArrayList.length - 1

    private static final String name = "<AddExp>\n";

    public AddExp(ArrayList<Token> arrayList,ArrayList<MulExp> exps) {
        this.AddSubList = arrayList;
        this.mulExpArrayList = exps;
    }

    @Override
    public String toString(){
        int num = mulExpArrayList.size();
        StringBuilder sb = new StringBuilder();
        sb.append(mulExpArrayList.get(0).toString());
        sb.append(name);
        for (int i = 1;i < num;i = i + 1) {
            sb.append(AddSubList.get(i-1).toString());
            sb.append(mulExpArrayList.get(i).toString());
            sb.append(name);
        }
        return sb.toString();
    }

    public static AddExp parse(TokenList list){
        ArrayList<Token> AddSubList = new ArrayList<>();
        ArrayList<MulExp> mulExpArrayList = new ArrayList<>();
        MulExp exp = MulExp.parse(list);
        mulExpArrayList.add(exp);
        while (list.now().getType().equals(TokenType.Type.PLUS) ||
                list.now().getType().equals(TokenType.Type.MINU)) {
            AddSubList.add(list.now());
            list.next();
            mulExpArrayList.add(MulExp.parse(list));
        }
        return new AddExp(AddSubList,mulExpArrayList);
    }
}
