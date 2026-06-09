package src;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.util.Scanner;
import java.io.PrintWriter;

public class LineAnalyzer {
    public LineAnalyzer() {
    }

    public boolean analyze(String line, int lineNumber, boolean isComment, PrintWriter lexerWriter, PrintWriter errorWriter) {
        Scanner scanner = new Scanner(line);
        State state = new State(isComment);
        String token = "";
        int index = 0;
        char currentChar;
        while (true) {
            if (state.getState().equals("comment")) {
                if (index + 1 < line.length() && line.charAt(index) == '*' && line.charAt(index + 1) == '/') {
                    state.changeState("start");
                    index += 2;
                    continue;
                }
                if (index >= line.length() - 1) {
                    return true;
                }
                index++;
                continue;
            }
            if (index >= line.length()) {
                writeToFile(lexerWriter, token, state);
                break;
            }
            currentChar = line.charAt(index);
            if (state.getState().equals("start")) {
                if (currentChar == ' ' || currentChar == '\t' || currentChar == '\n') {
                    index++;
                    continue;
                }
                if (currentChar == '/') {
                    if (index + 1 < line.length() && line.charAt(index + 1) == '/') {
                        writeToFile(lexerWriter, token, state);
                        break;
                    }
                    if (index + 1 < line.length() && line.charAt(index + 1) == '*') {
                        state.changeState("comment");
                        index += 2;
                        continue;
                    }
                }
                if (currentChar == 39) { //single quote
                    state.changeState("singleQuote");
                    index++;
                    continue;
                }
                if (currentChar == 34) { //double quote
                    state.changeState("doubleQuote");
                    index++;
                    continue;
                }
                if (currentChar == '_' || Character.isLetter(currentChar)) {
                    token += currentChar;
                    index++;
                    state.changeState("identifier");
                    continue;
                }
                if (Character.isDigit(currentChar)) {
                    token += currentChar;
                    index++;
                    state.changeState("digit");
                    continue;
                }
                if (currentChar == '+') {
                    token += currentChar;
                    index++;
                    state.changeState("plus");
                    continue;
                }
                if (currentChar == '-') {
                    token += currentChar;
                    index++;
                    state.changeState("minus");
                    continue;
                }
                if (currentChar == '*') {
                    token += currentChar;
                    index++;
                    state.changeState("multiply");
                    continue;
                }
                if (currentChar == '/') {
                    token += currentChar;
                    index++;
                    state.changeState("divide");
                    continue;
                }
                if (currentChar == '%') {
                    token += currentChar;
                    index++;
                    state.changeState("mod");
                    continue;
                }
                if (currentChar == '=') {
                    token += currentChar;
                    index++;
                    state.changeState("equal");
                    continue;
                }
                if (currentChar == '!') {
                    token += currentChar;
                    index++;
                    state.changeState("not");
                    continue;
                }
                if (currentChar == '<') {
                    token += currentChar;
                    index++;
                    state.changeState("lessThan");
                    continue;
                }
                if (currentChar == '>') {
                    token += currentChar;
                    index++;
                    state.changeState("greaterThan");
                    continue;
                }
                if (currentChar == ';') {
                    state.changeState("semicolon");
                    writeToFile(lexerWriter, ";", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == ',') {
                    state.changeState("comma");
                    writeToFile(lexerWriter, ",", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == '(') {
                    state.changeState("leftParenthesis");
                    writeToFile(lexerWriter, "(", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == ')') {
                    state.changeState("rightParenthesis");
                    writeToFile(lexerWriter, ")", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == '[') {
                    state.changeState("leftBracket");
                    writeToFile(lexerWriter, "[", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == ']') {
                    state.changeState("rightBracket");
                    writeToFile(lexerWriter, "]", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == '{') {
                    state.changeState("leftBrace");
                    writeToFile(lexerWriter, "{", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == '}') {
                    state.changeState("rightBrace");
                    writeToFile(lexerWriter, "}", state);
                    state.changeState("start");
                    index++;
                    continue;
                }
                if (currentChar == '&') {
                    state.changeState("and");
                    token += currentChar;
                    index++;
                    continue;
                }
                if (currentChar == '|') {
                    state.changeState("or");
                    token += currentChar;
                    index++;
                    continue;
                }
            }
            if (state.getState().equals("singleQuote")) {
                if(currentChar == 92) {
                    token += currentChar;
                    index++;
                    currentChar = line.charAt(index);
                    token += currentChar;
                    index++;
                    continue;
                }
                if (currentChar == 39) {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    index++;
                    continue;
                }
                token += currentChar;
                index++;
                continue;
            }
            if (state.getState().equals("doubleQuote")) {
                if (currentChar == 34) {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    index++;
                    continue;
                }
                token += currentChar;
                index++;
                continue;
            }
            if (state.getState().equals("identifier")) {
                if (currentChar == '_' || Character.isLetterOrDigit(currentChar)) {
                    token += currentChar;
                    index++;
                    continue;
                }
                writeToFile(lexerWriter, token, state);
                token = "";
                state.changeState("start");
                continue;
            }
            if (state.getState().equals("digit")) {
                if (Character.isDigit(currentChar)) {
                    token += currentChar;
                    index++;
                    continue;
                }
                writeToFile(lexerWriter, token, state);
                token = "";
                state.changeState("start");
                continue;
            }
            if (state.getState().equals("plus")) {
                if (currentChar != '+') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("minus")) {
                if (currentChar != '-') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("multiply")) {
                if (currentChar != '*') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("divide")) {
                if (currentChar != '/') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("mod")) {
                if (currentChar != '%') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("equal")) {
                if (currentChar == '=') {
                    token += currentChar;
                    index++;
                    state.changeState("equalEqual");
                    continue;
                }
                writeToFile(lexerWriter, token, state);
                token = "";
                state.changeState("start");
                continue;
            }
            if (state.getState().equals("equalEqual")) {
                if (currentChar != '=') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("not")) {
                if (currentChar == '=') {
                    token += currentChar;
                    index++;
                    state.changeState("notEqual");
                    continue;
                }
                writeToFile(lexerWriter, token, state);
                token = "";
                state.changeState("start");
                continue;
            }
            if (state.getState().equals("notEqual")) {
                if (currentChar != '=') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("lessThan")) {
                if (currentChar == '=') {
                    token += currentChar;
                    index++;
                    state.changeState("lessThanOrEqual");
                    continue;
                }
                writeToFile(lexerWriter, token, state);
                token = "";
                state.changeState("start");
                continue;
            }
            if (state.getState().equals("lessThanOrEqual")) {
                if (currentChar != '=') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("greaterThan")) {
                if (currentChar == '=') {
                    token += currentChar;
                    index++;
                    state.changeState("greaterThanOrEqual");
                    continue;
                }
                writeToFile(lexerWriter, token, state);
                token = "";
                state.changeState("start");
                continue;
            }
            if (state.getState().equals("greaterThanOrEqual")) {
                if (currentChar != '=') {
                    writeToFile(lexerWriter, token, state);
                    token = "";
                    state.changeState("start");
                    continue;
                }
            }
            if (state.getState().equals("and")) {
                if (currentChar != '&') {
                    writeErrorToFile(errorWriter, lineNumber);
                    LexicalAnalyzer.hasError = true;
                }
                token += currentChar;
                writeToFile(lexerWriter, token, state);
                index++;
                token = "";
                state.changeState("start");
                continue;
            }
            if (state.getState().equals("or")) {
                if (currentChar != '|') {
                    writeErrorToFile(errorWriter, lineNumber);
                    LexicalAnalyzer.hasError = true;
                }
                token += currentChar;
                writeToFile(lexerWriter, token, state);
                index++;
                token = "";
                state.changeState("start");
                continue;
            }
        }
        return false;
    }

    private void writeToFile(PrintWriter writer, String token, State state) {
        if (!token.isEmpty()) {
            switch (state.getState()) {
                case "singleQuote" -> writer.println("CHRCON '" + token + "'");
                case "doubleQuote" -> writer.println("STRCON \"" + token + "\"");
                case "identifier" -> {
                    String translatedToken = translateToken(token);
                    if (translatedToken.equals("FALSE")) {
                        writer.println("IDENFR " + token);
                    } else {
                        writer.println(translatedToken + " " + token);
                    }
                }
                case "digit" -> writer.println("INTCON " + token);
                case "plus" -> writer.println("PLUS " + token);
                case "minus" -> writer.println("MINU " + token);
                case "multiply" -> writer.println("MULT " + token);
                case "divide" -> writer.println("DIV " + token);
                case "mod" -> writer.println("MOD " + token);
                case "equal" -> writer.println("ASSIGN " + token);
                case "equalEqual" -> writer.println("EQL " + token);
                case "not" -> writer.println("NOT " + token);
                case "notEqual" -> writer.println("NEQ " + token);
                case "lessThan" -> writer.println("LSS " + token);
                case "lessThanOrEqual" -> writer.println("LEQ " + token);
                case "greaterThan" -> writer.println("GRE " + token);
                case "greaterThanOrEqual" -> writer.println("GEQ " + token);
                case "semicolon" -> writer.println("SEMICN " + token);
                case "comma" -> writer.println("COMMA " + token);
                case "leftParenthesis" -> writer.println("LPARENT " + token);
                case "rightParenthesis" -> writer.println("RPARENT " + token);
                case "leftBracket" -> writer.println("LBRACK " + token);
                case "rightBracket" -> writer.println("RBRACK " + token);
                case "leftBrace" -> writer.println("LBRACE " + token);
                case "rightBrace" -> writer.println("RBRACE " + token);
                case "and" -> writer.println("AND " + token);
                case "or" -> writer.println("OR " + token);
            }
        }
    }

    private void writeErrorToFile(PrintWriter writer, int lineNumber) {
        writer.println(lineNumber + " a");
    }

    private String translateToken(String token) {
        if (token.equals("int")) {
            return "INTTK";
        }
        if (token.equals("char")) {
            return "CHARTK";
        }
        if (token.equals("if")) {
            return "IFTK";
        }
        if (token.equals("else")) {
            return "ELSETK";
        }
        if (token.equals("return")) {
            return "RETURNTK";
        }
        if (token.equals("break")) {
            return "BREAKTK";
        }
        if (token.equals("continue")) {
            return "CONTINUETK";
        }
        if (token.equals("void")) {
            return "VOIDTK";
        }
        if (token.equals("main")) {
            return "MAINTK";
        }
        if (token.equals("const")) {
            return "CONSTTK";
        }
        if (token.equals("for")) {
            return "FORTK";
        }
        if (token.equals("getint")) {
            return "GETINTTK";
        }
        if (token.equals("getchar")) {
            return "GETCHARTK";
        }
        if (token.equals("printf")) {
            return "PRINTFTK";
        }
        return "FALSE";
    }
}
