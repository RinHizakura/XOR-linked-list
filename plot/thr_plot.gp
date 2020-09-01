reset
set xlabel 'thr'
set ylabel 'time(ms)'
set terminal png font " Times_New_Roman,12 "
set output 'THR.png'


plot \
"THR.txt" using 1:2 with linespoints linewidth 2 title " ", \

