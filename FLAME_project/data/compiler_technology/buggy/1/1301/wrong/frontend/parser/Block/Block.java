package frontend.parser.Block;

import frontend.lexer.LexType;
import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.parser.Decl.ConstDecl;
import frontend.parser.Decl.Decl;
import frontend.parser.Decl.VarDecl;

import java.util.ArrayList;

public class Block implements StmtElement {
    private Token lbrace; //{
    private ArrayList<BlockItem> blockItems; //可以没有
    private Token rbrace; //}
    private TokenList tokens;
    private int errorNum;
    private String nonTerminalName = "Block";

    public Block(TokenList tokens) {
        this.lbrace = null;
        this.blockItems = new ArrayList<>();
        this.rbrace = null;
        this.tokens = tokens;
        this.errorNum = 0;
    }

    public int parse() { //return error num
        lbrace = tokens.nextToken();
        Token token = tokens.nextToken();
        while (!token.equals(LexType.RBRACE)) {
            //BlockItem
            if (token.equals(LexType.CONSTTK)) { //ConstDecl
                tokens.rollBack(1);
                ConstDecl constDecl = new ConstDecl(tokens);
                errorNum += constDecl.parse();
                blockItems.add(constDecl);
            } else if (token.equals(LexType.INTTK) || token.equals(LexType.CHARTK)) { //VarDecl
                tokens.rollBack(1);
                VarDecl varDecl = new VarDecl(tokens);
                errorNum += varDecl.parse();
                blockItems.add(varDecl);
            } else { //stmt
                tokens.rollBack(1);
                Stmt stmt = new Stmt(tokens);
                errorNum += stmt.parse();
                blockItems.add(stmt);
            }
            token = tokens.nextToken();
        }
        rbrace = token;
        return errorNum;
    }

    public String toSyntaxTree() {
        StringBuilder sb = new StringBuilder();
        sb.append(lbrace);
        for (BlockItem blockItem : blockItems) {
            sb.append(blockItem.toSyntaxTree());
        }
        sb.append(rbrace);
        sb.append('<').append(this.nonTerminalName).append('>').append('\n');
        return sb.toString();
    }
}
