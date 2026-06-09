package Parser.Decl;

import Parser.Syntax;

import java.util.ArrayList;

public class ConstDecl implements Syntax {
    private String name;
    private ArrayList<Syntax> syntaxes = new ArrayList<>();
    private int size;

    public ConstDecl(ArrayList<Syntax> syntaxes, int size) {
        this.name = getName();
        this.syntaxes = syntaxes;
        this.size = size;
    }

    @Override
    public String getName() {
        return "<ConstDecl>";
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(syntaxes.get(0).syntaxOutput());//CONSTTK
        sb.append(syntaxes.get(1).syntaxOutput());//BType
        sb.append(syntaxes.get(2).syntaxOutput());//第一个ConstDef
        for (int i = 3; i < size; i++) {
            sb.append(syntaxes.get(i).syntaxOutput());
        }
        sb.append(name + "\n");
        return sb.toString();
    }
}
