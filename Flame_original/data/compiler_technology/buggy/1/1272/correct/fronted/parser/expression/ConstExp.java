package fronted.parser.expression;

import fronted.lexer.TokenList;

public class ConstExp {
    //ConstExp → AddExp 注：使用的 Ident 必须是常量

    private AddExp addExp;

    private static final String name = "<ConstExp>\n";

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    @Override
    public String toString(){
        return this.addExp.toString() + name;
    }

    public static ConstExp parse(TokenList list){
        return new ConstExp(AddExp.parse(list));
    }
}
