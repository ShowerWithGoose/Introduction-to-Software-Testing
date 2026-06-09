package fronted.Parser.SyntaxTree;

import fronted.Lexer.Token;

import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/10/12 15:31
 */
public class ConstDecl implements SyntaxNode{
    private final String name = "<ConstDecl>";
    private Token constTk; // 'const'
    private BType btype;
    private ConstDef necConstDef;
    private ArrayList<Token> commas; // commas
    private ArrayList<ConstDef> constDefs; // constDefs
    private Token semicn; // ';'

    public ConstDecl(Token constTk,
                     BType btype,
                     ConstDef necConstDef,
                     Token semicn) {
        this.constTk = constTk;
        this.btype = btype;
        this.necConstDef = necConstDef;
        this.semicn = semicn;
    }

    public ConstDecl(Token constTk,
                     BType btype,
                     ConstDef necConstDef,
                     ArrayList<Token> commas,
                     ArrayList<ConstDef> constDefs,
                     Token semicn) {
        this(constTk, btype, necConstDef, semicn);
        this.commas = commas;
        this.constDefs = constDefs;
    }

    @Override
    public String output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.constTk.output());
        sb.append(this.btype.output());
        sb.append(this.necConstDef.output());
        if (!this.commas.isEmpty() && !this.constDefs.isEmpty() && this.commas.size() == this.constDefs.size()) {
            int len = this.commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).output());
                sb.append(this.constDefs.get(i).output());
            }
        }
        sb.append(this.semicn.output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
