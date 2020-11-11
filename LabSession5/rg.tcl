# script for Radius of gyration (Rg) calculation 
set outfile [open rg.dat w] 
set sel [atomselect top "protein"] 
set frame0 [atomselect top "protein" frame 0]  
set nf [molinfo top get numframes] 

for { set i 1 } { $i <= $nf } { incr i } { 
   $sel frame $i 
   $sel move [measure fit $sel $frame0] 
   puts $outfile "[measure rgyr $sel]" 
} 
close $outfile 