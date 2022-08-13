" ---search set
" set ignorecase
set hlsearch

" ---run cmd
" !pwd

" ---ui set
" set backspace=indent,eol,start
" set autoindent
" set backup
" set history=50
" set ruler
set showcmd
set mouse=a


" ---keymap"
"map Q gq
"vnoremap _g y:exe "grep /" .. escape(@", '\\/') .. "/ *.c *.h"<CR>
" ---shortcut
" ":map \p i(<Esc>ea)<Esc>

" ---general file

" set tab display
set listchars=tab:>-,trail:-

" ---ui
" colorscheme evening

" ---global plugin
" packadd vimball
" :help vimball

" ---filetype plugin
filetype plugin on
filetype plugin indent on

" ---code set
set encoding=utf-8
set number relativenumber
syntax enable
set noswapfile
set scrolloff=7
set backspace=indent,eol,start
set autoindent
set expandtab


"---vim-plug
call plug#begin('~/.local/share/nvim/plugged')

Plug 'morhetz/gruvbox'
Plug 'preservim/nerdtree'
Plug 'jiangmiao/auto-pairs'
Plug 'preservim/nerdcommenter'
Plug 'norcalli/nvim-colorizer.lua'

call plug#end()

" --- gruvbox
set background=dark    " Setting dark mode
colorscheme gruvbox

" --- NERDTree
" https://github.com/preservim/nerdtree
nnoremap <leader>n :NERDTreeFocus<CR> " <leader>=`\`
" nnoremap <C-n> :NERDTree<CR>
nnoremap <C-t> :NERDTreeToggle<CR>
nnoremap <C-f> :NERDTreeFind<CR>

let mapleader= "," " now <leader> is ,