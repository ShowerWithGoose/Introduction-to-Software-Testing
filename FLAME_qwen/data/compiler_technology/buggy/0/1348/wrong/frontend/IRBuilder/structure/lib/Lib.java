package frontend.IRBuilder.structure.lib;

import frontend.IRBuilder.structure.FuncDef;
import frontend.IRBuilder.structure.Function;
import frontend.IRBuilder.structure.SymTab;
import frontend.syntax.Ast;
import type.BasicType;
import type.IntType;

import java.util.ArrayList;

public class Lib {
    public static LibFunc getLibFunc(String name) {
        return switch (name) {
            case "getint" -> new FuncGetint();
            case "printf" -> new FuncPrintf();
            case "getch" -> new FuncGetch();
            case "memset" -> new MemSet();
            default -> null;
        };
    }


    public static class LibFunc extends Function {
        public LibFunc() {
            super(null, null);
        }
    }
    public static class FuncGetint extends LibFunc {

    }

    public static class FuncPrintf extends LibFunc {

    }

    public static class FuncGetch extends LibFunc {

    }

    public static class MemSet extends LibFunc {

    }
}
