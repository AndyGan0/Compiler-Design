#  Compiler-Design
These are 3 projects created during my university course "COMPILERS"
Language: C++ and Flex

<br>

#  Project 1
Language: C++ <br>
Designed a string generator using the following grammar rules: <br>
<Ε>::=(<Υ>) <br>
<Υ>::=<Α><Β> <br>
<Α>::=ν|<Ε> <br>
<Β>::=-<Υ>|+<Υ>|ε <br>

<br><br><br>
#  Project 2
Language: C++ <br>
Designed a top-down parser using the following grammar rules: <br>
S→(Χ)<br>
Χ→ΥΖ<br>
Υ→α | β | S<br>
Ζ→*Χ | -Χ |+Χ| ε <br>

<br><br><br>
#  Project 3
Language: FLEX and C++ <br>
Designed a Flex program to analyze geometric definitions in text. <br>
Points are define as a single symbol, lines are defined as pair of 2 symbols, triangle are defied as three symbols, and so on, up to octagons.<br>
This program accepts valid definitions like "triangle  ABC" and rejects invalid definitions.
