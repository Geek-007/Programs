#!/usr/bin/perl

open(FILE,"./WRFV3/phys/module_mp_sbu_ylin.F");
while(<FILE>) {
	push(@tmp, $_);
	if ($_ =~ /\sREAL, DIMENSION\( its:ite , jts:jte \) /) {
		push(@tmp, "ffffffffffff\n")
	}
}
open myfile, ">./tmp" or die $!;
print myfile @tmp;
