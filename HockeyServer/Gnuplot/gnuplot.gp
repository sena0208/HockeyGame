#gnuplot setting
#-------------------
reset
set term x11 enhanced
set nokey
set xrange [-10:10]
set yrange [-10:10]
set xtics 1
set ytics 1
set size square
set arrow from -4.0,-6.0 to -4.0, 6.0 nohead
set arrow from -4.0,-6.0 to  4.0,-6.0 nohead
set arrow from  4.0, 6.0 to  4.0,-6.0 nohead
set arrow from  4.0, 6.0 to -4.0, 6.0 nohead

set term gif animate
set output "result/play.gif"

#------------------
#set value
#------------------

n0 = 1
n1 = 200
dn = 1

#-----------------
#loop
#----------------
load "Gnuplot/gnuplot.plt"
