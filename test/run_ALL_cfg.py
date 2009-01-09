import FWCore.ParameterSet.Config as cms

process = cms.Process("HCALRECHITSVALIDATION")
process.load("Validation.HcalRecHits.HcalRecHitsValidation_cfi")
process.load("Configuration.StandardSequences.GeometryHCAL_cff")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalDigis/data/2_0_0/simhits_pi50_eta05.root']

process.hcalRecoAnalyzer = cms.EDFilter("HcalRecHitsValidation",
    eventype = cms.untracked.string('single'),
    outputFile = cms.untracked.string('HcalRecHitsValidationALL.root'),
    ecalselector = cms.untracked.string('no'),
    hcalselector = cms.untracked.string('all')
)

process.p = cms.Path(process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.horeco*process.hfreco*process.hcalRecoAnalyzer)

