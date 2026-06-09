package parser_part.declaration;

import parser_part.Ident;
import parser_part.Node;
import parser_part.expression.ConstExp;

import java.util.ArrayList;

public interface Def extends Node {

    Ident getIdent();
}
