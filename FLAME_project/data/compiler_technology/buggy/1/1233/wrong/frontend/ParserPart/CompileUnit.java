package frontend.ParserPart;

import frontend.Factor;
import frontend.ParserPart.decl.Decl;
import frontend.ParserPart.func.FuncDef;
import frontend.ParserPart.func.MainFuncDef;
import frontend.TokenPart.Token;
import frontend.TokenPart.TokenList;
import frontend.TokenPart.TokenType;

import java.util.ArrayList;

public class CompileUnit implements Factor {
    private String name = "<CompUnit>";
    private TokenList tokenList;
    private ArrayList<Decl> declArrayList;//可能存在
    private ArrayList<FuncDef> funcDefArrayList;//可能存在
    private MainFuncDef mainFuncDef;
    public CompileUnit(TokenList tokenList){
        this.tokenList = tokenList;
        declArrayList = new ArrayList<>();
        funcDefArrayList = new ArrayList<>();
        mainFuncDef = new MainFuncDef(tokenList);
    }
    public void parseCompileUnit(){
        parseDecl();
        parseFuncDef();
        parseMainFuncDef();
    }
    public void parseDecl(){
        //如果预读的第二个是(结束
        while (tokenList.hasNext()){
            if (tokenList.preRead(2).getType().equals(TokenType.LPARENT)){
                //有(，说明是函数了
                return;
            }
            Decl decl = new Decl(tokenList);
            decl.parseDecl();
            declArrayList.add(decl);
        }
    }
    public void parseFuncDef(){
        //如果预读的第一个是main结束
        while (tokenList.hasNext()){
            if (tokenList.preRead(1).getType().equals(TokenType.MAINTK)){
                //有main，说明是主函数了
                return;
            }
            FuncDef funcDef = new FuncDef(tokenList);
            funcDef.parseFuncDef();
            funcDefArrayList.add(funcDef);
        }
    }
    public void parseMainFuncDef(){
        mainFuncDef.parseMainFuncDef();
    }
    @Override
    public String toString(){
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < declArrayList.size(); i++) {
            sb.append(declArrayList.get(i).toString());
        }
        for (int i = 0; i < funcDefArrayList.size(); i++) {
            sb.append(funcDefArrayList.get(i).toString());
        }
        sb.append(mainFuncDef.toString());
        sb.append(name);
        sb.append("\n");
        return sb.toString();
    }
}
