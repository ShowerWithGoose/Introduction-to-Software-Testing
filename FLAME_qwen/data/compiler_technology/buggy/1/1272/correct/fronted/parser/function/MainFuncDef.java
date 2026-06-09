package fronted.parser.function;

import fronted.ErrorList;
import fronted.lexer.Token;
import fronted.lexer.TokenList;
import fronted.lexer.TokenType;
import fronted.parser.others.Block;

public class MainFuncDef {
    //MainFuncDef â†’ 'int' 'main' '(' ')' Block // j

    private Token type;

    private Token funcName;

    private static final Token leftParent = new Token(TokenType.Type.LPARENT,"(",1);

    private static final Token rightParent = new Token(TokenType.Type.RPARENT,")",1);

    private Block block;

    private static final String name = "<MainFuncDef>\n";

    public MainFuncDef(Token type,Token funcName,Block block) {
        this.type = type;
        this.funcName = funcName;
        this.block = block;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(type.toString());
        sb.append(funcName.toString());
        sb.append(leftParent);
        sb.append(rightParent);
        sb.append(block.toString());
        sb.append(name);
        return sb.toString();
    }

    public static MainFuncDef parse(TokenList list) {
        Token type = null;
        Token FuncName = null;
        Block block = null;
        if (list.now().getType().equals(TokenType.Type.INTTK)) {
            type = list.now();
            list.next();
            if (list.now().getType().equals(TokenType.Type.MAINTK)) {
                FuncName = list.now();
                list.next();
                if (list.now().getType().equals(TokenType.Type.LPARENT)){
                    list.next();
                    if (list.now().getType().equals(TokenType.Type.RPARENT)) {
                        list.next();
                    } else {
                        ErrorList.addError(list.before().getLine(),'j');
                    }
                    block = Block.parse(list);
                } else {
                    System.err.println("Error:MainFunDef cannot find (");
                }
            } else {
                System.err.println("Error:MainFunDef cannot find main");
            }
        } else {
            System.err.println("Error:MainFunDef cannot find int");
        }
        return new MainFuncDef(type,FuncName,block);
    }
}
