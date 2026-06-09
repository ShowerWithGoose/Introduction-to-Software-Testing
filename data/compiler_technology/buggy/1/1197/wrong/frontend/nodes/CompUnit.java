package frontend.nodes;

import frontend.*;

import java.util.stream.Stream;

public class CompUnit extends Node {
    public CompUnit() {
        super(NodeType.COMP_UNIT);
    }

    public static Node parse() {
        CompUnit compUnit = new CompUnit();
        while (Stream.of(LexType.CONSTTK, LexType.INTTK, LexType.CHARTK)
                .anyMatch((o) -> o == Lexer.INSTANCE.getLexType())) {
            if (Lexer.INSTANCE.getLexType() != LexType.CONSTTK) {
                Lexer.INSTANCE.next();
                Lexer.INSTANCE.next();
                if (Lexer.INSTANCE.getLexType() != LexType.LPARENT) {
                    Lexer.INSTANCE.back(2);
                    compUnit.parseAndAdd(NodeRegistry.DECL);
                } else {
                    Lexer.INSTANCE.back(2);
                    break;
                }
            } else {
                compUnit.parseAndAdd(NodeRegistry.DECL);
            }
        }
        while (Stream.of(LexType.VOIDTK, LexType.INTTK, LexType.CHARTK)
                .anyMatch((o) -> o == Lexer.INSTANCE.getLexType())) {
            if (Lexer.INSTANCE.getLexType() != LexType.INTTK) {
                compUnit.parseAndAdd(NodeRegistry.FUNC_DEF);
            } else {
                Lexer.INSTANCE.next();
                if (Lexer.INSTANCE.getLexType() == LexType.MAINTK) {
                    Lexer.INSTANCE.back();
                    break;
                } else {
                    Lexer.INSTANCE.back();
                    compUnit.parseAndAdd(NodeRegistry.FUNC_DEF);
                }
            }
        }
        compUnit.parseAndAdd(NodeRegistry.MAIN_FUNC_DEF);
        return compUnit;
    }
}
