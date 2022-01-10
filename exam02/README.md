```
2
Assignment name  : inter
3
Expected files   : inter.c
4
Allowed functions: write
5
--------------------------------------------------------------------------------
6
7
Write a program that takes two strings and displays, without doubles, the
8
characters that appear in both strings, in the order they appear in the first
9
one.
10
11
The display will be followed by a \n.
12
13
If the number of arguments is not 2, the program displays \n.
14
15
Examples:
16
17
$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
18
padinto$
19
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
20
df6ewg4$
21
$>./inter "nothing" "This sentence hides nothing" | cat -e
22
nothig$
23
$>./inter | cat -e
24
$
25
```
26

27
```text
28
Assignment name  : union
29
Expected files   : union.c
30
Allowed functions: write
31
--------------------------------------------------------------------------------
32
33
Write a program that takes two strings and displays, without doubles, the
34
characters that appear in either one of the strings.
35
36
The display will be in the order characters appear in the command line, and
37
will be followed by a \n.
38
39
If the number of arguments is not 2, the program displays \n.
40
41
Example:
42
43
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
44
zpadintoqefwjy$
45
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
46
df6vewg4thras$
47
$>./union "rien" "cette phrase ne cache rien" | cat -e
48
rienct phas$
49
$>./union | cat -e
50
$
51
$>
52
$>./union "rien" | cat -e
53
$
54
$>
55
```
