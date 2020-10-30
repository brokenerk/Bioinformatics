
set tau 200

set tau0 2.4	;# autocorrelation decay time
set T0 300	;# initial temperature
set T1 0	;# first temperature reassignment
set T2 0	;# sedcond temperature reassignment
set lambda1 [expr sqrt($T1/$T0)]
set lambda2 [expr sqrt($T2/$T0)]

set y1 [expr (1 + pow($lambda1,2) + 2*pow($lambda2,2)) / 4]

set file [open harmonic.dat w]
for {set t $tau} {$t <= [expr 4*$tau]} {incr t} {
  set y2 [expr (1 + pow($lambda1,2) - 2*pow($lambda2,2)) / 4 * [expr exp(-($t-$tau)/$tau0)]]
  set y3 [expr $lambda1*$lambda2/2 * [expr exp(-abs($t-3*$tau/2)/$tau0)]]
  set y4 [expr (1 - pow($lambda1,2)) / 8 * [expr exp(-abs($t-2*$tau)/$tau0)]]
  puts $file "[expr $t+500]\t [expr $T0*($y1-$y2-$y3-$y4)]"
  }
close $file
