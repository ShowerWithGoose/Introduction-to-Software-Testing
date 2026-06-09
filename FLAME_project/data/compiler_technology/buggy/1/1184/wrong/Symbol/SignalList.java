package Symbol;

import java.util.ArrayList;

public class SignalList implements Signal {
    private ArrayList<Signal> list;
    private int num; //记录作用域序号 如果是函数，则需要根据上一层？
    private SignalType type;
    private SignalList out;
    private boolean returned;

    public SignalList(int num,SignalType type,SignalList out) {
        this.list = new ArrayList<>();
        this.num = num;
        this.type = type;
        this.out = out;
        this.returned = false;
    }

    public void setReturned() {
        returned = true;
    }

    public boolean getReturned() { //报错报多了！！
        return returned;
    }

    public SignalList getOut() {
        return out;
    }

    public boolean findSignal(String ident) {
        for (Signal s : list) {
            if (s instanceof SignalNode) {
                if (((SignalNode) s).equalIdent(ident)) {
                    return true;
                }
            }
            else if (s instanceof SignalFunc) {
                if (((SignalFunc) s).getIdent().equals(ident)) {
                    return true;
                }
            }
        }
        if (out != null) {
            return out.findSignal(ident);
        }
        return false;
    }

    public boolean findSignalb(String ident) {
        for (Signal s : list) {
            if (s instanceof SignalNode) {
                if (((SignalNode) s).equalIdent(ident)) {
                    return true;
                }
            }
            else if (s instanceof SignalFunc) {
                if (((SignalFunc) s).getIdent().equals(ident)) {
                    return true;
                }
            }
        }
        return false;
    }

    public int getLayer() {
        return num;
    }

    public Signal findS(String ident) {
        for (Signal s : list) {
            if (s instanceof SignalNode) {
                if (((SignalNode) s).equalIdent(ident)) {
                    return s;
                }
            }
            else if (s instanceof SignalFunc) {
                if (((SignalFunc) s).getIdent().equals(ident)) {
                    return s;
                }
            }
        }
        if (out != null) {
            return out.findS(ident);
        }
        return null;
    }

    public void addSignal(Signal signal) {
        list.add(signal);
    }

    public SignalType findIdentType(String ident) {
        for (Signal s : list) {
            if (s instanceof SignalNode) {
                if (((SignalNode) s).equalIdent(ident)) {
                    return ((SignalNode) s).getType();
                }
            }
            else if (s instanceof SignalFunc) {
                if (((SignalFunc) s).getIdent().equals(ident)) {
                    return ((SignalFunc) s).getType();
                }
            }
        }
        if (out != null) {
            return out.findIdentType(ident);
        }
        return SignalType.NULL;
    }

    @Override
    public void print() {
        for (Signal s : list) {
            if (s instanceof SignalList) {
                continue;
            }
            System.out.print(num + " ");
            s.print();
        }

        for (Signal s : list) {
            if (s instanceof SignalList) {
                //System.out.print(num + " ");
                s.print();
            }

        }

    }

    public boolean canReturn() {
        if (type.equals(SignalType.IntFunc) || type.equals(SignalType.CharFunc)) {
            return true;
        }
        if (out != null) {
            return out.canReturn();
        }
        return false;
    }

    public boolean canReturnf() {
        if (type.equals(SignalType.IntFunc) || type.equals(SignalType.CharFunc)) {
            return true;
        }

        return false;
    }

    public void copyList(SignalList s) {
        list.add(s);
    }
}
