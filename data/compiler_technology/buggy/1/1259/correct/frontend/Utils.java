package frontend;

import frontend.Lexer.Token;
import frontend.Lexer.TokenType;
import frontend.Parser.GrammarTreeNode;
import frontend.Parser.Nonterminal;
import frontend.Parser.NonterminalType;
import frontend.Symbol.MyType;
import frontend.Symbol.SymbolType;

public class Utils
{
    public static boolean IsNonDigit(char c){
        return Character.isLetter(c) || c == '_';
    }

    public static boolean IsTokenTypeIn(Token token, TokenType ... tokenTypes){
        for(TokenType tokenType : tokenTypes){
            if(token.getType().equals(tokenType)){
                return true;
            }
        }
        return false;
    }

    public static boolean IsNonterminalTypeIn(Nonterminal nonterminal, NonterminalType ... nonterminalTypes){
        for(NonterminalType nonterminalType : nonterminalTypes){
            if(nonterminal.getType().equals(nonterminalType)){
                return true;
            }
        }
        return false;
    }

    public static MyType SymbolTypeArray2SingleVarMyType(SymbolType symbolType){
        switch (symbolType){
            case IntArray, ConstIntArray -> {
                return MyType.Int;
            }
            case CharArray, ConstCharArray -> {
                return MyType.Char;
            }
        }
        return null;
    }

    public static MyType SymbolType2VarMyType(SymbolType symbolType){
        switch(symbolType){
            case IntVar,ConstInt -> {
                return MyType.Int;
            }
            case CharVar, ConstChar ->{
                return MyType.Char;
            }
            case CharArray, ConstCharArray ->{
                return MyType.CharArray;
            }
            case IntArray,ConstIntArray ->{
                return MyType.IntArray;
            }

        }
        return null;
    }

    public static MyType SymbolType2FuncMyType(SymbolType symbolType){
        switch(symbolType){
            case VoidFunc -> {
                return MyType.Void;
            }
            case IntFunc -> {
                return MyType.Int;
            }
            case CharFunc -> {
                return MyType.Char;
            }
        }
        return null;
    }

    public static SymbolType TokenType2FuncSymbolType(TokenType tokenType){
        switch(tokenType){
            case VoidTk -> {
                return SymbolType.VoidFunc;
            }
            case IntTk -> {
                return SymbolType.IntFunc;
            }
            case CharTk -> {
                return SymbolType.CharFunc;
            }
        }
        return null;
    }

    public static SymbolType MyType2VarSymbolType(MyType myType, boolean constant){
        if(!constant){
            switch(myType){
                case Int -> {
                    return SymbolType.IntVar;
                }
                case Char -> {
                    return SymbolType.CharVar;
                }
                case CharArray -> {
                    return SymbolType.CharArray;
                }
                case IntArray -> {
                    return SymbolType.IntArray;
                }
            }
            return null;
        }
        else{
            switch(myType){
                case Int -> {
                    return SymbolType.ConstInt;
                }
                case Char -> {
                    return SymbolType.ConstChar;
                }
                case CharArray -> {
                    return SymbolType.ConstCharArray;
                }
                case IntArray -> {
                    return SymbolType.ConstIntArray;
                }
            }
            return null;
        }
    }

    public static int getNumFromPrintString(String str){
        String string = str;
        int num = 0;
        int index = -1;
        while(true){
            int index1 = string.indexOf("%d", index+1);
            int index2 = string.indexOf("%c", index+1);
            if(index1 == -1 && index2 == -1){
                break;
            }
            else if(index1 != -1 && index2 != -1) {
                index = Math.min(index1, index2);
            }
            else {
                index = Math.max(index1, index2);
            }
            num ++;
        }
        return num;
    }

    public static boolean CheckReturn(GrammarTreeNode blockItem){
        if(blockItem.getChildren()!= null && !blockItem.getChildren().isEmpty()){
            GrammarTreeNode stmt = blockItem.getChildren().get(0);
            if(!stmt.getChildren().isEmpty()){
                if(stmt.getChildren().get(0).getGrammarWord() instanceof Token token){
                    return token.getType() == TokenType.ReturnTk;
                }
            }
        }
        return false;
    }

    public static boolean CheckType(MyType type1, MyType type2){
        if(type1 == MyType.IntArray || type1 == MyType.CharArray){

            if(type2 == MyType.Int || type2 == MyType.Char){
                //传递变量给数组
                return false;
            }
            if(type1 == MyType.IntArray && type2 == MyType.CharArray){
                return false;
            }
            if(type1 == MyType.CharArray && type2 == MyType.IntArray){
                return false;
            }
        }
        else if (type1 == MyType.Int || type1 == MyType.Char) {
            if(type2 == MyType.IntArray || type2 == MyType.CharArray) {
                //传递数组给变量
                return false;
            }
        }
        return true;
    }
}
