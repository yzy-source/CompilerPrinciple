实现语法分析器
====
题目要求
----
对预备工作中自然语言描述的简化C编译器的语言特性的语法，设计上下文无关文法进行描述<br>

借助Yacc工具实现语法分析器，考虑语法树的构造：<br>

1.语法树数据结构的设计：节点类型的设定，不同类型节点应保存哪些信息，多叉树的实现方式<br>

2.实现辅助函数，完成节点创建、树创建等功能<br>

3.利用辅助函数，修改上下文无关文法，设计翻译模式<br>

4.修改Yacc程序，实现能构造语法树的分析器<br>

考虑符号表处理的扩充<br>

1.完成语法分析后，符号表项应增加哪些标识符的属性，保存语法分析的结果<br>

2.如何扩充符号表数据结构，Yacc程序如何与Lex程序交互，正确填写符号表项<br>

 

以一个简单的C源程序验证你的语法分析器，可以文本方式输出语法树结构，以节点编号输出父子关系，来验证分析器的正确性，如下例：<br>

```c++
main()
{

    int a, b;

    if (a == 0)

       a = b + 1;

}
```

可能的输出为：忽略标点符号。<br>

0 : Type Specifier,   integer,    Children:<br>

1 : ID Declaration,   symbol: a   Children:<br>

2 : ID Declaration,   symbol: b   Children:<br>

3 : Var Declaration,          Children: 0  1  2<br>

4 : ID Declaration,   symbol: a   Children:<br>

5 : Const Declaration, value:0,    Children:<br>

6 : Expr,        op: ==,    Children: 4  5<br>

7 : ID Declaration,   symbol: a   Children:<br>

8 : ID Declaration,   symbol: b   Children:<br>

9 : Const Declaration, value:1,    Children:<br>

10: Expr,        op: +,     Children: 8  9<br>

11: Expr,        op: =,     Children: 7  10<br>

12: if statement,           Children: 6  11<br>

13: compound statement,        Children: 3 12<br>

