package fronted.parser.declaration;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

import java.util.ArrayList;

public class VarDecl {

    //VarDecl â†’ BType VarDef { ',' VarDef } ';' // i

    private BType bType;


    private static final Token Comma = new Token(TokenType.Type.COMMA,",",1);

    private ArrayList<VarDef> defList;

    private static final Token Semicn = new Token(TokenType.Type.SEMICN,";",1);

    private static final String name = "<VarDecl>\n";



    public VarDecl(BType type,ArrayList<VarDef> defList) {
        this.bType = type;
        this.defList = defList;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(bType.toString());
        stringBuilder.append(defList.get(0).toString());
        int num = defList.size();
        for (int i = 1;i<num;i=i+1) {
            stringBuilder.append(Comma);
            stringBuilder.append(defList.get(i).toString());
        }
        stringBuilder.append(Semicn);
        stringBuilder.append(name);
        return stringBuilder.toString();
    }

    public static VarDecl parse(TokenList list) {
        BType type = BType.parse(list);
        ArrayList<VarDef> arrayList = new ArrayList<>();
        VarDef varDef = VarDef.parse(list);
        arrayList.add(varDef);
        while (list.now().getType().equals(TokenType.Type.COMMA)) {
            list.next();
            VarDef def = VarDef.parse(list);
            arrayList.add(def);
        }
        if (!list.now().getType().equals(TokenType.Type.SEMICN)) {
            ErrorList.addError(list.before().getLine(),'i');
        } else {
            list.next();
        }
        return new VarDecl(type,arrayList);
    }
}
