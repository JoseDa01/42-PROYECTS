cat /etc/passwd | sed '/^#/ d' | sed -n 'n;p' | cut -d ":" -f1 | rev | sort -r | sed -n "${FT_LINE1} , ${FT_LINE2}p" | sed "s/$/, /g" | sed '$ s/, $/./g' | tr -d "\n"
