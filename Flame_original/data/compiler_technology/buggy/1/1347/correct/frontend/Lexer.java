package frontend;

import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

public class Lexer {

    private Errors errors;
    private ArrayList<String> sourceCode;
    private int line = 0;
    private int position = 0;
    private Token newToken;
    private String reserveChar = "!&|+-*%<>=,;()[]{}";
    private String doubleChar = "!&|<>=";
    private boolean arriveEnd = false;
    private int nowLine = -1;

    public Lexer(Errors errors, ArrayList<String> code) {
        this.sourceCode = code;
        this.errors = errors;
    }

    public void next() {
        StringBuilder stringBuilder = new StringBuilder();
        Character character;
        if (!isEnd()) {
            character = getChar();
            this.nowLine = this.line;
        } else {
            setArriveEnd();
            return;
        }
        while (!isEnd() && (character == ' ' || character == '\t' || character == '\n')) {
            character = getChar();
            this.nowLine = this.line;
        }

        if (isEnd()) {
            setArriveEnd();
            return;
        }

        if (isIdentNonDigit(character)) {
            identLexer(character);
        } else if (Character.isDigit(character)) {
            digitConst(character);
        } else if (character.equals('\'')) {
            charConst(character);
        } else if (character.equals('"')) {
            stringConst(character);
        } else if (this.reserveChar.contains(character.toString())) {
            otherReserveWord(character);
        } else if (character.equals('/')) {
            Character character1;
            if (!isEnd()) {
                character1 = getChar();
            } else {
                setArriveEnd();  //             maybe have illegal format
                System.out.println("\\ lexer error");
                return;
            }
            if (character1.equals('/')) {
                skipOneLine();
            } else if (character1.equals('*')) {
                multilineComment();
            } else {
                unGetChar();
                newToken = new Token(LexType.DIV, "/", this.nowLine + 1);
            }
        }
    }

    private void multilineComment() {
        Character character;
        if (!isEnd()) {
            character = getChar();
        } else {
            setArriveEnd();
            return;
        }
        while (!isEnd()) {
            while (!isEnd() && !character.equals('*')) {
                character = getChar();
            }

            while (!isEnd() && character.equals('*')) {
                character = getChar();
            }
            if (character.equals('/')) {
                break;
            }
        }
        next();
    }

    private void otherReserveWord(Character character) {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(character);
        if (this.doubleChar.contains(character.toString())) {
            Character characterNext;
            if (!isEnd()) {
                characterNext = getChar();
            } else {
                setArriveEnd();
                String stringTemp = stringBuilder.toString();
                this.newToken = new Token(ReservedWords.getInstance().isReserve(stringTemp),
                        stringTemp, this.nowLine + 1);
                return;
            }
            if (character.equals('!')) {
                if (characterNext.equals('=')) {
                    stringBuilder.append(characterNext);
                } else {
                    unGetChar();
                }
            } else if (character.equals('&')) { // 错误处理
                if (characterNext.equals('&')) {
                    stringBuilder.append(characterNext);
                } else {
                    stringBuilder.append('&');
                    MyError error = new MyError(this.nowLine + 1, ErrorType.a);
                    errors.setErrors(error);
                    unGetChar();
                }
            } else if (character.equals('|')) { // 错误处理 and LexType
                //TOOD;
                if (characterNext.equals('|')) {
                    stringBuilder.append(characterNext);
                } else {
                    stringBuilder.append('|');
                    MyError error = new MyError(this.nowLine + 1, ErrorType.a);
                    errors.setErrors(error);
                    unGetChar();
                }
            } else if (character.equals('<')) {
                if (characterNext.equals('=')) {
                    stringBuilder.append(characterNext);
                } else {
                    unGetChar();
                }
            } else if (character.equals('>')) {
                if (characterNext.equals('=')) {
                    stringBuilder.append(characterNext);
                } else {
                    unGetChar();
                }
            } else if (character.equals('=')) {
                if (characterNext.equals('=')) {
                    stringBuilder.append(characterNext);
                } else {
                    unGetChar();
                }
            }
        }
        String stringTemp = stringBuilder.toString();
        this.newToken = new Token(ReservedWords.getInstance().isOtherReserve(stringTemp), stringTemp, this.nowLine + 1);
    }

    private void identLexer(Character ch) {
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(ch);
        Character character;

        if (!isEnd()) {
            character = getChar();
        } else {
            setArriveEnd();
            return;
        }

        while (isIdentNonDigit(character) || Character.isDigit(character)) {
            stringBuilder.append(character);
            if (!isEnd()) {
                character = getChar();
            } else {
                setArriveEnd();
                break;
            }
        }
        unGetChar(); // TOOD
        String string = stringBuilder.toString();
        this.newToken = new Token(ReservedWords.getInstance().isReserve(string), string, this.nowLine + 1);
    }

    private void digitConst(Character ch) {
        StringBuilder stringBuilder = new StringBuilder();
        if (ch == '0') {
            this.newToken = new Token(LexType.INTCON, ch.toString(), this.nowLine + 1);
        } else {
            Character character;
            stringBuilder.append(ch);
            if (!isEnd()) {
                character = getChar();
            } else {
                setArriveEnd();
                return;
            }

            while (Character.isDigit(character)) {
                stringBuilder.append(character);
                if (!isEnd()) {
                    character = getChar();
                } else {
                    setArriveEnd();
                    break;
                }
            }
            unGetChar();
            this.newToken = new Token(LexType.INTCON, stringBuilder.toString(), this.nowLine + 1);
        }
    }

    private void charConst(Character ch) {
        StringBuilder sb = new StringBuilder();
        sb.append(ch);
        Character character = getChar();
        if (character.equals('\\')) {
            sb.append(character);
            character = getChar();
            sb.append(character);
            character = getChar();

        } else {
            sb.append(character);
            character = getChar();
        }

        if (character.equals('\'')) {
            sb.append(character);
        } else {
            unGetChar();
            System.out.println("constChar error");
        }
        newToken = new Token(LexType.CHRCON, sb.toString(), this.nowLine + 1);
    }

    private void stringConst(Character ch) {
        StringBuilder sb = new StringBuilder();
        sb.append(ch);
        ch = getChar();
        while (!ch.equals('"')) {
            sb.append(ch);
            ch = getChar();
            if (ch.equals('\\')) { // assume ch is legal  ascii;
                sb.append(ch);
                ch = getChar();
                sb.append(ch);
                ch = getChar();
            }
        }
        sb.append(ch);
        newToken = new Token(LexType.STRCON, sb.toString(), this.nowLine + 1);
    }

    private void unGetChar() {
        if (this.position != 0) {
            this.position--;
        }
    }

    private Character getChar() {
        if (position + 1 > sourceCode.get(line).length()) {
            line++;
            position = 0;
            return '\n';
        }
        Character temp = sourceCode.get(line).charAt(position);
        position++;
        return temp;
    }


    public boolean isEnd() {
        return this.line + 1 > sourceCode.size(); //  && this.position >= sourceCode.get(this.line).length();
    }

    private void skipOneLine() {
        this.line++;
        this.position = 0;
        next();
    }

    public boolean getArriveEnd() {
        return this.arriveEnd;
    }

    public void setArriveEnd() {
        this.arriveEnd = true;
    }

    public Token getNewToken() {
        return this.newToken;
    }

    private boolean isIdentNonDigit(Character character) {
        if (character.equals('_') || Character.isLetter(character)) {
            return true;
        }
        return false;
    }
}
