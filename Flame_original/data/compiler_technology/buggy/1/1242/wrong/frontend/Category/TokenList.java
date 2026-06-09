package frontend.Category;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class TokenList {
    private static ArrayList<Token> list = new ArrayList<>();

    private static HashMap<Token,Integer> tokenScope = new HashMap<>();
    private static int index = 0;

    private static ArrayList<Integer> scopeTable = new ArrayList<>();

    private static HashMap<Integer,Integer> scopeFather = new HashMap<>();

    //private static HashSet<Integer> loopScope = new HashSet<>();

    //private static HashSet<Token> tokenInLoop = new HashSet<>();

    static {
        scopeTable.add(1);
    }

    private static int scopeNumber = 1;

    //private static int loopDepth = 0;

    private static boolean passLeft = false;

    private static boolean passRight = false;

    public static void AddToken(Token token) {
        if (list.size() != 0 && list.get(list.size() - 1).GetCategory() == Category.ASSIGN) {
            passLeft = true;
        } else {
            passLeft = false;
        }
        list.add(token);
        if (token.GetCategory() == Category.LBRACE) {
            if (!passLeft) {
                scopeNumber++;
                scopeFather.put(scopeNumber, scopeTable.get(scopeTable.size() - 1));
                scopeTable.add(scopeNumber);
            } else {
                passRight = true;
            }
        } else if (token.GetCategory() == Category.RBRACE) {
            if (!passRight) {
                scopeTable.remove(scopeTable.size() - 1);
            } else {
                passRight = false;
            }
        }
        tokenScope.put(token,scopeTable.get(scopeTable.size() - 1));
    }

    public static Token GetToken() {
        if (Over()) {
            return null;
        }
        return list.get(index++);
    }

    public static Token GetTokenByPtr(int ptr) {
        return list.get(index + ptr);
    }

    public static int GetIndex() {
        return index;
    }

    public static void SetIndex(int a) {
        index = a;
    }
    public static boolean Over() {
        return index >= list.size();
    }

    public static boolean NextIs(Category category) {
        return GetToken().GetCategory() == category;
    }

    public static int ErrorLine() {
        return list.get(index - 1).GetLine();
    }

    public static int Scope() {
        return tokenScope.get(list.get(index - 1));
    }

    public static int ScopeByIndex(int a) {
        return tokenScope.get(list.get(a + index));
    }

    public static int ScopeFather(int scope) {
        if (scopeFather.containsKey(scope)) {
            return scopeFather.get(scope);
        }
        return 0;
    }

    public static int GetScopeNumber() {
        return scopeNumber;
    }

    public static ArrayList<Token> GetList() {
        return list;
    }

    public static class Main {
        public static void main(String[] args) {
            TokenList.AddToken(new Token(Category.AND,"&&",1));
            TokenList.AddToken(new Token(Category.ASSIGN,"=",2));
            System.out.println(GetToken().toString() + " " + Over());
            System.out.println(GetToken().toString() + " " + Over());
            System.out.println(GetToken().toString() + " " + Over());
        }
    }
}
