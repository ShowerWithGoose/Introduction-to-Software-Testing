package frontend.Parser.SyntaxNode;

import frontend.Lexer.Token.Token;
import java.util.ArrayList;
/*
FuncDef â†’ FuncType Ident '(' [FuncFParams] ')' Block // j
 */
public class FuncDef implements SyntaxNode {
    private final String name = "<FuncDef>";
    private FuncType funcType;
    private Token ident;
    private Token lparent;
    private FuncFParam firstFuncFParam;
    private ArrayList<FuncFParam> funcFParams;
    private ArrayList<Token> commas;
    private Token rparent;
    private Block block;

    public FuncDef(FuncType funcType, Token ident, Token lparent,
                   FuncFParam firstFuncFParam, ArrayList<FuncFParam> funcFParams,
                   ArrayList<Token> commas, Token rparent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.rparent = rparent;
        this.block = block;
        this.firstFuncFParam = firstFuncFParam;
        this.funcFParams = funcFParams;
        this.commas = commas;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType);
        sb.append(ident);
        sb.append(lparent);
        if (firstFuncFParam != null) {
            sb.append(firstFuncFParam);
            for (int i = 0; i < funcFParams.size(); i++) {
                sb.append(commas.get(i));
                sb.append(funcFParams.get(i));
            }
            sb.append("<FuncFParams>\n");
        }
        sb.append(rparent);
        sb.append(block);
        sb.append(name + "\n");
        return sb.toString();
    }
}
