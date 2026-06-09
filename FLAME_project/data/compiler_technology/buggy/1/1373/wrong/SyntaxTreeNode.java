import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class SyntaxTreeNode {
    private SyntaxType type;
    private Token value;
    private ArrayList<SyntaxTreeNode> children;

    public SyntaxTreeNode(SyntaxType type, Token value) {
        this.type = type;
        this.value = value;
        this.children = new ArrayList<>();
    }

    public SyntaxType getType() {
        return this.type;
    }

    public void addChild(SyntaxTreeNode child) {
        children.add(child);
    }

    public void output(FileWriter writer) throws IOException {
        if (type.equals(SyntaxType.Token)) {
            writer.write(value.getType() + " " + value.getValue() + "\n");
        } else {
            if (type.toString().equals("MulExp")
                || type.toString().equals("AddExp")
                || type.toString().equals("RelExp")
                || type.toString().equals("EqExp")
                || type.toString().equals("LAndExp")
                || type.toString().equals("LOrExp")) {

                if (children.size() != 1) {
                    for (int i = 0;i < children.size();i++) {
                        children.get(i).output(writer);
                        if (!children.get(i).getType().equals(SyntaxType.Token) && i!=children.size() - 1) {
                            writer.write("<" + type.toString() + ">\n");
                        }
                    }
                    writer.write("<" + type.toString() + ">\n");
                } else {
                    children.get(0).output(writer);
                    writer.write("<" + type.toString() + ">\n");
                }

            } else {
                for (SyntaxTreeNode value : children) {
                    value.output(writer);
                }
                if (!type.toString().equals("BlockItem")
                        && !type.toString().equals("Decl")
                        && !type.toString().equals("BType")) {

                    writer.write("<" + type.toString() + ">\n");

                }
            }
        }
    }
}
