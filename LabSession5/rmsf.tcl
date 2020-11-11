# script for Root mean square fluctuation (RMSF) calculation 
set outfile [open rmsf.dat w] 
set sel [atomselect top "name CA"] 
set rmsf "[measure rmsf $sel first 0 last -1 step 1]" 

for {set i 0} {$i < [$sel num]} {incr i} { 
	puts $outfile "[lindex $rmsf $i]" 
} 
close $outfile 