package parser_part.declaration;

import parser_part.Node;

import java.util.ArrayList;

public interface DeclComponent extends Node {
    Def getFirstDef();
    ArrayList<Def> getDefs();
}
