### init.vim

reload: `source $MYVIMRC`

### vim-plug

https://github.com/junegunn/vim-plug#neovim

| Command                             | Description                                                        |
| ----------------------------------- | ------------------------------------------------------------------ |
| `PlugInstall [name ...] [#threads]` | Install plugins                                                    |
| `PlugUpdate [name ...] [#threads]`  | Install or update plugins                                          |
| `PlugClean[!]`                      | Remove unlisted plugins (bang version will clean without prompt) |
| `PlugUpgrade`                       | Upgrade vim-plug itself                                            |
| `PlugStatus`                        | Check the status of plugins                                        |
| `PlugDiff`                          | Examine changes from the previous update and the pending changes   |
| `PlugSnapshot[!] [output path]`     | Generate script for restoring the current snapshot of the plugins  |

### NERDTree

* `t/T` open in tab
* `s/gs` open in vsplit
* `p/P` go parent
* `C` set root
* `u` go up
* `r` refresh
* `m` menu
* `cd` set cwd
* `:Bookmark [<name>]` set bookmark

https://github.com/preservim/nerdtree

### Auto-pairs

https://github.com/jiangmiao/auto-pairs

### NERD Commenter

https://github.com/preservim/nerdcommenter

[count]<leader>ci |NERDCommenterInvert|