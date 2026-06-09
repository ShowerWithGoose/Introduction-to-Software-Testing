package common;

import model.Error;
import model.SyntaxTreeNode;

import java.util.ArrayList;
import java.util.List;

public class GlobalData {
    public static boolean Errorflag = false;
    public static boolean Lexerflag = true;
    public static boolean Parserflag = true;
    public static SyntaxTreeNode CompUnitNode;
    public static List<Error> Errors = new ArrayList<>();
}
