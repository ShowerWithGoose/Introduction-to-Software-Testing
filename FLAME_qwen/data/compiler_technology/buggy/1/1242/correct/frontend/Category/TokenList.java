package frontend.Category;

import java.util.ArrayList;

public class TokenList {
    private static ArrayList<Token> list = new ArrayList<>();
    private static int index = 0;


    public static void AddToken(Token token) {
        list.add(token);
    }

    public static Token GetToken() {
        if (Over()) {
            return null;
        }
        return list.get(index++);
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
