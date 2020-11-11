# script for Solvent Accessible Surface Area (SASA) calculation 
set outfile [open sasa.dat w] 
set sel [atomselect top "protein"] 
set frame0 [atomselect top "protein" frame 0]  
set nf [molinfo top get numframes] 

for { set i 1 } { $i <= $nf } { incr i } { 
   $sel frame $i 
   $sel move [measure fit $sel $frame0] 
   puts $outfile "[measure sasa 1.4 $sel]" 
} 
close $outfile 