#!/usr/bin/perl
# -*- perl -*-

# ./rime.py clean を実行して rimeの作業ファイルを削除
# カレントディレクトリ以下の *~ や #* も削除します

system 'python rime.py clean';

print "seeking #* files\n";
system 'find . -name "\#*" -exec rm \{\} \;';

print "seeking *~ files\n";
system 'find . -name "*~" -exec rm \{\} \;';

print "seeking a.out files\n";
system 'find . -name "a.out" -exec rm \{\} \;';

exit;

