##eg: ./etkf.sh 40 2013070406

#!/bin/ksh
##PBS -N etkf          
##PBS -q Bigcpu          
##PBS -l nodes=2:ppn=12   
##PBS -l jobtype=parallel 
##PBS -l walltime=06:00:00 
##PBS -P P000648512       
##PBS -S /bin/bash


num_max=$1
DATE=$2

cd /nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406
#DAT_DIR
export DAT_DIR=/nuist/p/work/20131201008msy/hybrid/fc/2013070406
export WRFDA_DIR=/nuist/p/work/20131201008msy/WRFDA
export WORK_DIR_ETKF=/nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406

cp /nuist/p/work/20131201008msy/WRFDA/var/da/da_advance_time.exe ./
  YYYY=`echo $DATE | cut -c1-4`
    MM=`echo $DATE | cut -c5-6`
    DD=`echo $DATE | cut -c7-8`
    HH=`echo $DATE | cut -c9-10`

DATE1=`./da_advance_time.exe $DATE -3h`
DATE2=`./da_advance_time.exe $DATE +3h`
  YYYY1=`echo $DATE1 | cut -c1-4`
    MM1=`echo $DATE1 | cut -c5-6`
    DD1=`echo $DATE1 | cut -c7-8`
    HH1=`echo $DATE1 | cut -c9-10`
  YYYY2=`echo $DATE2 | cut -c1-4`
    MM2=`echo $DATE2 | cut -c5-6`
    DD2=`echo $DATE2 | cut -c7-8`
    HH2=`echo $DATE2 | cut -c9-10`

an_time=${YYYY}-${MM}-${DD}_${HH}:00:00.0000
min_time=${YYYY1}-${MM1}-${DD1}_${HH1}:00:00.0000
max_time=${YYYY2}-${MM2}-${DD2}_${HH2}:00:00.0000



echo "==================================="
echo "Prepare the filtered observations"
echo "==================================="
#-------
 if [ ! -d ${obs_filter} ];then
           mkdir -p ${obs_filter}
        fi
cd ${obs_filter}
ln -fs $DAT_DIR/wrfout_d01_2013-07-04_06:00:00.mean ./fg
ln -fs $WRFDA_DIR/run/LANDUSE.TBL .
ln -fs /nuist/p/work/20131201008msy/rain/130705/observation/AMSU/20130704.1bamua/gdas.1bamua.t06z.20130704.bufr ./amsua.bufr
ln -fs /nuist/p/work/20131201008msy/rain/130705/observation/AMSU/20130704.1bamub/gdas.1bamub.t06z.20130704.bufr ./amsub.bufr
ln -fs $WRFDA_DIR/var/run/radiance_info ./radiance_info
ln -fs $WRFDA_DIR/var/run/VARBC.in ./VARBC.in
ln -fs $WRFDA_DIR/var/run/crtm_coeffs ./crtm_coeffs
ln -fs /nuist/p/work/20131201008msy/WRFDA/var/obsproc/obs_gts_2013-07-04_06:00:00.3DVAR ./ob.ascii
ln -fs /nuist/p/work/20131201008msy/hybrid/be/AMSU/be.dat ./be.dat
ln -fs $WRFDA_DIR/var/build/da_wrfvar.exe .
	cat >  namelist.input <<EOF
	&wrfvar1
        write_increments=true
	print_detail_grad=false
	/
	&wrfvar2
	CALC_W_INCREMENT = T
        /
	&wrfvar3
	ob_format=2,
        /
	&wrfvar4
	 USE_AMSUAOBS = .true.,
         USE_AMSUBOBS = .true.,
         USE_HIRS3OBS = .false.,
         USE_HIRS4OBS = .false.,
         USE_MHSOBS   = .false.,
         USE_AIRSOBS  = .false.
         USE_SATEMOBS=true
         use_synopobs=true
         use_metarobs=true
         use_geoamvobs=true
         use_soundobs=true
         use_shipsobs=true
         use_pilotobs=true
         use_buoyobs=true
         use_profilerobs=true
         use_qscatobs=true
         use_airepobs=true
         /
	&wrfvar5
	check_max_iv=true
	/
	&wrfvar6
	max_ext_its=1
	ntmax=200
	/
	&wrfvar7
	cv_options=5
        /
	&wrfvar8
	/
	&wrfvar9
	
	/
	&wrfvar10
	/
	&wrfvar11
	CALCULATE_CG_COST_FN=true
	SFC_ASSI_OPTIONS=1
	/
	&wrfvar12
	/
	&wrfvar13
	/
	&wrfvar14
         
         rtminit_nsensor  = 4,
                                 
         rtminit_platform =        1, 1,           1, 1,
         rtminit_satid    =       16,18,          16,17,
         rtminit_sensor   =        3, 3,           4, 4,
         thinning_mesh    = 120.,120.,120.,120.,
         thinning         = .true.,
         qc_rad           = .true.,
         write_iv_rad_ascii = .true.,
         write_oa_rad_ascii = .true.,
         rtm_option         = 2,             
         only_sea_rad       = .false.,       
         use_varbc          = .true.,
         freeze_varbc       = .false.,       
         use_crtm_kmatrix = .true.,

	/
	&wrfvar15
	/
	&wrfvar16
	/
	&wrfvar17
	analysis_type                       = 'QC-OBS',
	/
	&wrfvar18
	analysis_date="$an_time",
	/
	&wrfvar19
	/
	&wrfvar20
	/
	&wrfvar21
	time_window_min="$min_time",
	/
	&wrfvar22
	time_window_max="$max_time",
	/
	&wrfvar23
	/
	&time_control
	start_year=$YYYY,
	start_month=$MM,
	start_day=$DD,
	start_hour=$HH,
	end_year=$YYYY,
	end_month=$MM,
	end_day=$DD,
	end_hour=$HH,
	/
	&dfi_control
	/
	&domains
        time_step=180,
        e_we=163,
        e_sn=116,
        e_vert=30,
        dx=30000,
        dy=30000,
        /
  &physics
  mp_physics                          = 2,     
 ra_lw_physics                       = 1,     
 ra_sw_physics                       = 1,     
 radt                                = 30,    
 sf_sfclay_physics                   = 1,     
 sf_surface_physics                  = 2,     
 bl_pbl_physics                      = 1,     
 cu_physics                          = 2,     
 bldt                                = 0,     

 cudt                                = 0,     
 isfflx                              = 1,
 ifsnow                              = 1,
 icloud                              = 1,
 surface_input_source                = 1,
 num_soil_layers                     = 4,
 sf_urban_physics                    = 1,     
 /
&fdda
/
&dynamics
 w_damping                           = 0,
 diff_opt                            = 1,
 km_opt                              = 4,
 diff_6th_opt                        = 0,      
 diff_6th_factor                     = 0.12,   
 base_temp                           = 290.,
 damp_opt                            = 0,
 zdamp                               = 5000.,  
 dampcoef                            = 0.2,    
 khdif                               = 0,      
 kvdif                               = 0,      
 non_hydrostatic                     = .true., 
 moist_adv_opt                       = 1,      
 scalar_adv_opt                      = 1,      
/
&bdy_control
spec_bdy_width                      = 5,
 spec_zone                           = 1,
 relax_zone                          = 4,
 specified                           = .true., 
 nested                              = .false., 
/
&grib2
/
&namelist_quilt
/

EOF
./da_wrfvar.exe >& wrfda.log
cd $WORK_DIR_ETKF



echo "==================================="
echo "Prepare omb files for ETKF"
echo "==================================="

 if [ ! -d ${omb} ];then
           mkdir -p ${omb}
        fi
cd ${omb}

num=1
while [ $num -le $num_max ]
do

	if [ $num -ge 1 -a  $num -le 9  ]; then 
	en_num="00$num"
	elif [ $num -ge 10 -a  $num -le 99  ]; then
	en_num="0$num"
	else
	en_num=$num
	fi
	
	 if [ ! -d working.e{$en_num} ];then
           mkdir -p working.e{$en_num}
        fi
	cd working.e{$en_num}
	ln -fs $DAT_DIR/wrfout_d01_2013-07-04_06:00:00.e$en_num ./fg
	ln -fs $WRFDA_DIR/run/LANDUSE.TBL .
	ln -fs /nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406/obs_filter/filtered_obs_01 ./ob.ascii   
       #ob.ascii filtered_obs_01
	ln -fs /nuist/p/work/20131201008msy/hybrid/be/AMSU/be.dat ./be.dat
	ln -fs $WRFDA_DIR/var/build/da_wrfvar.exe .

	cat >  namelist.input <<EOF
	&wrfvar1
        write_increments=true
	print_detail_grad=false
	/
	&wrfvar2
	CALC_W_INCREMENT = true
        /
	&wrfvar3
	ob_format=2
	/
	&wrfvar4
	USE_AMSUAOBS = .true.,
         USE_AMSUBOBS = .true.,
         USE_HIRS3OBS = .false.,
         USE_HIRS4OBS = .false.,
         USE_MHSOBS   = .false.,
         USE_AIRSOBS  = .false.
         USE_SATEMOBS=true
         use_synopobs=true
         use_metarobs=true
         use_geoamvobs=true
         use_soundobs=true
         use_shipsobs=true
         use_pilotobs=true
         use_buoyobs=true
         use_profilerobs=true
         use_qscatobs=true
         use_airepobs=true
        /
	&wrfvar5
	check_max_iv=true
	/
	&wrfvar6
	max_ext_its=1
	ntmax=100
	/
	&wrfvar7
	cv_options=5
        /
	&wrfvar8
	/
	&wrfvar9
	
	/
	&wrfvar10
	/
	&wrfvar11
	CALCULATE_CG_COST_FN=true
	SFC_ASSI_OPTIONS=1
	/
	&wrfvar12
	/
	&wrfvar13
	/
	&wrfvar14
        
         rtminit_nsensor  = 4,
                                 
         rtminit_platform =        1, 1,           1, 1,
         rtminit_satid    =       16,18,          16,17,
         rtminit_sensor   =        3, 3,           4, 4,
         thinning_mesh    = 120.,120.,120.,120.,
         thinning         = .true.,
         qc_rad           = .true.,
         write_iv_rad_ascii = .true.,
         write_oa_rad_ascii = .true.,
         rtm_option         = 2,             
         only_sea_rad       = .false.,       
         use_varbc          = .true.,
         freeze_varbc       = .false.,       
         use_crtm_kmatrix = .true.,
	/
	&wrfvar15
	/
	&wrfvar16
	/
	&wrfvar17
	analysis_type                       = 'VERIFY',
	/
	&wrfvar18
	analysis_date="$an_time",
	/
	&wrfvar19
	/
	&wrfvar20
	/
	&wrfvar21
	time_window_min="$min_time",
	/
	&wrfvar22
	time_window_max="$max_time",
	/
	&wrfvar23
	/
	&time_control
	start_year=$YYYY,
	start_month=$MM,
	start_day=$DD,
	start_hour=$HH,
	end_year=$YYYY,
	end_month=$MM,
	end_day=$DD,
	end_hour=$HH,
	/
	&dfi_control
	/
	&domains
time_step=180,
e_we=163,
e_sn=116,
e_vert=30,
dx=30000,
dy=30000,
/
&physics
mp_physics                          = 2,    
 ra_lw_physics                       = 1,     
 ra_sw_physics                       = 1,     
 radt                                = 30,    
 sf_sfclay_physics                   = 1,     
 sf_surface_physics                  = 2,     
 bl_pbl_physics                      = 1,     
 cu_physics                          = 2,     
 bldt                                = 0,     

 cudt                                = 0,     
 isfflx                              = 1,
 ifsnow                              = 1,
 icloud                              = 1,
 surface_input_source                = 1,
 num_soil_layers                     = 4,
 sf_urban_physics                    = 1,  
/
&fdda
/
&dynamics
 w_damping                           = 0,
 diff_opt                            = 1,
 km_opt                              = 4,
 diff_6th_opt                        = 0,      
 diff_6th_factor                     = 0.12,   
 base_temp                           = 290.,
 damp_opt                            = 0,
 zdamp                               = 5000.,  
 dampcoef                            = 0.2,    
 khdif                               = 0,      
 kvdif                               = 0,      
 non_hydrostatic                     = .true., 
 moist_adv_opt                       = 1,      
 scalar_adv_opt                      = 1,

/
&bdy_control
/
&grib2
/
&namelist_quilt
/


EOF

	./da_wrfvar.exe >& wrfda_2.log

	cat ob.etkf.0* > ob.all
	wc -l ob.all > ob.etkf.e$en_num
	cat ob.all >> ob.etkf.e$en_num

	cd ..
	num=`expr $num + 1`
done

cd $WORK_DIR_ETKF



echo "==================================="
echo "Run ETKF"
echo "==================================="
if [ ! -d {etkf_run} ];then
           mkdir -p ${etkf_run}
        fi
cd ${etkf_run}
ln -sf $DAT_DIR/wrfout_d01_2013-07-04_06:00:00.mean ./etkf_input

num=1
while [ $num -le $num_max ]
do

	if [ $num -ge 1 -a  $num -le 9  ]; then 
	en_num="00$num"
	elif [ $num -ge 10 -a  $num -le 99  ]; then
	en_num="0$num"
	else
	en_num=$num
	fi

	ln -sf $DAT_DIR/wrfout_d01_2013-07-04_06:00:00.e$en_num ./etkf_input.e$en_num
	ln -sf ../omb/working.e$en_num/ob.etkf.e$en_num .
	cp $DAT_DIR/wrfout_d01_2013-07-04_06:00:00.e$en_num ./etkf_output.e$en_num
	
	num=`expr $num + 1`
done

cat > gen_be_etkf_nl.nl <<EOF
  &gen_be_etkf_nl
    num_members = $1,
    nv = 7,
    cv = 'U', 'V', 'W', 'PH', 'T', 'QVAPOR', 'MU',
    naccumt1 = 20,
    naccumt2 = 20,
    nstartaccum1 = 0,
    nstartaccum2 = 0,
    nout = 1,
    tainflatinput = 100,
    rhoinput = 0.5,
   infl_fac_file = '/nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406/etkf_run/param/inflation_factor.dat',
   infl_let_file = '/nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406/etkf_run/param/inflation_letkf.dat',
   eigen_val_file = '/nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406/etkf_run/param/eigen_value.dat',
  inno2_val_file = '/nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406/etkf_run/param/innovation_value.dat',
  proj2_val_file = '/nuist/p/work/20131201008msy/WRFDA/worketkf/2013070406/etkf_run/param/projection_value.dat',
    infl_fac_TRNK = .false.,
    infl_fac_WG03 = .true.,
    infl_fac_WG07 = .false.,
    infl_fac_BOWL = .false.,
    letkf_flg=.false.,
    rand_filt = .false.,
    rnd_seed = 2013070406,
    rnd_nobs = 5000
    etkf_erro_max = 20.
    etkf_erro_min = .00001
    etkf_inno_max = 20.
    etkf_inno_min = .00001
    etkf_erro_flg = .true.
    etkf_inno_flg = .true.
    etkf_wrfda = .false.
/
EOF


ln -sf $WRFDA_DIR/var/build/gen_be_etkf.exe .
./gen_be_etkf.exe  >& gen_be_etkf.log 2>&1

#cd ..



echo "==================================="
echo "Add updated ensemble perturbations to the ensemble mean to get new emsemble members"
echo "==================================="
#mkdir add_mean
#cd add_mean
ln -sf  $WRFDA_DIR/var/build/gen_be_addmean.exe .

num=1
while [ $num -le $num_max ]
do

	if [ $num -ge 1 -a  $num -le 9  ]; then 
	en_num="00$num"
	elif [ $num -ge 10 -a  $num -le 99  ]; then
	en_num="0$num"
	else
	en_num=$num
	fi

	cat > add_mean_nl.nl  <<EOF
	&add_mean_nl
	num_members = $1
	cv          = 'U', 'V', 'W', 'PH', 'T', 'QVAPOR', 'MU'
	nv          = 7
	path        = '../etkf_run'
	file_mean   = 'etkf_input' 
	file_pert   = 'etkf_output.e$en_num' 
	/

EOF

	./gen_be_addmean.exe

	num=`expr $num + 1`
done






