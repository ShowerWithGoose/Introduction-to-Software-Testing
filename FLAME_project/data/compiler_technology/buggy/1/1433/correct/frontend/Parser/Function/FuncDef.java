package frontend.Parser.Function;

import frontend.Lexer.Token;
import frontend.Parser.ASTNode;
import frontend.Parser.Declaration.Ident;
import frontend.Parser.Statement.Block;

import java.util.ArrayList;

public class FuncDef implements ASTNode {
    private FuncType funcType;
    private Ident ident;
    private Token lparentToken;
    private FuncFParam firstFuncFParam;
    private ArrayList<Token> commaTokens;
    private ArrayList<FuncFParam> funcFParams;
    private Token rparentToken;
    private Block block;

    public FuncDef(FuncType funcType,
                   Ident ident,
                   Token lparentToken,
                   FuncFParam firstFuncFParam,          // 可选
                   ArrayList<Token> commaTokens,        // 可选
                   ArrayList<FuncFParam> funcFParams,   // 可选
                   Token rparentToken,
                   Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lparentToken = lparentToken;
        this.firstFuncFParam = firstFuncFParam;
        this.commaTokens = commaTokens;
        this.funcFParams = funcFParams;
        this.rparentToken = rparentToken;
        this.block = block;
    }

    @Override
    public String printString() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.printString());
        sb.append(ident.printString());
        sb.append(lparentToken);
        if (firstFuncFParam != null) {
            sb.append(firstFuncFParam.printString());
            if (!commaTokens.isEmpty()) {
                for (Token commaToken : commaTokens) {
                    sb.append(commaToken);
                    sb.append(funcFParams.get(commaTokens.indexOf(commaToken)).printString());
                }
            }
            sb.append("<" + "FuncFParams" + ">\n");
        }
        if (rparentToken != null) {
            sb.append(rparentToken);
        }
        sb.append(block.printString());
        sb.append("<" + "FuncDef" + ">\n");
        return sb.toString();
    }
}
