package frontend.Error;

import java.io.BufferedWriter;
import java.io.IOException;

public class ErrorTool {
    private BufferedWriter writer;

    public ErrorTool(BufferedWriter writer) {
        this.writer = writer;
    }

    public void checkA(int line) throws IOException {
        writer.write(line + " a\n");
    }

    public boolean checkI(String op, int line) throws IOException {
        if (op.equals(";")) {
            return true;
        } else {
            writer.write(line + " i\n");
            return false;
        }
    }

    public boolean checkJ(String op,int line) throws IOException {
        //System.out.println(op+" "+line);
        if (op.equals(")")) {
            return true;
        } else {
            writer.write(line + " j\n");
            return false;
        }
    }

    public boolean checkK(String op,int line) throws IOException {
        if (op.equals("]")) {
            return true;
        } else {
            writer.write(line + " k\n");
            return false;
        }
    }
}
