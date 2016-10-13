set terminal postscript "Helvetica" 25
set size square
set output "layer2_vs_bddbasedlayer2_conjunctions.eps"
set xlabel "Layer2 Time"
set ylabel "BDDBasedLayer2 Time"
set logscale x
set logscale y
set xrange[1:10000000]
set yrange[1:10000000]
set xtics 1,100,1e7
set ytics 1,100,1e7
plot 'layer2_vs_bddbasedlayer2_conjunctions.txt' u ($2+1):($3+1) notitle with points pt 9 lc 1 ps 2
replot 'line2.txt' notitle with linespoints lt -1
quit
