
 set terminal png
 set output "continuous.png"
 plot "./data/core.txt", "./data/mkl.txt", "./data/oblas.txt"

 set terminal eps
 set output "continuous.eps"
 plot "./data/core.txt", "./data/mkl.txt", "./data/oblas.txt"


 core(n) = sprintf("data/core_step%d00.txt", n)
 mkl(n) = sprintf("data/mkl_step%d00.txt", n)
 oblas(n) = sprintf("data/oblas_step%d00.txt", n)

 set style fill solid 0.25 border -1
 set style boxplot outliers pointtype 0
 set style data boxplot
 set terminal png
 set output "step.png"
 set yrange[0:0.004]
 set xtics('100' 1, '200' 2, '300' 3, '400' 4, '500' 5, '600' 6, '700' 7, '800' 8)

 plot for [i=1:8] core(i) using(i):1 notitle, \
      for [i=1:8] mkl(i) using(i):1 notitle, \
      for [i=1:8] oblas(i) using(i):1 notitle
 
 set style fill solid 0.25 border -1
 set style boxplot outliers pointtype 0
 set style data boxplot
 set terminal eps
 set output "step.eps"
 set yrange[0:0.004]
 set xtics('100' 1, '200' 2, '300' 3, '400' 4, '500' 5, '600' 6, '700' 7, '800' 8)

 plot for [i=1:8] core(i) using(i):1 notitle, \
        for [i=1:8] mkl(i) using(i):1 notitle, \
        for [i=1:8] oblas(i) using(i):1 notitle
