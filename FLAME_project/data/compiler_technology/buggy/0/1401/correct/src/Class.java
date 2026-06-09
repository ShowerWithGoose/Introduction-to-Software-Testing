package src;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Class {
    private Word name;
    private Enum anEnum;

    public Class() {
        this.name = new Word();
    }

    public void add(Character character) {
        name.add(character);
    }

    public ArrayList<Character> getName() {
        return name.getWord();
    }

    public void IDENFR() {
        anEnum = Enum.IDENFR;
    }

    public void INTCON() {
        anEnum = Enum.INTCON;
    }

    public void STRCON() {
        anEnum = Enum.STRCON;
    }

    public void CHRCON() {
        anEnum = Enum.CHRCON;
    }

    public void MAINTK() {
        anEnum = Enum.MAINTK;
    }

    public void CONSTTK() {
        anEnum = Enum.CONSTTK;
    }

    public void INTTK() {
        anEnum = Enum.INTTK;
    }

    public void CHARTK() {
        anEnum = Enum.CHARTK;
    }

    public void BREAKTK() {
        anEnum = Enum.BREAKTK;
    }

    public void CONTINUETK() {
        anEnum = Enum.CONTINUETK;
    }

    public void IFTK() {
        anEnum = Enum.IFTK;
    }

    public void ELSETK() {
        anEnum = Enum.ELSETK;
    }

    public void NOT() {
        anEnum = Enum.NOT;
    }

    public void AND() {
        anEnum = Enum.AND;
    }

    public void OR() {
        anEnum = Enum.OR;
    }

    public void FORTK() {
        anEnum = Enum.FORTK;
    }

    public void GETINTTK() {
        anEnum = Enum.GETINTTK;
    }

    public void GETCHARTK() {
        anEnum = Enum.GETCHARTK;
    }

    public void PRINTFTK() {
        anEnum = Enum.PRINTFTK;
    }

    public void RETURNTK() {
        anEnum = Enum.RETURNTK;
    }

    public void PLUS() {
        anEnum = Enum.PLUS;
    }

    public void MINU() {
        anEnum = Enum.MINU;
    }

    public void VOIDTK() {
        anEnum = Enum.VOIDTK;
    }

    public void MULT() {
        anEnum = Enum.MULT;
    }

    public void DIV() {
        anEnum = Enum.DIV;
    }

    public void MOD() {
        anEnum = Enum.MOD;
    }

    public void LSS() {
        anEnum = Enum.LSS;
    }

    public void LEQ() {
        anEnum = Enum.LEQ;
    }

    public void GRE() {
        anEnum = Enum.GRE;
    }

    public void GEQ() {
        anEnum = Enum.GEQ;
    }

    public void EQL() {
        anEnum = Enum.EQL;
    }

    public void NEQ() {
        anEnum = Enum.NEQ;
    }

    public void ASSIGN() {
        anEnum = Enum.ASSIGN;
    }

    public void SEMICN() {
        anEnum = Enum.SEMICN;
    }

    public void COMMA() {
        anEnum = Enum.COMMA;
    }

    public void LPARENT() {
        anEnum = Enum.LPARENT;
    }

    public void RPARENT() {
        anEnum = Enum.RPARENT;
    }

    public void LBRACK() {
        anEnum = Enum.LBRACK;
    }

    public void RBRACK() {
        anEnum = Enum.RBRACK;
    }

    public void LBRACE() {
        anEnum = Enum.LBRACE;
    }

    public void RBRACE() {
        anEnum = Enum.RBRACE;
    }

    public void word(BufferedWriter out) throws IOException {
        out.write(anEnum.toString() + ' ');
        for (int i=0;i<name.size();i++){
            out.write(name.get(i));
        }
    }
}