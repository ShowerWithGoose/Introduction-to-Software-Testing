package frontend.Parser;

import frontend.Error;
import frontend.Lexer.Token;
import frontend.Lexer.TokenListManager;
import frontend.Lexer.TokenResolved;
import frontend.Lexer.TokenType;
import frontend.Parser.declaration.Decl;
import frontend.Parser.declaration.ParserOfDecl;
import frontend.Parser.function.FuncDef;
import frontend.Parser.function.MainFuncDef;
import frontend.Parser.function.ParserOfFuncDef;
import frontend.Parser.function.ParserOfMainFuncDef;

import java.util.ArrayList;

public class ParserOfCompUnit {
    private TokenResolved resolvedList;
    private TokenListManager tokenListManager;
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;
    private ArrayList<Error> errors;

    public void initParserOfCompUnit() {
        this.tokenListManager = new TokenListManager(resolvedList);
    }

    public ParserOfCompUnit(TokenResolved resolvedList) {
        this.resolvedList = resolvedList;
        initParserOfCompUnit();
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
        this.errors = new ArrayList<>();
    }

    public CompUnit parseCompUnit(){
        parseDecls();
        parseFuncDefs();
        parseMainFuncDef();

        CompUnit compUnit = new CompUnit(this.decls, this.funcDefs, this.mainFuncDef);
        return compUnit;
    }

    public void parseDecls(){
        Token fir = this.tokenListManager.getTokenAndMove();
        Token sec = this.tokenListManager.getTokenAndMove();
        while(tokenListManager.hasNextToken()){
            Token thi = this.tokenListManager.getTokenAndMove();
            //先排除函数的可能
            if(thi.getTokenType().equals(TokenType.LPARENT)){
                tokenListManager.lookBackToken(3);
                return;
            } else {
                tokenListManager.lookBackToken(1);
            }
            boolean constDeclFlag = fir.getTokenType().equals(TokenType.CONSTTK) && (sec.getTokenType().equals(TokenType.INTTK)
                    || sec.getTokenType().equals(TokenType.CHARTK));
            boolean varDeclFlag = (fir.getTokenType().equals(TokenType.INTTK) || fir.getTokenType().equals(TokenType.CHARTK))
                    && sec.getTokenType().equals(TokenType.IDENFR);
            if(constDeclFlag || varDeclFlag){
                tokenListManager.lookBackToken(2);
                ParserOfDecl parserOfDecl = new ParserOfDecl(tokenListManager);
                Decl decl = parserOfDecl.parseDecl();
                this.decls.add(decl);
                this.errors.addAll(parserOfDecl.getErrors());
            } else{
                tokenListManager.lookBackToken(2);
                break;
            }
            fir = tokenListManager.getTokenAndMove();
            sec = tokenListManager.getTokenAndMove();
        }
    }

    public void parseFuncDefs(){
        Token fir = this.tokenListManager.getTokenAndMove();
        Token sec = this.tokenListManager.getTokenAndMove();
        while(tokenListManager.hasNextToken()){
            if((fir.getTokenType().equals(TokenType.VOIDTK) ||
            fir.getTokenType().equals(TokenType.INTTK) ||
            fir.getTokenType().equals(TokenType.CHARTK))
            && sec.getTokenType().equals(TokenType.IDENFR)){
                tokenListManager.lookBackToken(2);
                ParserOfFuncDef parserOfFuncDef = new ParserOfFuncDef(tokenListManager);
                this.funcDefs.add(parserOfFuncDef.parseFuncDef());
                this.errors.addAll(parserOfFuncDef.getErrors());
            } else {
                tokenListManager.lookBackToken(2);
                break;
            }
            fir = tokenListManager.getTokenAndMove();
            sec = tokenListManager.getTokenAndMove();
        }

    }

    public void parseMainFuncDef(){
        ParserOfMainFuncDef parserOfMainFuncDef = new ParserOfMainFuncDef(tokenListManager);
        this.mainFuncDef = parserOfMainFuncDef.parseMainFuncDef();
        this.errors.addAll(parserOfMainFuncDef.getErrors());
    }

    public ArrayList<Error> getErrors(){
        return this.errors;
    }

    public boolean hasError(){
        return !this.errors.isEmpty();
    }
}
