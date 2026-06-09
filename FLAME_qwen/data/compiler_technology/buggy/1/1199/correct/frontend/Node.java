package frontend;

import java.io.*;
import java.util.ArrayList;

public class Node {
    private Type type;
    private Token token;
    private Node parent;
    private ArrayList<Node> children;
    private static int isNumber = 0;

    public Node(Type type) {
        this.type = type;
        this.parent = null;
        this.children = new ArrayList<>();
    }

    public Node(Token token) {
        this.type = Type.Leaf;
        this.token = token;
        this.parent = null;
        this.children = new ArrayList<>();
    }

    public void addChild(Node child) {
        children.add(child);
        child.parent = this;
    }

    public void print() throws IOException {
        try (FileWriter fileWriter = new FileWriter("parser.txt", true); // true 表示追加写入文件
             PrintWriter printWriter = new PrintWriter(fileWriter)) {
            for (Node child : children) {
                child.print();
            }
            if (type == Type.Leaf && token != null) {
                if (token.getType() == TokenType.INTCON || token.getType() == TokenType.IDENFR
                        || token.getType() == TokenType.RBRACK || token.getType() == TokenType.RPARENT || token.getType() == TokenType.CHRCON) {
                    isNumber = 1;
                } else {
                    if (!((token.getType() == TokenType.PLUS || token.getType() == TokenType.MINU) && isNumber == 1)) isNumber = 0;
                }
                if ((token.getType() == TokenType.PLUS || token.getType() == TokenType.MINU) && isNumber == 1) {
                    printWriter.printf("<%s>\n", Type.AddExp);
                    isNumber = 0;
                } else if (token.getType() == TokenType.MULT || token.getType() == TokenType.DIV || token.getType() == TokenType.MOD) {
                    printWriter.printf("<%s>\n", Type.MulExp);
                } else if (token.getType() == TokenType.LSS || token.getType() == TokenType.LEQ || token.getType() == TokenType.GEQ || token.getType() == TokenType.GRE) {
                    printWriter.printf("<%s>\n", Type.RelExp);
                } else if (token.getType() == TokenType.EQL || token.getType() == TokenType.NEQ) {
                    printWriter.printf("<%s>\n", Type.EqExp);
                } else if (token.getType() == TokenType.AND) {
                    printWriter.printf("<%s>\n", Type.LAndExp);
                } else if (token.getType() == TokenType.OR) {
                    printWriter.printf("<%s>\n", Type.LOrExp);
                }
                printWriter.printf("%s\n", token.toString());
            } else {
                printWriter.printf("<%s>\n", type);
            }
        }
    }
}
