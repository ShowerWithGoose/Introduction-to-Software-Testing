package frontend.AST;

import java.util.ArrayList;
import static util.File.writeFile;

public class AST {
    public static AST ast = new AST();
    private ArrayList<String> lines = new ArrayList<>();
    private ArrayList<CompUnit> compUnits;

    private AST() {
    }

    public void setCompUnits(ArrayList<CompUnit> compUnits) {
        this.compUnits = compUnits;
    }

    public void addLine(String line) {
        lines.add(line);
    }

    public void print() {
        for (CompUnit compUnit : compUnits) {
            compUnit.print();
        }
        writeFile("parser.txt", lines);
    }
}
