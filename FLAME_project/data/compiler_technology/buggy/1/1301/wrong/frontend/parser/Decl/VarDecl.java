package frontend.parser.Decl;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Block.BlockItem;

import java.util.ArrayList;

public class VarDecl implements Decl, BlockItem {
    private Token bType;
    private VarDef firstVarDef;
    private ArrayList<Token> commas; //,可以没有
    private ArrayList<VarDef> varDefs; //可以没有
    private Token semicn; //;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "VarDecl";

    public VarDecl(TokenList tokens) {
        this.bType = null;
        this.firstVarDef = null;
        this.commas = new ArrayList<>();
        this.varDefs = new ArrayList<>();
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        bType = tokens.nextToken();
        firstVarDef = new VarDef(tokens);
        errorNum += firstVarDef.parse();
        Token first = tokens.nextToken();
        while (first.equals(LexType.COMMA)) {
            commas.add(first);
            VarDef varDef = new VarDef(tokens);
            errorNum += varDef.parse();
            varDefs.add(varDef);
            first = tokens.nextToken();
        }
        if (!first.equals(LexType.SEMICN)) { //error i
            ErrorHandling.printError(tokens.preNonTerminalLineNum(),'i');
            errorNum++;
            tokens.rollBack(1);
        } else {
            semicn = first;
        }
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(bType).append(firstVarDef.toSyntaxTree());
        for (int i = 0;i < varDefs.size();i++) {
            sb.append(commas.get(i)).append(varDefs.get(i).toSyntaxTree());
        }
        if (semicn != null) {
            sb.append(semicn);
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
