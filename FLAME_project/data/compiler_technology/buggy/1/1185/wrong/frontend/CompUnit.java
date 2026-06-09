package frontend;

import java.util.ArrayList;

public class CompUnit {
    private ArrayList<Token> words;
    private TokenItaretor tokenItaretor;
    private ArrayList<Decl> decls = new ArrayList<>();
    private ArrayList<FuncDef> funcDefs = new ArrayList<>();
    private MainFuncDef mainFuncDef;
    private String string = "<CompUnit>";
    private ParserFile file = new ParserFile();

    public CompUnit(ArrayList<Token> words) {
        this.words = words;
        this.tokenItaretor = new TokenItaretor(words);
        this.mainFuncDef = null;
    }

    public void parseCompUnit() {

        Token first = tokenItaretor.getNext();
        Token next = tokenItaretor.getNext();
        while (tokenItaretor.hasNext()) {
            Token third = tokenItaretor.getNext();
            if (ifDecl(first, next, third) == 2) {
                getDecls();
                first = tokenItaretor.getNext();
                next = tokenItaretor.getNext();
            } else if (ifDecl(first, next, third) == 3) {
                getFuncDefs();
                first = tokenItaretor.getNext();
                next = tokenItaretor.getNext();
            } else if (ifDecl(first, next, third) == 1) {
                getMainFuncDef();
            }
        }
        file.addToken(new Token(string));
    }

    public int ifDecl(Token first, Token next, Token third) {
        if (first.getType().equals("INTTK") && next.getType().equals("MAINTK") && third.getString().equals("(")) {
            return 1;
        } else if (first.getType().equals("CONSTTK")) return 2;
        else if ((first.getType().equals("INTTK") || first.getType().equals("CHARTK")) && next.getType().equals("IDENFR")
                && !third.getString().equals("(")) {
            return 2;
        } else {
            return 3;
        }
    }

    public void getDecls() {
        tokenItaretor.getPrevious(3); //const int a
        Decl decl = new Decl(file, tokenItaretor);
        decl.getDecl();
        decls.add(decl);
    }

    public void getFuncDefs() {
        tokenItaretor.getPrevious(3);
        FuncDef funcDef = new FuncDef(tokenItaretor, file);
        funcDef.getFuncDef();
        funcDefs.add(funcDef);
    }

    public void getMainFuncDef() {
        tokenItaretor.getPrevious(3);
        mainFuncDef = new MainFuncDef(tokenItaretor, file);
        mainFuncDef.getMainFuncDef();
    }

    public void printWords() {
        if(WrongFile.getInstance().getFlag()) {
            WrongFile.getInstance().getPrint();
        } else {
            file.printWords();
        }
    }


}
