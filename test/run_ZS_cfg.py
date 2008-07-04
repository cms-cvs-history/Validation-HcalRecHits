import FWCore.ParameterSet.Config as cms

process = cms.Process("HCALRECHITSVALIDATION")
process.load("Configuration.StandardSequences.Simulation_cff")

process.load("DQMServices.Core.DQM_cfg")

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(-1)
)
process.source = cms.Source("PoolSource",
    debugFlag = cms.untracked.bool(True),
    debugVebosity = cms.untracked.uint32(10),
    fileNames = cms.untracked.vstring('rfio:/castor/cern.ch/cms/store/data/GlobalNov07/DTHcal/000/030/260/RAW/0000/FC53D7F5-38A3-DC11-98B4-001617DBCF44.root', 
        'rfio:/castor/cern.ch/cms/store/data/GlobalNov07/DTHcal/000/030/260/RAW/0000/801C824E-39A3-DC11-A1A3-001617DBD4C4.root', 
        'rfio:/castor/cern.ch/cms/store/data/GlobalNov07/DTHcal/000/030/260/RAW/0000/1C633F54-39A3-DC11-A2EC-000423D6CA42.root')
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

