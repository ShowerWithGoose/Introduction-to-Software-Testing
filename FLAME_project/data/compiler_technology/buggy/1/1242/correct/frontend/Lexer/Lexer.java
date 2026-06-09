package frontend.Lexer;

import frontend.Category.Category;
import frontend.Category.Token;
import frontend.Category.TokenList;
import frontend.Error.Error;
import frontend.Error.ErrorMap;

import java.io.*;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lexer {

    //const
    private static final int norw = 13;

    private static final int txmax = 100;

    private static final int nmax = 14;

    private static final int al = 10;

    private static final int amax = 2047;

    private static final int levmax = 3;

    private static final int cxmax = 200;

    private static final Map<String,String> reserve = new HashMap<>();
    //var
    static {
        reserve.put("main","MAINTK");
        reserve.put("const","CONSTTK");
        reserve.put("int","INTTK");
        reserve.put("char","CHARTK");
        reserve.put("break","BREAKTK");
        reserve.put("continue","CONTINUETK");
        reserve.put("if","IFTK");
        reserve.put("else","ELSETK");
        reserve.put("for","FORTK");
        reserve.put("getint","GETINTTK");
        reserve.put("getchar","GETCHARTK");
        reserve.put("printf","PRINTFTK");
        reserve.put("return","RETURNTK");
        reserve.put("void","VOIDTK");
    }
    private static char ch = ' ';

    private static String lc;

    private static String sym;

    private static String id;

    private static int num;

    private static int cc = 0;

    private static int ll = 0;

    private static String line;

    private static int lineth = -1;

    ///
    private static Scanner scanner;

    private static BufferedWriter lexer;

    private static boolean over = false;
    ///

    public static int GetLineth() {
        return lineth;
    }
    public static void getch() {
        if (cc == ll) {
            ch = '\0';
            //System.out.println((int)ch + " ");
            //Scanner scanner = new Scanner(System.in);
            if (scanner.hasNextLine()) {
                line = scanner.nextLine();
                //lineth++;
            }
            else {
                over = true;
                return;
            }
            if (ll == 0) {
                lineth++;
            }
            ll = line.length();
            cc = 0;
        } else if (cc < ll) {
            if (cc == 0) {
                lineth++;
            }
            ch = line.charAt(cc);
            //System.out.print((int)ch + " ");
            cc++;
        }
    }

    private static void SearchTail() {
        while (ch != '*') {
            getch();
        }
        getch();
        if (ch == '/') {
            getch();
        } else {
            SearchTail();
        }
    }

    public static void getSym() {
        if (over) {
            return;
        }
        while (ch == ' ') {
            getch();
        }
        if (Character.isLetter(ch) || ch == '_') {
            StringBuilder a = new StringBuilder();
            while (Character.isLetterOrDigit(ch) || ch == '_') {
                a.append(ch);
                getch();
            }
            sym = a.toString();
            id = sym;
            if (reserve.containsKey(sym)) {
                lc = reserve.get(sym);
            } else {
                lc = "IDENFR";
            }
        } else if (Character.isDigit(ch)) {
            num = 0;
            StringBuilder a = new StringBuilder();
            while (Character.isDigit(ch)) {
                num = 10 * num + (ch - '0');
                a.append(ch);
                getch();
            }
            lc = "INTCON";
            sym = a.toString();
        } else if (ch == '\'') {
            StringBuilder a = new StringBuilder();
            a.append(ch);
            getch();
            if (ch == '\\') {
                a.append(ch);
                getch();
            }
            a.append(ch);
            getch();
            a.append(ch);
            getch();
            Pattern pattern = Pattern.compile(Category.CHRCON.GetValue());
            Matcher matcher = pattern.matcher(a.toString());
            if (matcher.matches()) {
                lc = "CHRCON";
                sym = a.toString();
            } else {
                System.out.println("error");
                return;
            }
        } else if (ch == '\"') {
            StringBuilder a = new StringBuilder();
            a.append(ch);
            char last = ch;
            getch();
            while (!(ch == '\"' && last != '\\')) {
                a.append(ch);
                last = ch;
                getch();
            }
            a.append(ch);
            getch();
            Pattern pattern;
            if (id.equals("printf")) {
                pattern = Pattern.compile(Category.ASTRCON.GetValue());
            } else {
                pattern = Pattern.compile(Category.STRCON.GetValue());
            }
            Matcher matcher = pattern.matcher(a.toString());
            if (matcher.matches()) {
                lc = "STRCON";
                sym = a.toString();
            } else {
                System.out.println("error");
                return;
            }
        } else if (ch == '!') {
            getch();
            if (ch == '=') {
                getch();
                lc = "NEQ";
                sym = "!=";
            } else {
                lc = "NOT";
                sym = "!";
            }
        } else if (ch == '&') {
            getch();
            if (ch == '&') {
                getch();
                lc = "AND";
                sym = "&&";
            } else {
                ErrorMap.AddError(new Error(lineth,'a'));
                lc = "AND";
                sym = "&";
            }
        } else if (ch == '|') {
            getch();
            if (ch == '|') {
                getch();
                lc = "OR";
                sym = "||";
            } else {
                ErrorMap.AddError(new Error(lineth,'a'));
                lc = "OR";
                sym = "|";
            }
        } else if (ch == '+') {
            getch();
            lc = "PLUS";
            sym = "+";
        } else if (ch == '-') {
            getch();
            lc = "MINU";
            sym = "-";
        } else if (ch == '*') {
            getch();
            lc = "MULT";
            sym = "*";
        } else if (ch == '/') {
            getch();
            if (ch == '*') {
                getch();
                SearchTail();
                return;
            } else if (ch == '/') {
                getch();
                while(ch != '\0') {
                    getch();
                }
                getch();
                return;
            } else {
                lc = "DIV";
                sym = "/";
            }
        } else if (ch == '%') {
            getch();
            lc = "MOD";
            sym = "%";
        } else if (ch == '<') {
            getch();
            if (ch == '=') {
                getch();
                lc = "LEQ";
                sym = "<=";
            } else {
                lc = "LSS";
                sym = "<";
            }
        } else if (ch == '>') {
            getch();
            if (ch == '=') {
                getch();
                lc = "GEQ";
                sym = ">=";
            } else {
                lc = "GRE";
                sym = ">";
            }
        } else if (ch == '=') {
            getch();
            if (ch == '=') {
                getch();
                lc = "EQL";
                sym = "==";
            } else {
                lc = "ASSIGN";
                sym = "=";
            }
        } else if (ch == ';') {
            getch();
            lc = "SEMICN";
            sym = ";";
        } else if (ch == ',') {
            getch();
            lc = "COMMA";
            sym = ",";
        } else if (ch == '(') {
            getch();
            lc = "LPARENT";
            sym = "(";
        } else if (ch == ')') {
            getch();
            lc = "RPARENT";
            sym = ")";
        } else if (ch == '[') {
            getch();
            lc = "LBRACK";
            sym = "[";
        } else if (ch == ']') {
            getch();
            lc = "RBRACK";
            sym = "]";
        } else if (ch == '{') {
            getch();
            lc = "LBRACE";
            sym = "{";
        } else if (ch == '}') {
            getch();
            lc = "RBRACE";
            sym = "}";
        } else if (ch == '\0') {
            getch();
            return;
        } else {
            getch();
            //System.out.println("unknown word");
            return;
        }
        //System.out.println(sym + " " + id);
        TokenList.AddToken(new Token(Category.valueOf(lc),sym,lineth));
        try {
            lexer.write(lc + " " + sym + " " + lineth + "\n");
            lexer.flush();
        } catch (IOException e) {
            System.out.println("IOE");
        }
    }

    public static void ReadFrom(String a, String b) {
        try {
            scanner = new Scanner(new File(a));
            lexer = new BufferedWriter(new FileWriter(b));
            while (!over) {
                getSym();
            }
        } catch (FileNotFoundException e) {
            System.out.println(System.getProperty("user.dir") + " " + "file does not exist1");
        } catch (IOException e) {
            System.out.println("file does not exist2");
        }
    }

    public static class Main {
        public static void main(String args[]) {
            scanner = new Scanner(System.in);
            while(!over) {
                getSym();
            }
        }
    }
}
