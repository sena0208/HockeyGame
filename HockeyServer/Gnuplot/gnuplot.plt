#---------------
#loop
#---------------
if(exist("n") == 0 || n < 0) n = n0

#---------------
#plot
#---------------
plot "result/out.dat" index n using 1:2 ps 4 pt 2

#---------------
#update
#---------------
n = n + dn            #increse
if( n < n1) reread    #check
undefine n            #delete
