import FWCore.ParameterSet.Config as cms

process = cms.Process("HCALRECHITSVALIDATION")
process.load("Configuration.StandardSequences.Simulation_cff")
process.load("Configuration.StandardSequences.GeometryHCAL_cff")

process.load("DQMServices.Core.DQM_cfg")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.source = cms.Source("PoolSource",
    debugFlag = cms.untracked.bool(True),
    debugVebosity = cms.untracked.uint32(10),
    fileNames = cms.untracked.vstring(
   )
)

process.hcalRecoAnalyzer = cms.EDFilter("HcalRecHitsValidation",
    eventype = cms.untracked.string('single'),
    outputFile = cms.untracked.string('HcalRecHitsValidationZS.root'),
    ecalselector = cms.untracked.string('no'),
    mc = cms.untracked.string('no'),
    hcalselector = cms.untracked.string('ZS')
)

process.DQM.collectorHost = ''

process.p = cms.Path(process.hcalRecoAnalyzer)

