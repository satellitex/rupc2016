#! /bin/bash
# Usage:
# convert.sh
# remove all CRLF line terminators
for filename in input*.txt output*.txt
do
    mv $filename $filename.crlf
    tr -d "\r" < $filename.crlf > $filename
    rm $filename.crlf
    chmod 644 $filename
done
    
