package frontend.parser;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.declaration.Decl;
import frontend.parser.function.FuncDef;
import frontend.parser.function.MainFuncDef;

import java.util.ArrayList;

public class CompUnit implements Node{
    private final String name = "<CompUnit>";
    private ArrayList<Decl> decls; // MAY exist
    private ArrayList<FuncDef> funcDefs; // MAY exist
    private MainFuncDef mainFuncDef;
    private TokenList tokenList;
    //必要属性结束z

    public CompUnit(TokenList tokenList) {
        this.tokenList = tokenList;
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public void parseCompUnit(){
        this.tokenList.resetLocation();//多重确保初始为0
        parseDecls();
        parseDefs();
        parseMainFuncDef();
    }

    private void parseDecls(){
        Token first;
        Token second;
        Token third;
        while (tokenList.hasNext()){
            first = tokenList.seeAfterToken(0);
            second = tokenList.seeAfterToken(1);
            third = tokenList.seeAfterToken(2);
            if (third.getType().equals(TokenType.LPARENT)) {
                return;
            }//自定义函数或者main函数
            //错误处理先忽略掉的话，假设之后一定是(const) int/char IDENFR
            Decl decl = new Decl(this.tokenList);
            decl.parseDecl();
            this.decls.add(decl);

        }
    }
    private void parseDefs(){
        Token first;
        Token second;
        Token third;
        while (tokenList.hasNext()) {
            first = tokenList.seeAfterToken(0);
            second = tokenList.seeAfterToken(1);
            third = tokenList.seeAfterToken(2);
            if (second.getType().equals(TokenType.MAINTK)){
                return;
            }//解决main函数
            //错误处理先忽略掉的话，假设之后一定是int/char IDENFR(
            FuncDef funcDef = new FuncDef(this.tokenList);
            funcDef.parseFuncDef();
            this.funcDefs.add(funcDef);

        }
    }
    private void parseMainFuncDef(){
        MainFuncDef mainFuncDef1 = new MainFuncDef(this.tokenList);
        mainFuncDef1.parseMainFuncDef();
        this.mainFuncDef = mainFuncDef1;
    }
    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        if (this.decls != null) {
            int len = this.decls.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.decls.get(i).syntaxOutput());
            }
        }
        if (this.funcDefs != null) {
            int len = this.funcDefs.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.funcDefs.get(i).syntaxOutput());
            }
        }
        sb.append(this.mainFuncDef.syntaxOutput());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
