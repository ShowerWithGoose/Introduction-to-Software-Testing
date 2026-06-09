package frontend.Error;

public enum ErrorType
{
    IllegalCharacter("a"),
    VarAlreadyDefined("b"),
    NameUndeclared("c"),
    FuncParamNumUnmatched("d"),
    FuncParamTypeUnmatched("e"),
    UnmatchedReturnOfVoid("f"),
    LackOfReturnOfUnVoid("g"),
    ChangeValueOfConst("h"),
    LackOfRBracket("k"),
    LackOfRParent("j"),
    LackOfSemicolon("i"),
    UnmatchedPrintfParam("l"),
    RCNotInCircle("m"),

    ;
    private String value;

    ErrorType(String value) {
        this.value = value;
    }

    @Override
    public String toString() {
        return value;
    }
}
