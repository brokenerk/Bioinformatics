# script for Root Mean Square Desviation (RMSD) calculation 
set outfile [open rmsd.dat w] 
set sel [atomselect top "protein"] 
set frame0 [atomselect top "protein" frame 0] 
set nf [molinfo top get numframes] 

for { set i 1 } { $i <= $nf } { incr i } { 
   $sel frame $i 
   $sel move [measure fit $sel $frame0] 
   puts $outfile "[measure rmsd $sel $frame0]" 
} 
close $outfile