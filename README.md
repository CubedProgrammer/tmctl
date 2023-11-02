# Terminal Control
Move the caret around in your terminal.

## Compilation
```
clang -std=c99 -O3 -c fmt.c interactive.c mvmnt.c tmctl.c
clang -o tmctl fmt.o interactive.o mvmnt.o tmctl.o
```
## Installation
To install, move the generted executable to a directory in your PATH, such as /usr/local/bin.

Alternatively, if you have bash, you can run ./cmpl.sh, then ./install.sh.

Helpful shell aliases
```
alias up='tmctl u'
alias down='tmctl d'
alias right='tmctl h'
alias left='tmctl l'
alias nxtln='tmctl n'
alias prvln='tmctl p'
alias setpos='tmctl s'
```
## Usage
Each command-line argument can be either commands or values.
Commands can be grouped together in the same argument.

```
. to reset all text formatting, text formatting is set back to normal.
I to start interactive mode, press q to quit. Must be lowercase q.
o to bold
f to faint.
i to italic.
e to underline.
t to cross out or strikethrough.
v to overline.
k to set foreground to black.
r to set foreground to red.
g to set foreground to green.
y to set foreground to yellow.
b to set foreground to blue.
m to set foreground to magenta.
c to set foreground to cyan.
w to set foreground to white.
F to set foreground to default.
a to set foreground to true colour, all colours are available, argument must be hexadecimal value for the colour.
K to set background to black.
R to set background to red.
G to set background to green.
Y to set background to yellow.
B to set background to blue.
M to set background to magenta.
C to set background to cyan.
W to set background to white.
O to set background to default.
A to set background to true colour, all colours are available, argument must be hexadecimal value for the colour.
u to move up, one value, how many lines to move.
d to move down, one value, how many lines to move.
h to move right, one value, how many characterss to move.
l to move left, one value, how many characters to move.
n to move to next lines, one value, how many lines to move.
p to move to previous lines, one value, how many lines to move.
s to set the position, top left corner is 1 1, two values, row, and column.
```
If value is not provided, relative movement commands default to 1.
True colour defaults to black background and white foreground.

Examples
```
tmctl ur 5 7
tmctl s 3 3
```
The first command moves five up and seven to the right. The second sets the position to row three and column three.
