A flex and parser written by Jakob Adamsson and Emil Gullbrandsson. To use it, make sure to have Flex and Bison installed:
```
apt-get install bison
apt-get install flex
```

Make sure to have graphwiz aswell:
```
apt-get install graphviz
```

When set up, you may run **make** inorder to build, then either in test.txt write some testcases or use the pre-defined javafiles. To use the compiler, type:
```
./compiler test.txt

or

e.g:
./compiler test_files/valid/binarysearch.java
```

To build the AST(abstract syntax tree) type the following:
```
make tree
```
Now a PDF should be located in your current working directory containing the AST.
