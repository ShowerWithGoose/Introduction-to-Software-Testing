package frontend.Symbol;

import frontend.ErrorInfo;
import frontend.Lexer.Token;
import frontend.Parser.Class.Block;
import frontend.Parser.Class.FuncType;

import java.util.ArrayList;
import java.util.Objects;

public class Operation {
    public static String getType(String form, Token.tokenType type, boolean array) {
        String typeString = "";
        String arrayString = "";
        if (type == Token.tokenType.INTTK) {
            typeString = "Int";
        } else if (type == Token.tokenType.CHARTK) {
            typeString = "Char";
        } else if (type == Token.tokenType.VOIDTK) {
            typeString = "Void";
        }
        if (array) {
            arrayString = "Array";
        }
        if (Objects.equals(form, "Const")) {
            return "Const" + typeString + arrayString;
        } else if (Objects.equals(form, "Var")) {
            return typeString + arrayString;
        } else if (Objects.equals(form, "Func")) {
            return typeString + "Func";
        }
        return null;
    }

    public static void judgeBError(int currentLineNum, ArrayList<ErrorInfo> errorList, SymbolTable symbolTable, String ident) {
        if (symbolTable.layerLookUpSymbol(ident)) {
            errorList.add(new ErrorInfo(currentLineNum, "b"));
        }
    }

    public static void judgeGError(int currentLineNum, ArrayList<ErrorInfo> errorList, Token.tokenType type, Block block) {
        boolean result = block.getResult();
        if (type != Token.tokenType.VOIDTK && !result) {
            errorList.add(new ErrorInfo(currentLineNum, "g"));
        }
    }
    public static void judgeHError(int currentLineNum, ArrayList<ErrorInfo> errorList, SymbolTable symbolTable, String ident) {
        if (symbolTable.allLookUpSymbol(ident)) {
            errorList.add(new ErrorInfo(currentLineNum, "h"));
        }
    }
}
