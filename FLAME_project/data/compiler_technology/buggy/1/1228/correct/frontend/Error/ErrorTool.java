package frontend.Error;

import frontend.Symbol.Symbol;
import frontend.Symbol.SymbolTree;
import frontend.Tree.Exp;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class ErrorTool {
    private BufferedWriter writer;
    private boolean checkError = true;

    public ErrorTool(BufferedWriter writer) {
        this.writer = writer;
    }

    public void checkA(int line) throws IOException {
        if (checkError) {
            writer.write(line + " a\n");
        }
    }

    public boolean checkB(String ident, SymbolTree symbolTree, int line) throws IOException {
        boolean flag = true;
        if (symbolTree.checkB(ident)) {
            flag = false;
            if (checkError) {
                writer.write(line + " b\n");
            }
        }
        return flag;
    }

    public boolean checkC(String ident, SymbolTree symbolTree, int line) throws IOException {
        boolean flag = true;
        if (!symbolTree.checkC(ident)) {
            flag = false;
            if (checkError) {
                writer.write(line + " c\n");
            }
        }
        return flag;
    }

    public boolean checkD(String s, int num, SymbolTree symbolTree, int line) throws IOException {
        boolean flag = true;
        if (symbolTree.checkD(s) != num) {
            flag = false;
            if (checkError) {
                writer.write(line + " d\n");
            }
        }
        return flag;
    }

    public void checkE(String s, ArrayList<Exp> exps, SymbolTree symbolTree, int line) throws IOException {
        boolean flag = true;
        boolean flag1 = true;
        int i = 0;
        Symbol symbol = symbolTree.getSymbol(s);
        ArrayList<Integer> paramTypes = symbol.getParamTypes();
        if ((paramTypes == null || paramTypes.isEmpty()) && exps == null) {
            flag1 = false;
        }
        if (flag1) {
            for (Exp exp : exps) {
                int type = exp.getType();
                int type1 = paramTypes.get(i);
                i++;
                if (type == 1 || type == 3) {
                    if (type1 == 0 || type1 == 2) {
                        flag = false;
                        break;
                    } else if (type == 1 && type1 == 3) {
                        flag = false;
                        break;
                    } else if (type == 3 && type1 == 1) {
                        flag = false;
                        break;
                    }
                } else {
                    if (type1 == 1 || type1 == 3) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (!flag) {
            if (checkError) {
                writer.write(line + " e\n");
            }
        }
    }
    public void checkF(int line) throws IOException {
        if (checkError) {
            writer.write(line + " f\n");
        }
    }

    public void checkG(int line) throws IOException {
        if (checkError) {
            writer.write(line + " g\n");
        }
    }
    public void checkH(String ident, SymbolTree symbolTree, int line) throws IOException {
        if (symbolTree.checkH(ident)) {
            if (checkError) {
                writer.write(line + " h\n");
            }
        }
    }

    public boolean checkI(String op, int line) throws IOException {
        if (op.equals(";")) {
            return true;
        } else {
            if (checkError) {
                writer.write(line + " i\n");
            }
            return false;
        }
    }

    public boolean checkJ(String op, int line) throws IOException {
        if (op.equals(")")) {
            return true;
        } else {
            if (checkError) {
                writer.write(line + " j\n");
            }
            return false;
        }
    }

    public boolean checkK(String op, int line) throws IOException {
        if (op.equals("]")) {
            return true;
        } else {
            if (checkError) {
                writer.write(line + " k\n");
            }
            return false;
        }
    }

    public void checkL(String s, int num, int line) throws IOException {
        int num1 = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '/') {
                i++;
            } else if (s.charAt(i) == '%') {
                i++;
                if(s.charAt(i)=='c'||s.charAt(i)=='d') {
                    num1++;
                }
            }
        }
        if (num != num1) {
            if (checkError) {
                writer.write(line + " l\n");
            }
        }
    }
    public void checkM(boolean inFor,int line) throws IOException {
        if(!inFor){
            if (checkError) {
                writer.write(line + " m\n");
            }
        }
    }

    public void setCheckError(boolean checkError) {
        this.checkError = checkError;
    }
}
