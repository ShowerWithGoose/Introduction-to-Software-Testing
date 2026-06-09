package fronted.parser.function;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.others.Block;

public class FuncDef {
    //FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block // j

    private FuncType type;

    private Token ident;

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    private FuncFParams funcFParams;

    private Block block;

    private static final String name = "<FuncDef>\n";

    public FuncDef(FuncType type,Token ident,FuncFParams funcFParams,Block block) {
        this.type = type;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.block = block;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(type.toString());
        sb.append(ident.toString());
        sb.append(leftParent);
        if (funcFParams != null) {
            sb.append(funcFParams.toString());
        }
        sb.append(rightParent);
        sb.append(block.toString());
        sb.append(name);
        return sb.toString();
    }

    public static FuncDef parse(TokenList list) {
        FuncType type = null;
        Token ident = null;
        FuncFParams funcFParams = null;
        Block block = null;
        type = FuncType.parse(list);
        //System.out.println(list.now().toString()+"|||");
        if (list.now().getType().equals(TokenType.Type.IDENFR)) {
            ident = list.now();
            list.next();
        } else {
            System.err.println("Error:FuncDef cannot find ident");
            return null;
        }
        if (list.now().getType().equals(TokenType.Type.LPARENT)) {
            list.next();
        } else {
            System.err.println("Error:FuncDef cannot find (");
            return null;
        }
        if (list.now().getType().equals(TokenType.Type.RPARENT)) {
            list.next();
        } else if (list.now().getType().equals(TokenType.Type.LBRACE)) {
            ErrorList.addError(list.before().getLine(),'j');
        } else {
            funcFParams = FuncFParams.parse(list);
            if (list.now().getType().equals(TokenType.Type.RPARENT)) {
                list.next();
            } else {
                ErrorList.addError(list.before().getLine(),'j');
            }
        }

        block = Block.parse(list);
        return new FuncDef(type,ident,funcFParams,block);
    }
}
