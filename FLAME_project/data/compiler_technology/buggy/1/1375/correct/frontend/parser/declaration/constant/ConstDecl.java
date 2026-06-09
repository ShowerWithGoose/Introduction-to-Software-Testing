package frontend.parser.declaration.constant;

import frontend.lexer.Token;
import frontend.parser.SyntaxNode;
import frontend.parser.declaration.BType;
import frontend.parser.declaration.DeclEle;

import java.util.ArrayList;

public class ConstDecl implements DeclEle {
    public final String name = "<ConstDecl>";
    public Token constTk; // 'const'
    public BType btype;
    public ConstDef first;
    public ArrayList<Token> commas; // commas
    public ArrayList<ConstDef> constDefs; // constDefs
    public Token semicn; // ';'
    public ConstDecl(Token constTk,
                     BType btype,
                     ConstDef first,
                     Token semicn) {
        this.constTk = constTk;
        this.btype = btype;
        this.first = first;
        this.semicn = semicn;
    }
    public ConstDecl(Token constTk,
                     BType btype,
                     ConstDef first,
                     ArrayList<Token> commas,
                     ArrayList<ConstDef> constDefs,
                     Token semicn) {
        this.constTk = constTk;
        this.btype = btype;
        this.first = first;
        this.semicn = semicn;
        this.commas = commas;
        this.constDefs = constDefs;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(constTk.syntaxOutput());
        sb.append(btype.syntaxOutput());
        sb.append(first.syntaxOutput());
        if (commas != null && constDefs != null && commas.size() == constDefs.size()) {
            int len = commas.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.commas.get(i).syntaxOutput());
                sb.append(this.constDefs.get(i).syntaxOutput());
            }
        }
        sb.append(this.semicn.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
    public int my_line_num() {
        if (this.semicn != null) {
            return this.semicn.linenum;
        } else {
            if(!constDefs.isEmpty()){
                return constDefs.get(constDefs.size()-1).my_line_num();
            } else{
                return first.my_line_num();
            }
        }
    }
}
