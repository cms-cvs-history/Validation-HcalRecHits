#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh
        
    rm *.xml*
    if ( -e outputRecHitsHB.log ) rm outputRecHitsHB.log 
    if ( -e outputRecHitsHE.log ) rm outputRecHitsHE.log
    if ( -e outputRecHitsHF.log ) rm outputRecHitsHF.log 
    if ( -e outputRecHitsHO.log ) rm outputRecHitsHO.log 

    if ( -e outputRecHitsHF_gamma.log ) rm outputRecHitsHF_gamma.log 
    if ( -e outputRecHits_noise.log )   rm outputRecHits_noise.log 
    if ( -e outputRecHitsALL.log )      rm outputRecHitsALL.log 

    cmsRun --parameter-set run_HB.cfg >& outputRecHitsHB.log &
    cmsRun --parameter-set run_HE.cfg >& outputRecHitsHE.log &
    cmsRun --parameter-set run_HF.cfg >& outputRecHitsHF.log &
    cmsRun --parameter-set run_HO.cfg >& outputRecHitsHO.log &

    cmsRun --parameter-set run_HF_gamma.cfg >& outputRecHitsHF_gamma.log &
    cmsRun --parameter-set run_noise.cfg    >& outputRecHits_noise.log &
    cmsRun --parameter-set run_ALL.cfg      >& outputRecHitsALL.log &
