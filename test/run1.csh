#!/bin/csh

    eval `scramv1 ru -csh`
    SealPluginRefresh

    rm *.xml*
    rm *.log*
   cmsRun --parameter-set runHB.cfg >& outputDigisHB.log
#   cmsRun --parameter-set runHE.cfg >& outputDigisHE.log
   cmsRun --parameter-set runHF.cfg >& outputDigisHF.log
#   cmsRun --parameter-set runHO.cfg >& outputDigisHO.log
  
   cmsRun --parameter-set runHBnoise.cfg >& outputDigisHBnoise.log
#   cmsRun --parameter-set runHEnoise.cfg >& outputDigisHEnoise.log
   cmsRun --parameter-set runHFnoise.cfg >& outputDigisHFnoise.log
#   cmsRun --parameter-set runHOnoise.cfg >& outputDigisHOnoise.log
