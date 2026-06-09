package saver;

import lexical_analysis.Token;
import Error.MyError;
import java.util.ArrayList;

public class Saver {
    public static ArrayList<Token> tokenList = new ArrayList<>();
    public static boolean ifError;
    public static ArrayList<MyError> ErrorList = new ArrayList<>();
}
