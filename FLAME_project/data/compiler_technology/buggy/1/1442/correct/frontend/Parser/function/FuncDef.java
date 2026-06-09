package frontend.Parser.function;

import frontend.Parser.statement.block.StmtBlock;
import frontend.lexer.Errorlist;
import frontend.lexer.Errors;
import frontend.lexer.Token;
import frontend.lexer.Tokenlist;

import java.util.ArrayList;

public class FuncDef
{
    private String type = "<FuncDef>";

    private String type_inner = "<FuncFParams>";
    private FuncType funcType;
    private Token ident;

    private Token lparent;

    private Token rparent;
    private ArrayList<Token> commas;
    private ArrayList<FuncFParam> funcFParams;

    private StmtBlock stmtBlock;

    public FuncDef(FuncType funcType, Token ident, Token lparent, Token rparent, ArrayList<Token> commas, ArrayList<FuncFParam> funcFParams, StmtBlock stmtBlock)
    {
        this.funcType = funcType;
        this.ident = ident;
        this.lparent = lparent;
        this.rparent = rparent;
        this.commas = commas;
        this.funcFParams = funcFParams;
        this.stmtBlock = stmtBlock;
    }

    public FuncDef ParseFuncDef(Tokenlist tokenlist)
    {
        FuncType funcType1 = new FuncType(null);
        FuncType funcType2 = funcType1.ParseFunctype(tokenlist);
        Token token1 = tokenlist.getToken();
        tokenlist.ReadNext();
        Token lparent = null;
        Token rparent = null;
        if (tokenlist.getToken().getType() != Token.Type.LPARENT)
        {
            System.out.println("FuncDef + 缺少一个左小括号");
            tokenlist.ReadForward();
        }
        else
        {
            lparent = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        ArrayList<FuncFParam> funcFParams1 = new ArrayList<>();
        ArrayList<Token> commas = new ArrayList<>();
        if (tokenlist.getToken().getType() == Token.Type.INTTK || tokenlist.getToken().getType() == Token.Type.CHARTK)
        {
            FuncFParam funcFParam = new FuncFParam(null, null, null, null, false);
            funcFParams1.add(funcFParam.ParseFuncFParam(tokenlist));
            //tokenlist.ReadNext();
            boolean flag = false;
            while (tokenlist.getToken().getType() == Token.Type.COMMA)
            {
                commas.add(tokenlist.getToken());
                tokenlist.ReadNext();
                funcFParams1.add(funcFParam.ParseFuncFParam(tokenlist));
                //tokenlist.ReadNext();
                flag = true;
            }
//            if (flag)
//            {
//                tokenlist.ReadForward();
//            }
        }
        if (tokenlist.getToken().getType() != Token.Type.RPARENT)
        {
            Errorlist.getErrorlist().AddError(new Errors(tokenlist.getForwardToken().getLine(), 'j'));
            System.out.println("FuncDef + 缺少一个右小括号");
            tokenlist.ReadForward();
        }
        else
        {
            rparent = tokenlist.getToken();
        }
        tokenlist.ReadNext();
        StmtBlock stmtBlock1 = new StmtBlock(null, null, null);
        StmtBlock stmtBlock2 = stmtBlock1.ParseStmtBlock(tokenlist);
        return new FuncDef(funcType2, token1, lparent, rparent, commas, funcFParams1, stmtBlock2);
    }

    public String toString()
    {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.toString());
        sb.append(ident.toString());
        sb.append(lparent.toString());
        if (!funcFParams.isEmpty())
        {
            sb.append(funcFParams.get(0));
            for (int i = 0; i < commas.size(); i++)
            {
                sb.append(commas.get(i));
                sb.append(funcFParams.get(i + 1).toString());
            }
            sb.append(type_inner + "\n");
        }
        sb.append(rparent.toString());
        sb.append(stmtBlock.toString());
        sb.append(type + "\n");
        return sb.toString();
    }
}
