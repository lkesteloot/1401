
IBM 1401 Reference Sheet
========================

This is a quick-reference sheet for the IBM 1401.

Instructions
============

     Op  SPS   Aut    Function
     @   M     M      Multiply A into B. B's length is sum of operand lengths plus one.
                      B's operand is left-justified.
     0+  ZA    ZA     Moves A to B. A can be shorter. Sets sign bits on B.
     0-  ZS    ZS     Moves A to B and negates. A can be shorter. Sets sign bits on B.
     A   A     A      Adds A to B. A can be shorter. Sets sign bits on B.
     S   S     S      Substracts A from B. A can be shorter. Sets sign bits on B.
     B   B     BCE    Jump to A if characters pointed to by B equals d.

