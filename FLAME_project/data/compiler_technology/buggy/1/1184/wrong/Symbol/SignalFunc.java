package Symbol;

import node.FuncFParamNode;

import java.util.ArrayList;

public class SignalFunc implements Signal {
    private String ident;
    private ArrayList<SignalParams> params;
    private SignalType type;
    private SignalList list;

    public SignalFunc(String ident, ArrayList<FuncFParamNode> params, int type) {
        this.ident = ident;
        this.params = new ArrayList<>();
        for (FuncFParamNode funcFParamNode : params) {
            this.params.add(new SignalParams(funcFParamNode.getIdent(), funcFParamNode.getType()));
        }

        if (type == 0) {
            this.type = SignalType.IntFunc;
        } else if (type == 1) {
            this.type = SignalType.CharFunc;
        } else {
            this.type = SignalType.VoidFunc;
        }
    }

    public void setList(SignalList l) {
        list = l;
    }

    public SignalList getList() {
        return list;
    }

    public ArrayList<SignalParams> getParams() {
        return params;
    }

    public SignalType getType() {
        return type;
    }

    public String getIdent() {
        return ident;
    }

    @Override
    public void print() {
        System.out.print(ident + " " + type + "\n");
    }
}
