echo "ibase=5;obase=23;"$(echo "$FT_NBR1+$FT_NBR2" | tr mrdoc 01234 | tr "'\\" "01" | tr '\"?!' '234') | bc | tr 01234 gtaio | tr '0123456789ABC' 'gtaio luSnemf'
