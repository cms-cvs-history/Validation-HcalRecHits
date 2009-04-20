import FWCore.ParameterSet.Config as cms

process = cms.Process("HCALRECHITSVALIDATION")
process.load("Validation.HcalRecHits.HcalRecHitsValidation_cfi")
process.load("Configuration.StandardSequences.GeometryECALHCAL_cff")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalDigis/data/2_0_0/simhits_pi50_etaphi44.root']

process.hcalRecoAnalyzer = cms.EDFilter("HcalRecHitsValidation",
    outputFile = cms.untracked.string('HcalRecHitsValidationHB.root'),
    eventype = cms.untracked.string('single'),
    mc = cms.untracked.string('yes'),
    sign = cms.untracked.string('*'),
    hcalselector = cms.untracked.string('HB'),
    ecalselector = cms.untracked.string('yes')
)

process.p = cms.Path(
 process.VtxSmeared * process.g4SimHits * process.mix *
 process.calDigi * 
 process.ecalPacker * process.hcalRawData *
 process.ecalDigis * process.hcalDigis *
 process.ecalGlobalUncalibRecHit * process.ecalDetIdToBeRecovered * process.ecalRecHit *
 process.hbhereco * process.horeco * process.hfreco *
 process.hcalRecoAnalyzer)
