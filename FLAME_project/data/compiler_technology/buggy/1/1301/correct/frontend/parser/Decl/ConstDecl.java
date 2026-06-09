package frontend.parser.Decl;

import error.ErrorHandling;
import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Block.BlockItem;

import java.util.ArrayList;

public class ConstDecl implements Decl, BlockItem {
    private Token constToken;
    private Token bType;
    private ConstDef firstConstDef;
    private ArrayList<Token> commas; //,可以没有
    private ArrayList<ConstDef> constDefs; //可以没有
    private Token semicn; //;
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "ConstDecl";

    public ConstDecl(TokenList tokens) {
        this.constToken = null;
        this.bType = null;
        this.firstConstDef = null;
        this.commas = new ArrayList<>();
        this.constDefs = new ArrayList<>();
        this.semicn = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        constToken = tokens.nextToken();
        bType = tokens.nextToken();
        firstConstDef = new ConstDef(tokens);
        errorNum += firstConstDef.parse();
        Token first = tokens.nextToken();
        while (first.equals(LexType.COMMA)) {
            commas.add(first);
            ConstDef constDef = new ConstDef(tokens);
            errorNum += constDef.parse();
            constDefs.add(constDef);
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
        sb.append(constToken).append(bType).append(firstConstDef.toSyntaxTree());
        for (int i = 0;i < constDefs.size();i++) {
            sb.append(commas.get(i)).append(constDefs.get(i).toSyntaxTree());
        }
        if (semicn != null) {
            sb.append(semicn);
        }
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
