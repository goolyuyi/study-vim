## ESSENTIAL

### motion

motion is cursor move

1. basic:

* move: `hjkl` or `<arrow>`
* word: `w`: next word head `e` word tail, `b`: last word head or `shift+<arrow>`
* line: `^/$`: start/end of line `0`: start of line
* `%`: match pair of `()` `[]` `{}` `<>`
* move in file: `gg` top `G` bottom
* `5gg` or `5G` jump to line 5
* `ctrl+b/f` (back/fore) full screen scroll OR `shift+<arrow>`
* `ctrl+u/d` (up/down) 1/2 screen scroll
* `{}` jump paragraph
* `50%` goto 50% of file

2.advanced

* `H` `M` `L`: scroll to top/middle/bottom of the screen
* `fx` - jump to next occurrence of character x `Fx` backward
* `tx` - jump to before next occurrence of character x `Tx` backward
* `;` repeat previous f, t, F or T movement
* `,` repeat previous f, t, F or T movement, backwards

3. **Note** : all motion can spec a quantity like `d3w`,`9<down>`

### navi

move won't change the cursor position

* `zz` frame cursor

* `ctrl-o`: navi back(out) `ctrl-i`: navi fore(in)
* `ctrl-]`: enter

### verb

some verb need a `motion`: `dw`=`d`+`w`

verb can have a quantity like `3x` `9dl`

1. list:

* cut/delete `d+` where `+`= `dd` `dw` `d$`=`D`, `daw` delete a word
* join line `J`
* delete at cursor: `x`
* copy/yank `y+`: `yy` `yw` `y$`
* put/paste: `p` paste after cur `P` paste before cur
* replace 1 char: `r`: `ra` replace to `a`
* undo `u`/ undo line `U` redo `ctrl-r`
* `.` repeat last change
* g-command like `gJ` see `:help g`
    * `g~~` toggle case
    * `gU` upper case `gUe` `gu` lower case `guu`
* change`c` (delete and enter insert): `cc`=`S` `cl`=`s` `c$`=`C` `caw`


2. object:

* `a+` a object, `aw` a word `as` a sentence `ab` a block`()` `aB` a block `{}`
* `i+` inner object, `iw` inner word `is` inner sentence `ib` inner block

### mode

* insert mode: `i` insert(before) `o` open(new line) `a` append(after)
    * `ea` frequently used
    * `^n` next find
    * `^j` new line 
    * `^t` tab line `^d` revert tab line `^i` insert tab
    * `^u` delete left `^w` delete left word
    * `<insert>` toggle replace mode

* replace mode: `R`

* visual mode(marking mode):
    * `v`: enter visual mode `V` enter visual line mode
    * `ctrl+v`: enter visual block mode
        * `o O`: move cursor to corner
    * `<>` shift left/right (with tab)
    * `u U ~` case
    * `y d` copy/delete

### mark

* `&grave;&grave;` goto last jump `"` last edit `.` last change
* `&grave;a` goto a
* `ma` set mark a; mark name [0-9a-z]
* `:marks` list marks `:jump` jump history `:changes` change history
* `y&grave;a` yank to a mark

### search and replace

1. search:

* regex: http://www.vimregex.com/
* `/`: search forward `?`: search backward `*/#` : search with cur word
* `n/N`: to next/previous
* search is a `verb`, can use like a verb: `d/the<Enter>`
* `//` `/?` `/&` last search
* `:s/\v(\w+)/\u\1/g` use `\v` to mimic perl regex

2. substitute:

* substitute/replace `:substitute` , mostly use `:s`
* syntax: `:[range]substitute/from/to/[flags]`
    * `:s/thee/the` default is cur line
        * `%s/thee/the`  `%` all line
    * `:s/thee/the/gc` replace all and confirm
* flag: `g` all, `c` confirm, `p` print, `i/I` case ignore

3. range:

* `1,5` line 1 to 5, `5` line 5
* `.`: cur line, `.w` write cur line
* `.,$` cur to last line `.,.+4` cur to next 4 line `%` the whole file
* `'t,'b` from mark t to mark b
* `'<,'>` visual selection, `<` is visual start, `>` is visual end
* `.,/patter` cur to next line that match pattern `.,?pattern` cur to prev line that match pattern
* `/Section 1/+,/Section 2/-` non-inclusively search for section 1 and section 2
* `/Section 1/;/Subsection/-,/Subsection/+`
* `:/Section/+ y` `:// normal p`

4. global:

* `:[range]global/{pattern}/{command}` search pattern and exec a command
    * :g+//+s/foobar/barfoo/g

5. pattern(regex):
    * `/\<the\>` `\< \>` word boundary
    * `^$` line boundary
    * `. \s \d \w \a` `\l=lower \u=upper` same as regex

6. option
    * `hlsearch`=`hls` `nohlsearch`
    * `wrapscan`
    * `incsearch`=`is`

### command

* show file info: `ctrl-g`
* quit with write: `ZZ`
* commands, start with `:`
    * `:!` shell command: `:!ls ~/dev`
    * `:set` set var
        * `:set ic`=`set ignorecase`
        * `:set history=1000` set value, `:set history` get value
        * `:set iskeyword&` set to default value
    * `:options` show options
    * `<ctrl-d>/<tab>` auto complete

### completion


### file\[s\]

1.file

* `:file a.txt` change file name
* `:r` read and merge in `:r !ls` read the stdout of ls
* `:w` write file: `:w README.md` `:write >> logfile` append
* `:saveas` `:edit`

2.multi file

* `:ls`
* `:args` `:args FILES`
* `:next` `:prev` `first` `:last`
* quick jump, to last `<ctrl+^>`

### multi-window

1. basic

    * split window `:split` `:split a.txt` `:new`
        * `:3split alpha.c` window size is 3 line
    * window commands: `:close` `:only`
    * command all `qall` `wall` `wqall`


2. `ctrl-w`: input window command
    * `w`: jump window `q`: close window
    * `<arrow>` move window
    * `+/-`: window size
    * `s` `v` split `H` `J` resplit
    * `x` exchange
    * `<arrow>`: move window
    * `f` Split current window in two.  Edit file name under cursor.
        * `d` goto definition
        
4. vsplit: `:vsplit` `:vnew`
5. tab:

* `:tabnew` `:tabedit` `:tabclose` `:tabonly` `:tabmove` `:tabnext` `:tabprevious`
* `gt` `gT` jump tab `5gt` jump tab 5 
* `ctrl-w gf`:Open a new tab page and edit the file name under the cursor.

* options:
    * `winheight`

### macro, register

1. register(think as named clipboard)

* `:reg` show; reg name is `[0-9a-z]`
* `"xy` yank to x `"xp` put from x;
    * use uppercase for append mode: `"Xy` append to x
    * `+ $` is clipboard: `"+y` yank to system clipboard
    * register cross session; stored in ` ~/.viminfo`

* in insert mode:
    * `^r` insert register

```
Tip Special registers:
0 - last yank
" - unnamed register, last delete or yank
% - current file name
# - alternate file name
* - clipboard contents (X11 primary)
+ - clipboard contents (X11 clipboard)
/ - last search pattern
: - last command-line
. - last inserted text
- - last small (less than a line) delete
= - expression register
_ - black hole register
```

2. macro
    * macro is the same thing as reg ,stored in `reg`
    * `qa` start recode macro a `q` stop
    * `@a` play macro a `@@` repeat last macro
        * `qA/word<Enter>q` append to macro a
    * `.` repeat last change

### indent

* `>>` `<<`
* `>%` indent block `>ib` inner block `>at` tag
* `==` indent current line `=$` indent all `=%` indent to block
* `]p` paste and indent

### format

* `gq+`, `help gq`
* `gqap`: `gq` format `ap` a paragraph
* `gggqG`: `gg` go file start `gq` format `G` end of file

### help

    * `:help`: show help
    * `:help w` `help ctrl-d`: show help of `command`s

## CUSTOM

### vimrc

put `init.vim` here

```
~/.config/nvim/init.vim         (Unix and OSX)
~/AppData/Local/nvim/init.vim   (Windows)
```

### useful option

```
set backup
set backupext=.bak
set patchmode=.orig
```

```
set backspace=indent,eol,start
set autoindent
set history=50
set ruler
set showcmd
set incsearch
set hlsearch
set sidescroll=10
set whichwrap=b,s
set list                      # show tab symbol
set listchars=tab:>-,trail:-  # set tab style
```

```
autowrite
```

```
syntax on
```

### color

* `$VIMRUNTIME/colors` path of theme
* `:colorscheme evening`
*

### keymapping

like shortcut or macro

```
:map <F5> i{<Esc>ea}<Esc>
```

press `F5`

```
:map \p i(<Esc>ea)<Esc>
:map \c i{<Esc>ea}<Esc>
```

press `\ + p` quickly

## PLUGIN SYS

There are two types of plugins:
>
>* global plugin: Used for all kinds of files
>* filetype plugin: Only used for a specific type of file
>
`~/.vimrc`

### package

* package and plugin are basically the same thing
* `packadd vimball` load package
    * `mkdir -p ~/.local/share/nvim/site/pack/fancy` put the package here

### plugin

* There are two types of plugins:
    * global plugin: Used for all kinds of files
    * filetype plugin: Only used for a specific type of file

* `help standard-plugin-list`
* `$VIMRUNTIME/plugin` `$VIMRUNTIME/macros` system plugin path
* `~/.local/share/nvim/site/plugin` user plugin path

### filetype plugin

`~/.local/share/nvim/site/ftplugin` path

The generic names for the filetype plugins are:

        ftplugin/<filetype>.vim
        ftplugin/<filetype>_<name>.vim
        ftplugin/<filetype>/<name>.vim

Here `<name>` can be any name that you prefer.
Examples for the "stuff" filetype on Unix:

        ~/.local/share/nvim/site/ftplugin/stuff.vim
        ~/.local/share/nvim/site/ftplugin/stuff_def.vim
        ~/.local/share/nvim/site/ftplugin/stuff/header.vim

## FAQ

## TODO