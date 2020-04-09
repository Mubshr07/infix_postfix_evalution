# Infix to Profix to Evaluation

We commonly write arithmetic expressions in infix form, that is, with each operator placed between its operands, as in the following expression:

```sh
(3 + 4) * (5 / 2)
```
Although we are comfortable writing expressions in this form, infix form has the disadvantage that parentheses must be used to indicate the order in which operators are to be evaluated. These parentheses, in turn, greatly complicate the evaluation process. Evaluation is much easier if we can simply evaluate operators from left to right. Unfortunately, this evaluation strategy will not work with the infix form of arithmetic expressions. However, it will work if the expression is in postfix form. In the postfix form of an arithmetic expression, each ope rator is placed immediately after its operands. The expression above is written in postfix form as

```sh
 3 4 + 5 2 / *
```
Note that both forms place the numbers in the same order (reading from left to right). The order of the operators is different, however, because the operators in the postfix form are positioned in the order in which they are evaluated. The resulting postfix expression is hard to read at first, but it is easy to evaluate. All you need is a stack on which to place intermediate results.

```sh
string InfixToPostfix(const string str)
```
####  Test Plan (infix to postfix Conversion)  
| Test Case (arithmetic Expression) | Post fix expression | Expected result  |
|:------------------------------:|:-------------:|:-----:|
| (3 + 4) * (5 / 2) | 3 4 + 5 2 / * | |
| 2 + 12 / 6      | 2 12 6 / + |    |
| A + B * C – ( D / E + F $ G $ H ) | A B C * + D E / F G $ H $ + -      |    |



Note: only binary operators (+,-,*,/, $(power)) allowed
```sh


T PostfixEvaluation(const string str) // T mean int, double & float
```

#### Test Plan (postfix arithmetic expression evaluation)


| Test case  | Arithmetic expression  | Expected result  | Checked |
|:----------- |:-----------:|:-----------:|:-----------:|
| One operator  | 34+ | 7 | |
| Nested operators | 34+52/* | 14 | |
| Uneven nesting | 93*2+1- | 28 | |
| All operators at end | 4675-+* | 32 | |
| Zero dividend | 02/ | error | |
| Single-digit number | 7 | 7 | |




Author's website [Mubashir Iqbal](https://www.mubashiriqbal07.com/).
