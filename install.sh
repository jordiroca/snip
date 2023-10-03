#!/usr/bin/env bash
# -*- coding: utf-8 -*-
#
# DESCRIPTION: install Install snip, lsnip and rsnip utilities
#
# VERSION: 23.10.2
#
# AUTHOR: Jordi Roca
# CREATED: 2023/10/02
#
# GITHUB: https://github.com/jordiroca/
# WEBSITE: https://jordiroca.com
#
# LICENSE: See LICENSE file.
#

echo "Compiling snip, lsnip and rsnip utilities"
g++ snip.cpp -o snip
if [ "$?" -eq 0 ]; then
    cp snip lsnip
    cp snip rsnip
    echo "OS may ask for sudo password to copy files to /usr/local/bin/"
    sudo cp -fv snip lsnip rsnip /usr/local/bin/
    echo
fi
