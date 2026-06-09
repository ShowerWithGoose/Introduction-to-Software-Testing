package frontend;

import java.io.BufferedWriter;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;

public class GramNode {
    GramType gramType;
    ArrayList<GramNode> children = new ArrayList<>();
    GramNode parent;
    Token leaf = null;

    public GramNode() {
        ;
    }

    public void p() {
        for (GramNode child : children) {
            child.p();
        }
        if (leaf != null) {
            System.out.println(leaf.type + " " + leaf.word);
        } else {
            if(gramType!=GramType.BType&&gramType!=GramType.Decl&&gramType!=GramType.BlockItem)
                System.out.println("<"+gramType+">");
        }
    }

    public void w(BufferedWriter writeOut) throws IOException {
        for (GramNode child : children) {
            child.w(writeOut);
        }
        if (leaf != null) {
            //System.out.println(leaf.type + " " + leaf.word);
            writeOut.write(leaf.type + " " + leaf.word);
            writeOut.newLine();
            writeOut.flush();
        } else {
            if(gramType!=GramType.BType&&gramType!=GramType.Decl&&gramType!=GramType.BlockItem) {
                //System.out.println("<" + gramType + ">");
                writeOut.write("<" + gramType + ">");
                writeOut.newLine();
                writeOut.flush();
            }
        }
    }

    @Override
    public String toString() {
        String str = "";
        if (leaf == null) {
            for (GramNode child : children) {
                str += child.toString();
            }
            str += "<" + gramType + ">" + "\n";
        } else {
            str += leaf.toString();
        }
        return str;
    }
}