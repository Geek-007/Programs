#!/bin/bash
#-----------------------------------------------
#write in 2015.08.02
#Nanjing
#this script is used in ETKF assmilation 
#-----------------------------------------------

#define some env variables

       NUM_MAX=     #members of the sample
       DATE=        # formate: YYYYMMDDHH
       NPROC=8
export RUN_BASEDIR=/nuist/p/work/20131201008msy/WRFDA/worketkf/${DATE} #your working dir path 
export DAT_SRCDIR=/nuist/p/work/wxying/hybrid/members #hybrid memebers's  dir
export BE_DATDIR=/nuist/p/work/20131201008msy/hybrid/be/AMSU  # BEC path
export 
       run_info=${RUN_BASEDIR}/run.info

#--------------------------------------------------
# difine analysis time
#--------------------------------------------------
    ccyy=$(echo $DATE | cut -c1-4)
      mm=$(echo $DATE | cut -c5-6)
      dd=$(echo $DATE | cut -c7-8)
      hh=$(echo $DATE | cut -c9-10)
      
date_min=`${DA_SRCDIR}/var/da/da_advance_time.exe ${DATE} ${TIMEWINDOW1} -w`
date_max=`${DA_SRCDIR}/var/da/da_advance_time.exe ${DATE} ${TIMEWINDOW2} -w`

save_date=${ccyy}-${mm}-${dd}_${hh}
      echo ' run information file: '${RUN_BASEDIR}/wrfda_${save_date}_d${DOMAIN_ID}.log >> ${run_info}
      echo '' >> ${run_info}
      echo '' >> ${run_info}

# first step
echo "===================================">> ${run_info}
echo "Prepare the filtered observations">> ${run_info}
echo "===================================">> ${run_info}
cd ${RUN_BASEDIR}
      if [ ! -d obs_filter ];then
          mkdir -p obs_filter
      fi
      cd obs_filter
   #link some files  
   ln -fs ${DAT_SRCDIR}/wrfout_d01_2013-07-04_06:00:00.mean ./fg
   ln -fs ${DA_SRCDIR}/run/LANDUSE.TBL .
   ln -fs /nuist/p/work/20131201008msy/rain/130705/observation/AMSU/20130704.1bamua/gdas.1bamua.t06z.20130704.bufr ./amsua.bufr
   ln -fs /nuist/p/work/20131201008msy/rain/130705/observation/AMSU/20130704.1bamub/gdas.1bamub.t06z.20130704.bufr ./amsub.bufr
   ln -sf ${DA_SRCDIR}/var/run/radiance_info ./radiance_info
   ln -sf ${DA_SRCDIR}/var/run/VARBC.in ./VARBC.in
   ln -fs ${DA_SRCDIR}/var/run/crtm_coeffs ./crtm_coeffs
   ln -fs /nuist/p/work/20131201008msy/WRFDA/var/obsproc/obs_gts_2013-07-04_06:00:00.3DVAR ./ob.ascii
   ln -fs ${BE_DATDIR}/be.dat ./be.dat

less > namelist.input-initial 2>&1<< EOF
!-----------------------------------------
!---the namelist for QC-OBS
!----------------------------------------
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
! --- total sensors
         rtminit_nsensor  = 4,
         !                        --AMSUA(2)--   --AMSUB(2)--
         rtminit_platform =        1, 1,           1, 1,
         rtminit_satid    =       16,18,          16,17,
         rtminit_sensor   =        3, 3,           4, 4,
         thinning_mesh    = 120.,120.,120.,120.,
         thinning         = .true.,
         qc_rad           = .true.,
         write_iv_rad_ascii = .true.,
         write_oa_rad_ascii = .true.,
         rtm_option         = 2,             ! 1: RTTOV(v8-7 only), 2: CRTM (V1.2 and later)
         only_sea_rad       = .false.,       ! .true.: assimilate radiance over water only
         use_varbc          = .true.,
         ! freeze_varbc       = .false.,       ! together with use_varbc=.false.
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
        analysis_date="${ccyy}-${mm}-${dd}_${hh}:00:00",
        /
        &wrfvar19
        /
        &wrfvar20
        /
        &wrfvar21
        time_window_min="${date_min}",
        /
        &wrfvar22
        time_window_max="${date_max}",
        /
        &wrfvar23
        /
        &time_control
        start_year=${yyyy},
        start_month=${mm},
        start_day=${dd},
        start_hour=${hh},
        end_year=${yyyy},
        end_month=${mm},
        end_day=${dd},
        end_hour=${hh},
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
       radt=30,
       bl_pbl_physics                      = 1,
       cu_physics                          = 2, 
       bldt=0,
       cudt=0,
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

 cp namelist.input-initial namelist.input
 ln -sf ${DA_SRCDIR}/var/build/da_wrfvar.exe .
if [ $NPROC > 1 ]; then
   mpirun -n ${NPROC}  ./da_wrfvar.exe > wrfda_${DATE}.log
 else
    ./da_wrfvar.exe  > wrfda_${DATE}.log
  fi
 grep "WRF-Var completed successfully" wrfda_${DATE}.log >> ${run_info}

#return your working dir and begin second step
 
cd ../
echo "==================================="  >> ${run_info}
echo "Prepare omb files for ETKF"           >> ${run_info}
echo "===================================" >> ${run_info}

 if [ ! -d omb ];then
           mkdir -p omb
        fi
       cd omb
  
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

    if [ ! -d working.e${en_num} ];then
           mkdir -p working.e${en_num}
        fi
       cd working.e${en_num}
        ln -fs ${DAT_SRCDIR}/wrfout_d01_2013-07-04_06:00:00.e$en_num ./fg
        ln -fs ${DA_SRCDIR}/run/LANDUSE.TBL .
        ln -fs ${RUN_BASEDIR}/obs_filter/filtered_obs_01 ./ob.ascii
       #ob.ascii filtered_obs_01
        ln -fs ${BE_DATDIR}/be.dat ./be.dat

  less > namelist.input_initial << EOF
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
        ! --- total sensors
         rtminit_nsensor  = 4,
         !                        --AMSUA(2)--   --AMSUB(2)--
         rtminit_platform =        1, 1,           1, 1,
         rtminit_satid    =       16,18,          16,17,
         rtminit_sensor   =        3, 3,           4, 4,
         thinning_mesh    = 120.,120.,120.,120.,
         thinning         = .true.,
         qc_rad           = .true.,
         write_iv_rad_ascii = .true.,
         write_oa_rad_ascii = .true.,
         rtm_option         = 2,             ! 1: RTTOV(v8-7 only), 2: CRTM (V1.2 and later)
         only_sea_rad       = .false.,       ! .true.: assimilate radiance over water only
         use_varbc          = .true.,
         ! freeze_varbc       = .false.,       ! together with use_varbc=.false.
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
        analysis_date="${ccyy}-${mm}-${dd}_${hh}:00:00",
        /
        &wrfvar19
        /
        &wrfvar20
        /
        &wrfvar21
        time_window_min="${date_min}",
        /
        &wrfvar22
        time_window_max="${date_max}",
        /
        &wrfvar23
        /
        &time_control
        start_year=${yyyy},
        start_month=${mm},
        start_day=${dd},
        start_hour=${hh},
        end_year=${yyyy},
        end_month=${mm},
        end_day=${dd},
        end_hour=${hh},
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
       radt=30,
       bl_pbl_physics                      = 1,
       cu_physics                          = 2, 
       bldt=0,
       cudt=0,
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

 cp namelist.input-initial namelist.input
 ln -fs ${DA_SRCDIR}/var/build/da_wrfvar.exe .
    if [ $NPROC > 1 ]; then
   mpirun -n ${NPROC}  ./da_wrfvar.exe > wrfda_${DATE}.log
   else
    ./da_wrfvar.exe  > wrfda_${DATE}.log
   fi
   grep "WRF-Var completed successfully" wrfda_${DATE}.log >> ${run_info}
        cat ob.etkf.0* > ob.all
        wc -l ob.all > ob.etkf.e${en_num}
        cat ob.all >> ob.etkf.e${en_num}
 cd ..
        num=`expr ${num} + 1`
done

#return your working dir and start third step

echo "==================================="
echo "Run ETKF"
echo "==================================="

if [ ! -d etkf_run ];then
           mkdir -p etkf_run
        fi
       cd etkf_run
   num=1
     while [ $num -le $num_max ]
       do

        if [$ num -ge 1 -a  $num -le 9  ]; then
        en_num="00$num"
        elif [ $num -ge 10 -a  $num -le 99  ]; then
        en_num="0$num"
        else
        en_num=$num
        fi

        ln -sf ${DAT_SRCDIR}/wrfout_d01_2013-07-04_06:00:00.e$en_num ./etkf_input.e$en_num
        ln -sf ../omb/working.e$en_num/ob.etkf.e$en_num .
        cp ${DAT_SRCDIR}/wrfout_d01_2013-07-04_06:00:00.e$en_num ./etkf_output.e$en_num

        num=`expr $num + 1`
done

less > gen_be_etkf_nl.nl_initial 2>&1<< EOF
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
   infl_fac_file = '${RUN_BASEDIR}/etkf_run/param/inflation_factor.dat',
   infl_let_file = '${RUN_BASEDIR}/etkf_run/param/inflation_letkf.dat',
   eigen_val_file = '${RUN_BASEDIR}/etkf_run/param/eigen_value.dat',
  inno2_val_file = '${RUN_BASEDIR}/etkf_run/param/innovation_value.dat',
  proj2_val_file = '${RUN_BASEDIR}/etkf_run/param/projection_value.dat',
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
cp gen_be_etkf_nl.nl_initial gen_be_etkf_nl.nl
ln -sf ${DA_SRCDIR}/var/build/gen_be_etkf.exe .
./gen_be_etkf.exe  >& gen_be_etkf.log 2>&1

#return working dir and start fourth step
echo "==================================="
echo "Add updated ensemble perturbations to the ensemble mean to get new emsemble members"
echo "==================================="
#mkdir add_mean

#cd add_mean

ln -sf  ${DA_SRCDIR}/var/build/gen_be_addmean.exe .

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

less > add_mean_nl.nl_initial 2>&1<< EOF  
        &add_mean_nl
        num_members = ${NUM_MAX}
        cv          = 'U', 'V', 'W', 'PH', 'T', 'QVAPOR', 'MU'
        nv          = 7
        path        = '../etkf_run'
        file_mean   = 'etkf_input' 
        file_pert   = 'etkf_output.e$en_num' 
        /

EOF

       cp add_mean_nl.nl_initial add_mean_nl.nl 

       ./gen_be_addmean.exe

        num=`expr $num + 1`
done

 date +'   ---> '%Y-%m-%d_%H:%M:%S  >> ${run_info}
      echo '' >> ${run_info}
      echo '============================================================' >> ${run_info}
      echo '' >> ${run_info}
      echo '' >> ${run_info}

