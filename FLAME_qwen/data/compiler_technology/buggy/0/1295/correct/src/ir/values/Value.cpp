//
// Created by  on 2024-09-04.
//

#include <algorithm>
#include "Value.h"

namespace ir {
    int Value::generateId() {
        static int idCount = 0;
        return idCount++;
    }

    void Value::addUser(User *u) {
        // 查找是否已经存在u
        auto it = std::find(users.begin(), users.end(), u);
        if (it == users.end()) {
            users.push_back(u);
        }
    }

    void Value::removeUser(User *u) {
        auto it = std::find(users.begin(), users.end(), u);
        if (it != users.end()) {
            users.erase(it);
        }
    }

    void Value::replaceAllUsesWith(Value *replacement) {
        auto slice = users;
        for (User *user : slice) {
            for (int i = 0; i < user->getNumOfOps(); i++) {
                if (user->getOperator(i) == this) {
                    user->setOperator(i, replacement);
                }
            }
        }
    }

    User::User(const std::string &name, Type *type, Value *parent, std::vector<Value *> &operators) : Value(name, type, parent) {
        this->operators.insert(this->operators.end(), operators.begin(), operators.end());
        initUsers();
    }

    void User::initUsers() {
        for (Value *op : operators) {
            if (op) { op->addUser(this); }
        }
    }

    void User::setOperator(int index, Value *newValue) {
        Value *oldValue = operators[index];
        if (oldValue) { oldValue->removeUser(this); }
        operators[index] = newValue;
        newValue->addUser(this);
    }

    void User::removeOperator(Value *op) {
        auto it = std::find(operators.begin(), operators.end(), op);
        if (it != operators.end()) {
            operators.erase(it);
        }
    }

    void User::removeAllOperators() {
        if (operators.empty()) { return; }
        for (Value *op : operators) {
            op->removeUser(this);
        }
        this->operators.clear();
    }

    void User::replaceOperator(Value *oldValue, Value *newValue) {
        // 找到 old value 的位置，然后调用 setOperator
        auto it = std::find(operators.begin(), operators.end(), oldValue);
        if (it != operators.end()) {
            setOperator((int) std::distance(operators.begin(), it), newValue);
        }
    }
} // ir