#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh
        
    rm *.xml*
    if ( -e outputRecHitsHBnoise.log ) rm outputRecHitsHBnoise.log
    if ( -e outputRecHitsHB.log ) rm outputRecHitsHB.log 

    if ( -e outputRecHitsHEnoise.log ) rm outputRecHitsHEnoise.log
    if ( -e outputRecHitsHE.log ) rm outputRecHitsHE.log

    if ( -e outputRecHitsHFnoise.log ) rm outputRecHitsHFnoise.log
    if ( -e outputRecHitsHF.log ) rm outputRecHitsHF.log 

    if ( -e outputRecHitsHOnoise.log ) rm outputRecHitsHOnoise.log
    if ( -e outputRecHitsHO.log ) rm outputRecHitsHO.log 


    cmsRun --parameter-set runHB.cfg >& outputRecHitsHB.log
    cmsRun --parameter-set runHBnoise.cfg >& outputRecHitsHBnoise.log

    cmsRun --parameter-set runHE.cfg >& outputRecHitsHE.log
    cmsRun --parameter-set runHEnoise.cfg >& outputRecHitsHEnoise.log


    cmsRun --parameter-set runHF.cfg >& outputRecHitsHF.log
    cmsRun --parameter-set runHFnoise.cfg >& outputRecHitsHFnoise.log

    cmsRun --parameter-set runHO.cfg >& outputRecHitsHO.log
    cmsRun --parameter-set runHOnoise.cfg >& outputRecHitsHOnoise.log
