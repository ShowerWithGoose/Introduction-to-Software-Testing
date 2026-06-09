package semantic;

import error.NameExistsException;
import io.OutputSystem;

import java.util.ArrayList;
import java.util.HashMap;

public class SymbolTable {

    private final String name;

    private int id;

    private static int ID = 1;

    private boolean cloned = false;

    private final HashMap<String, Info> table = new HashMap<>();

    private final ArrayList<String> list = new ArrayList<>();

    protected SymbolTable(String dir) {
        this.name = dir;
        this.id = ID++;
    }

    protected static void print(OutputSystem system) {
        for (String s : TABLES_NAMES) {
            SymbolTable t = TABLES.get(s);
            system.print(String.valueOf(t.getId()));
            system.print(" ");
            system.print(t.getName());
            system.print("\n");
        }
    }

    protected static void printAns(OutputSystem system) {
        int i = 0;
        for (String s : TABLES_NAMES) {
            i++;
            SymbolTable t = TABLES.get(s);
            for (String ident : t.list) {
                system.print(String.valueOf(i));
                system.print(" ");
                system.print(ident);
                system.print(" ");
                system.print(t.table.get(ident).toString());
                system.print("\n");
            }
        }
    }

    protected void addSymbol(String name, Info info) throws NameExistsException {
        if (table.containsKey(name)) {
            throw new NameExistsException();
        }
        table.put(name, info);
        list.add(name);
    }

    private static final HashMap<String, SymbolTable> TABLES = new HashMap<>();

    private static final ArrayList<String> TABLES_NAMES = new ArrayList<>();

    public static SymbolTable getTable(String name) {
        if (TABLES.containsKey(name)) {
            return TABLES.get(name);
        }
        return null;
    }

    protected static void addTable(SymbolTable table) {
        TABLES.put(table.name, table);
        TABLES_NAMES.add(table.name);
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Info getInfo(String name) {
        if (table.containsKey(name)) {
            return table.get(name);
        }
        else return getInfoFromFather(name);
    }

    private Info getInfoFromFather(String name) {
        String dir = getFatherName(this.name);
        if (dir == null) {
            return null;
        }
        SymbolTable t = TABLES.get(dir);
        if (t == null) {
            return null;
        }
        return t.getInfo(name);
    }

    public static String getDir() {
        return "root";
    }

    public static String getDir(String dir, SymbolType type, String name) {
        return dir + "/" + type + "::" + name;
    }

    public static String getFatherName(String dir) {
        int index = dir.lastIndexOf('/');
        if (index == -1) {
            return null;
        } else {
            return dir.substring(0, index);
        }
    }

    public enum SymbolType {
        Function, Loop, Block, Global
    }
}


