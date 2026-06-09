package fronted.parser.declaration;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.Node;

import java.util.ArrayList;

public class ConstDecl{

    //ConstDecl â†’ 'const' BType ConstDef { ',' ConstDef } ';' // i
    private BType bType;

    private static final Token Const = new Token(TokenType.Type.CONSTTK,"const",1);

    private static final Token Comma = new Token(TokenType.Type.COMMA,",",1);
    private ArrayList<ConstDef> defList;

    private static final Token Semicn = new Token(TokenType.Type.SEMICN,";",1);

    private static final String name = "<ConstDecl>\n";

    public ConstDecl(BType bType, ArrayList<ConstDef> defList) {
        this.bType = bType;
        this.defList = defList;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(Const.toString());
        sb.append(bType.toString());
        sb.append(defList.get(0).toString());
        int number = defList.size();
        for (int i = 1;i < number; i = i+1) {
            sb.append(Comma.toString());
            sb.append(defList.get(i).toString());
        }
        sb.append(Semicn.toString());
        sb.append(name);
        return sb.toString();
    }

    public static ConstDecl parse(TokenList list) {
        Token token = list.now();
        if (!token.getType().equals(TokenType.Type.CONSTTK)) {
            System.err.println("Error: ConstDecl cannot find const");
        } else {
            list.next();
            BType type = BType.parse(list);
            ArrayList<ConstDef> arrayList = new ArrayList<>();
            ConstDef constDef = ConstDef.parse(list);
            arrayList.add(constDef);
            while (list.now().getType().equals(TokenType.Type.COMMA)) {
                list.next();
                ConstDef def = ConstDef.parse(list);
                arrayList.add(def);
            }
            if (!list.now().getType().equals(TokenType.Type.SEMICN)) {
                ErrorList.addError(list.before().getLine(),'i');
            } else {
                list.next();
            }
            return new ConstDecl(type,arrayList);
        }

        return null;
    }
}
