/***
 * @Author: hanmi255 hanmi2550505@gmail.com
 * @Date: 2025-05-30 12:07:25
 * @LastEditTime: 2025-05-30 12:07:29
 * @LastEditors: hanmi255 hanmi2550505@gmail.com
 * @Description:
 * @FilePath: \LeetCode\CCF.模板展开.cpp
 * @技术宅拯救世界！！！
 */

/* 题目描述
模板语言涉及到的数据是字符串。我们约定，字符串是由零个或多个小写字母和数字（[a-z0-9]）组成的序列。
模板语言中的变量的名称是非空字符串，且变量的值也是字符串。在模板开始执行前，所有变量的值都是空字符串。
模板语言中的表达式涉及对变量的值和字符串进行拼接操作。
表达式由空格分隔的若干个操作数组成，操作数可以是变量或非空字符串；
其中如果操作数的第一个字符是美元符号($)，则表示该操作数是一个变量，操作数的剩余部分为该变量的名称；
否则，表示该操作数是一个字符串。
表达式的值是指先将表达式中的所有变量替换为其值，然后将所有操作数拼接在一起得到的字符串。

例如，假设有变量 a 的值为 hello，变量 b 的值为 world，则：

表达式 a 的值为 a；
表达式 $a 的值为 hello；
表达式 a b 的值为 ab；
表达式 $a b 的值为 hellob；
表达式 $a $b 的值为 helloworld；
表达式 $a $b a 的值为 helloworlda。

模板语言由一系列语句组成，每个语句占一行，每个语句按顺序执行。
语句分为两类：赋值语句和输出语句。
其中，赋值语句用于将变量和表达式关联起来，输出语句用于输出变量的值。

赋值语句分为两种：直接赋值和间接赋值。
直接赋值语句的形式为空格分隔的数字 1、变量名称和表达式，形如 1 <var>
<expr>，表示求表达式的值并将该值作为变量的值。 例如，语句 1 c $a $b 执行后，变量
c 的值为 helloworld。

间接赋值语句的形式为空格分隔的数字 2、变量名称和表达式，形如 2 <var>
<expr>，表示暂时不求表达式的值， 而是将该表达式与变量相对应。
待到后续求其它表达式的值需要用到该变量时，再求该变量对应的表达式的值并将该值作为变量的值用于求所求的表达式的值。
例如考虑以下模板：
1 a hello
1 b world
2 c $a $b
1 d good $c
1 a hi
1 e good $c
在执行第三个语句 2 c $a $b 时，变量 c 与表达式 $a $b
对应起来，但并不求表达式的值。 在执行第四个语句 1 d good $c 时，需要求表达式
good $c 的值，并将该值作为变量 d 的值。 此时需要用到变量 c，因此需要先求表达式
$a $b 的值，即 helloworld，然后再和 good 拼接得到 goodhelloworld。
因此，执行完第四个语句后，变量 d 的值为 goodhelloworld。在执行第五个语句 1 a hi
时，变量 a 的值被更新为 hi。 在执行第六个语句 1 e good $c 时，需要求表达式 good
$c 的值，需要用到变量 c，此时仍要重新求表达式 $a $b 的值， 即 hiworld，然后再和
good 拼接得到 goodhiworld。因此，执行完第六个语句后，变量 e 的值为 goodhiworld。
需要注意的是，虽然变量 c 没有被重新赋值，但由于 c 是间接赋值的，所以在每次用到 c
时都要重新求表达式 $a $b 的值， 即 c 的值是动态的。

输出语句的形式为空格分隔的数字 3 和变量名称，形如 3 <var>，表示输出一行，
内容为变量的值的长度除以 1000000007 的余数。例如，语句 3 d 表示输出变量 d
的值的长度。 用输出语句修改上述例子的模板：

1 a hello
1 b world
2 c $a $b
3 c
1 a hi
3 c
将会输出：10 和 7，对应的变量的值为：

helloworld
hiworld

需要注意的是，在使用间接赋值语句时，在变量的值之间建立了依赖关系，
在上述模板中，变量 c 的值依赖于变量 a 和 b 的值。
可以想见，如果变量的值间的依赖关系形成了环，那么模板将无法执行。
我们约定，给定的表达式中不存在这样的环。

形式化地，模板语言用 BNF 表示如下：

CHAR ::= [a-z0-9]
SPACE ::= ' '
DOLLAR ::= '$'
NONEMPTY_STRING ::= CHAR | NONEMPTY_STRING CHAR
STRING ::= '' | NONEMPTY_STRING
VAR ::= NONEMPTY_STRING
OPERAND ::= DOLLAR VAR | NONEMPTY_STRING
EXPR ::= OPERAND | EXPR SPACE OPERAND
ASSIGN_OP ::= '1' | '2'
ASSIGN ::= ASSIGN_OP SPACE VAR SPACE EXPR
OUTPUT ::= '3' SPACE VAR
STATEMENT ::= ASSIGN | OUTPUT

输入格式
从标准输入读入数据。

输入的第一行为一个整数 n，表示模板语言的语句数量。接下来的 n
行，每行为一个语句，语句的格式如上所述。

输出格式
输出到标准输出。

依次执行输入的语句：如果语句为输出语句，则相应输出一行变量的值的长度除以
1000000007 的余数。

样例1输入
6
1 a hello
1 b world
2 c $a $b
3 c
1 a hi
3 c
样例1输出
10
7
样例1解释
本样例即为题目描述中的例子。

样例2输入
5
1 var value
3 var
3 val
1 var $var $val $var
3 var
样例2输出
5
0
10
样例2解释
执行第一条语句后，变量 var 的值为 value，因此第二条语句输出 5；
执行第三条语句时，变量 val 并未被赋值，因此其值为初始的空字符串，输出 0；
执行第四条语句后，变量 var 的值为 valuevalue，因此第五条语句输出 10。

子任务
测试点	n	    语句类型	    表达式的性质
1, 2  ≤200     无间接赋值语句	每个表达式仅有1个字符串操作数
3, 4	                       每个表达式仅有1个操作数
5, 6	                       每个表达式包含不超过100个操作数
7, 8	       包含所有类型语句
9, 10  ≤2000
全部的数据满足：变量的总数不超过 1000 个，且每个变量的名称、字符串的长度不超过
50 个字符。 */

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

static const int MOD = 1000000007;
using namespace std;

// 表示一个操作数，常量字符或者变量引用
struct Operand {
    bool is_var;  // 是否为变量引用
    string value; // 值
};

// 变量存储结构：支持直接赋值(len >= 0)和间接赋值(expr为空)、
struct VarNode {
    long long len;        // 直接赋值后的长度；若为 -1，表示当前是间接赋值
    vector<Operand> expr; // 间接赋值时保存的表达式操作数列表
};

unordered_map<string, VarNode> vars;

// 递归计算变量 varName 的当前值长度（含间接依赖），并取模
long long evalLen(const string &varName) {
    auto &node = vars[varName];

    // 如果是直接赋值，len >= 0 即可直接返回
    if (node.len >= 0) {
        return node.len;
    }

    // 否则为间接赋值：递归计算 expr 中每个操作数的长度再求和
    long long total = 0;
    for (auto &op : node.expr) {
        if (op.is_var) {
            // 变量引用，递归调用
            total = (total + evalLen(op.value)) % MOD;
        } else {
            // 常量字符串，直接加其长度
            total = (total + (int)op.value.size()) % MOD;
        }
    }
    return total;
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int type;
        string var;
        cin >> type >> var;

        if (type == 1) {
            vector<Operand> ops;
            string token;
            getline(cin, token);
            istringstream iss(token);
            string sym;

            while (iss >> sym) {
                if (sym[0] == '$') {
                    // 变量引用
                    ops.push_back({true, sym.substr(1)});
                } else {
                    // 常量字符串
                    ops.push_back({false, sym});
                }
            }

            // 立即求表达式长度并存入vars[var]
            long long cur = 0;
            for (const auto &op : ops) {
                if (op.is_var) {
                    cur = (cur + evalLen(op.value)) % MOD;
                } else {
                    cur = (cur + op.value.size()) % MOD;
                }
            }

            vars[var] = {cur, {}};
        } else if (type == 2) {
            vector<Operand> ops;
            string token;
            getline(cin, token);
            istringstream iss(token);
            string sym;

            while (iss >> sym) {
                if (sym[0] == '$') {
                    // 变量引用
                    ops.push_back({true, sym.substr(1)});
                } else {
                    // 常量字符串
                    ops.push_back({false, sym});
                }
            }

            // 存储表达式，不立即求值
            vars[var] = {-1, ops};
        } else {
            long long ans = evalLen(var) % MOD;
            cout << ans << endl;
        }
    }

    return 0;
}