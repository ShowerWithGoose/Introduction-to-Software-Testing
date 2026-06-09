package parser_part.declaration.var.varDef;

import parser_part.Ident;
import parser_part.Node;
import parser_part.expression.ConstExp;

import java.util.ArrayList;

public interface VarDefComponent extends Node {
    ArrayList<ConstExp> getConstExps();
    Ident getIdent();
}
