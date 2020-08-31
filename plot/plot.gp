reset
set xlabel 'node #'
set ylabel 'time(s)'
set terminal png font " Times_New_Roman,12 "
set output 'runtime.png'


plot \
"fast.txt" using 1:2 with linespoints linewidth 2 title "New", \
"slow.txt" using 1:2 with linespoints linewidth 2 title "Old", \
