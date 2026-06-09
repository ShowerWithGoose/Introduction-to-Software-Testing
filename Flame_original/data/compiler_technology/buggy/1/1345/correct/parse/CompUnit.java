package parse;

import java.util.ArrayList;

public class CompUnit {
    private final String name = "<CompUnit>";
    private ArrayList<Decl> decls = null; 
    private ArrayList<FuncDef> funcDefs = null; 
    private MainFuncDef mainFuncDef;

    public String getName() {
        return name;
    }

    public ArrayList<Decl> getDecls() {
        return decls;
    }

    public void setDecls(ArrayList<Decl> decls) {
        this.decls = decls;
    }

    public ArrayList<FuncDef> getFuncDefs() {
        return funcDefs;
    }

    public void setFuncDefs(ArrayList<FuncDef> funcDefs) {
        this.funcDefs = funcDefs;
    }

    public MainFuncDef getMainFuncDef() {
        return mainFuncDef;
    }

    public void setMainFuncDef(MainFuncDef mainFuncDef) {
        this.mainFuncDef = mainFuncDef;
    }


    public CompUnit(TokenList list,WrongList wrongs) {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();

        Token x = list.readNextToken();
        Token y = list.readNextToken();
        while (list.hasNext()) {
            Token z = list.readNextToken();
            if (z.getType().equals("LPARENT")) {
                list.unReadToken(3);
                break;
            }
            else {
                list.unReadToken(1);
            }
            if ((x.getType().equals("CONSTTK") && (y.getType().equals("INTTK") || y.getType().equals("CHARTK"))) ||
                    ((x.getType().equals("INTTK") || x.getType().equals("CHARTK")) &&
                            y.getType().equals("IDENFR"))) {
                list.unReadToken(2);
                this.decls.add(new Decl(list,wrongs));
            } else {
                list.unReadToken(2);
                break;
            }
            x = list.readNextToken();
            y = list.readNextToken();
        }

        x = list.readNextToken();
        y = list.readNextToken();

        while (list.hasNext()) {
            if ((x.getType().equals("INTTK") ||
                    x.getType().equals("VOIDTK") ||
                    x.getType().equals("CHARTK")) &&
                    y.getType().equals("IDENFR")) {
                list.unReadToken(2);
                this.funcDefs.add(new FuncDef(list,wrongs));
            } else {
                list.unReadToken(2);
                break;
            }
            x = list.readNextToken();
            y = list.readNextToken();

        }

        this.mainFuncDef = new MainFuncDef(list,wrongs);
    }

    public String printout() {
        StringBuilder sb = new StringBuilder();
        if (this.decls != null && decls.size() != 0) {
            int len = this.decls.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.decls.get(i).printout());
            }
        }
        if (this.funcDefs != null && funcDefs.size() != 0) {
            int len = this.funcDefs.size();
            for (int i = 0; i < len; i++) {
                sb.append(this.funcDefs.get(i).printout());
            }
        }
        sb.append(this.mainFuncDef.printout());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
