## Essential

### motion

motion is cursor move

1. basic:

* move: `hjkl` or `<arrow>`
* word: `w/e`: next word, `b`: jump word backward or `shift+<arrow>`
* line:
    * `^/$`: start/end of line `0`: start of line
    * `??`: whole line like `dd` `cc` `yy`
* `%`: match pair of `()` `[]` `{}` `<>`

2. page

* move in file: `gg` top `G` bottom
* `5gg` or `5G` jump to line 5
* `ctrl+b/f` (back/fore) full screen scroll `ctrl+u/d` (up/down) 1/2 screen scroll
* `H` `M` `L`: scroll to top/middle/bottom of the screen
* `fx` - jump to next occurrence of character x `Fx` backward
* `tx` - jump to before next occurrence of character x `Tx` backward
* `;` repeat previous f, t, F or T movement
* `,` repeat previous f, t, F or T movement, backwards
* `{}` jump paragraph
* `50%` goto 50% of file

3. **Note** : all motion can spec a quantity like `d3w`,`9k`

### navi

move won't change the cursor position

* `zz` frame cursor

* `ctrl-o`: navi back(out) `ctrl-i`: navi fore(in)
* `ctrl-]`: enter

### mark

* `&grave;&grave;` goto last jump `"` last edit `.` last change
* `&grave;a` goto a
* `ma` set mark a; mark name [0-9a-z]
* `:marks` list marks `:jump` jump history `:changes` change history
* `y&grave;a` yank to a
*

### verb

some verb need a `motion`: `dw`=`d`+`w`

verb can have a quantity like `3x` `9dl`

1. list:

* cut/delete `d+`: `dd` `dw` `d$`=`D`, `daw` delete a word
* change`c` (delete and enter insert): `cc`=`S` `cl`=`s` `c$`=`C` `caw`
* join line `J`
* delete at cursor: `x`
* copy/yank `y+`: `yy` `yw` `y$`
* put/paste: `p` paste after cur `P` paste before cur
* replace 1 char: `r`: `ra` replace to `a`
* undo `u`/ undo line `U` redo `ctrl-r`
* `.` repeat last change
* g-command like `gj` see `:help g`
    * `g~~` toggle case
    * `gU` upper case `gUe` `gu` lower case `guu`

2. object:

* `a+` a object, `aw` a word `as` a sentence `ab` a block`()` `aB` a block `{}`
* `i+` inner object, `iw` inner word `is` inner sentence `ib` inner block

### mode

* insert mode: `i` insert(before) `o` open(new line) `a` append(after)
    * `ea` frequently used
    * `^j` new line `^t` tab line `^d` revert tab line
* replace mode: `R`

* visual mode(marking mode):
    * `v`: enter visual mode `V` enter visual line mode
    * `ctrl+v`: enter visual block mode
        * `o/O`: move cursor to corner
    * `<>` shift left/right (with tab)
    * `uU~` case
    * `yd` copy/delete

### search and replace

1. search:

* `/`: search forward `?`: search backward `*/#` : search with cur word
* `n/N`: to next/previous
* search is a `verb`, can use like a verb: `d/the<Enter>`

2. substitute:

* substitute/replace `:substitute` , mostly use `:s`
* syntax: `:[range]substitute/from/to/[flags]`
    * `%s/thee/the` default is cur line `%` all line
    * `:s/thee/the` search and replace
    * `:s/thee/the/gc` replace all and confirm
* flag: `g` all, `c` confirm, `p` print

3. range:

* `1,5` line 1 to 5, `5` line 5
* `.`: cur line, `.w` write cur line
* `.,$` cur to end `.,.+4` cur to next 4 line
* `'t,'b` from mark t to mark b
* `'<,'>` visual selection, `<` is visual start, `>` is visual end

4. global:

* `:[range]global/{pattern}/{command}` search pattern and exec a command
    * :g+//+s/foobar/barfoo/g

5. pattern(regex):
    * `/\<the\>` `\<` word boundary

6. option
    * `hlsearch`=`hls` `nohlsearch`
    * `wrapscan`
    * `incsearch`=`is`

### command

* show file info: `ctrl-g`
* quit with write: `ZZ`
* commands, start with `:`
    * `!` external command: `:!ls ~/dev`
    * `set` set var
        * `set ic`=`set ignorecase`
        * `set history=1000` set value, `set history` get value
        * `:set iskeyword&` set to default value
    * `options` show options
    * `<ctrl-d>/<tab>` auto complete
    * `file a.txt` change file name
    * `w` write file: `:w README.md` `:write >> logfile` append
    * `r` read and merge in `r !ls` read the stdout of `ls`

### multifile

* `:next` `:prev` `first` `:last`
* `:args` `:args FILES`
* `:ls`
* quick jump, to last `<ctrl+^>`

### multi-window

1. basic

* split window `:split` `:split a.txt` `:new`
    * `:3split alpha.c` window size is 3 line
* window commands: `:close` `:only`
* command all `qall` `wall` `wqall`
* `ctrl-w`: input window command
    * `w`: jump window `q`: close window
    * `+/-`: window size
    * `s` `v` split `H` `J` resplit
    * `x` exchange
    * `<arrow>`: move window

2. vsplit: `:vsplit` `:vnew`
3. tab:

* `:tabnew` `:tabedit` `:tabclose` `:tabonly` `:tabmove` `:tabnext` `:tabprevious`
* `gt` `gT` jump tab `5gt` jump tab 5

* options:
    * `winheight`

### macro, register, repeat

1. register(think as named clipboard)

* `:reg` show; reg name is `[0-9a-z]`
* `"xy` yank to x `"xp` put from x; `"Xy` append
* `"+y` yank to system clipboard
* register cross session; stored in ` ~/.viminfo`
* `"ayy` copy line to reg a -> `"ap` paste line from reg a

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
    * `qa` start recode macro a `q` stop
    * `@a` play macro a `@@` repeat
        * `qA/word<Enter>q` append to macro a

3. repeat

* `.` repeat last change

### indent

* `>>` `<<`
* `>%` indent block `>ib` inner block `>at` tag
* `==` indent current line `=$` indent all `=%` indent to block
* `]p` paste and indent

### help

    * `:help`: show help
    * `:help w` `help ctrl-d`: show help of `command`s

## Custom

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

## Plugin

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