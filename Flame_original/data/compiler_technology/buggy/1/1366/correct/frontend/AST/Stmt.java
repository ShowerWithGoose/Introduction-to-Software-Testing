package frontend.AST;

import frontend.AST.Exp.Exp;
import frontend.AST.Val.LVal;
import frontend.LexType;
import frontend.Token;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;

public class Stmt {
    private int type;
    //type = 1 assign
    private LVal lVal;
    private Token equal;// '='
    private Exp exp;
    private Token semicolon;

    // type = 2 [Exp] ';' // i

    //type = 3 block
    private Block block;
    // type = 4 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    private Token if_sign;
    private Token if_lParent;
    private Token if_rParent;
    private Token else_sign;
    private Stmt if_stmt;
    private Stmt else_stmt;
    private Cond if_cond;
    //type = 5 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    private Token for_sign;
    private Token for_lParent;
    private Token for_rParent;
    private Stmt for_stmt;
    private Token for_semicolon1,for_semicolon2;
    private Cond for_cond;
    private ForStmt f1,f2;

    //type = 6 'break' ';' |  7 'continue' ';' // i
    private Token break_continue_sign;
    private Token break_continue_semicolon;

    //type = 7 'continue' ';' // i

    //type = 8 'return' ';' // i
    private Token return_sign;
    private Exp return_exp;
    private Token return_semicolon;

    //type = 9  LVal '=' 'getint''('')'';' // i j
    private LVal get_LVal;
    private Token get_equal;
    private Token getInt_sign = null;
    private Token getChar_sign = null;
    private Token get_lParent;
    private Token get_rParent;
    private Token get_semicolon;
    // type = 10 'printf''('StringConst {','Exp}')'';' // i j
    private Token printf;
    private Token printf_lParent;
    private Token printf_rParent;
    private Token stringConst;
    private ArrayList<Exp> printf_exp;
    private Token printf_semicolon;

    public Stmt(LVal lVal,Token equal,Token getIntChar,Token l,Token r,Token semi) {
        type = 9;
        get_LVal = lVal;
        get_equal = equal;
        if (getIntChar.getLexType() == LexType.GETINTTK) {
            getInt_sign = getIntChar;
        } else {
          getChar_sign = getIntChar;
        }
        get_lParent = l;
        get_rParent = r;
        get_semicolon = semi;
    }

    public Stmt(LVal lVal,Token equal,Exp e,Token semi) {
        type = 1;
        this.lVal = lVal;
        this.equal = equal;
        this.exp = e;
        this.semicolon = semi;
    }

    public Stmt(Block b) {
        type = 3;
        block = b;
    }

    public Stmt(Exp e,Token semi) {
        type = 2;
        this.exp = e;
        this.semicolon = semi;
    }

    public Stmt(Token CBTK,Token semi) {
        type = 6;
        this.break_continue_sign = CBTK;
        this.break_continue_semicolon = semi;
    }

    public Stmt(Token ifTk,Token l ,Cond c,Token r, Stmt s1,Token elseTK,Stmt s2) {
        type = 4;
        if_sign = ifTk;
        if_lParent = l;
        if_cond = c;
        if_rParent = r;
        if_stmt = s1;
        else_sign = elseTK;
        else_stmt = s2;
    }

    public Stmt(Token forTK,Token l,ForStmt fs1,Token s1,Cond c,Token s2,ForStmt fs2,Token r,Stmt s) {
        type = 5;
        for_sign = forTK;
        for_lParent = l;
        f1 = fs1;
        f2 = fs2;
        for_semicolon1 = s1;
        for_semicolon2 = s2;
        for_rParent = r;
        for_cond = c;
        for_stmt = s;
    }

    public Stmt(Token returnTk,Exp exp,Token s) {
        type = 7;
        return_sign = returnTk;
        return_exp = exp;
        return_semicolon = s;
    }

    public Stmt(Token printTk,Token l,Token stringConst1,ArrayList<Exp> printf_exp1,Token r,Token s) {
        type = 8;
        printf_exp = printf_exp1;
        printf_rParent = r;
        printf_lParent = l;
        stringConst = stringConst1;
        printf = printTk;
        printf_semicolon = s;
    }

    public void postorder() {
        Path path = Paths.get("parser.txt");
        try {
            switch (type) {
                case 1: {
                    lVal.postorder();
                    Files.write(path, equal.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    exp.postorder();
                    if (semicolon != null) {
                        Files.write(path, semicolon.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    break;
                }
                case 2: {
                    if (exp != null) {
                        exp.postorder();
                    }
                    if (semicolon != null) {
                        Files.write(path, semicolon.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    break;
                }
                case 3:{
                    block.postorder();
                    break;
                }
                case 4:{
                    Files.write(path, if_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    Files.write(path, if_lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if_cond.postorder();
                    if (if_rParent != null) {
                        Files.write(path, if_rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    if_stmt.postorder();
                    if (else_sign != null) {
                        Files.write(path, else_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                        else_stmt.postorder();
                    }
                    break;
                }
                case 5:{
                    Files.write(path, for_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    Files.write(path, for_lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if (f1 != null) {
                        f1.postorder();
                    }
                    Files.write(path, for_semicolon1.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if (for_cond != null) {
                        for_cond.postorder();
                    }
                    Files.write(path, for_semicolon2.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if (f2 != null) {
                        f2.postorder();
                    }
                    Files.write(path, for_rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    for_stmt.postorder();
                    break;
                }
                case 6:{
                    Files.write(path, break_continue_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if (break_continue_semicolon != null) {
                        Files.write(path, break_continue_semicolon.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    break;
                }
                case 7:{
                    Files.write(path, return_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if (return_exp != null) {
                        return_exp.postorder();
                    }
                    if (return_semicolon != null) {
                        Files.write(path, return_semicolon.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    break;
                }
                case 8:{
                    Files.write(path, printf.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    Files.write(path, printf_lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    Files.write(path, stringConst.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    for (Exp exp1 : printf_exp) {
                        Token t = new Token(LexType.COMMA,1 ,",");
                        Files.write(path, t.toString().getBytes(StandardCharsets.UTF_8),StandardOpenOption.APPEND);
                        exp1.postorder();
                    }
                    if (printf_rParent != null) {
                        Files.write(path, printf_rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    if (printf_semicolon != null) {
                        Files.write(path, printf_semicolon.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    break;
                }
                case 9:
                {
                    get_LVal.postorder();
                    Files.write(path, get_equal.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if (getInt_sign == null) {
                        Files.write(path, getChar_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    else {
                        Files.write(path, getInt_sign.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    Files.write(path, get_lParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    if (get_rParent != null) {
                        Files.write(path, get_rParent.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    if (get_semicolon != null) {
                        Files.write(path, get_semicolon.toString().getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
                    }
                    break;
                }
                default:
            }
            Files.write(path, "<Stmt>\n".getBytes(StandardCharsets.UTF_8), StandardOpenOption.APPEND);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}


