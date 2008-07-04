import FWCore.ParameterSet.Config as cms

process = cms.Process("HCALRECHITSVALIDATION")
process.load("Validation.HcalRecHits.HcalRecHitsValidation_cfi")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalDigis/data/2_0_0/simhits_noise.root']

process.hcalRecoAnalyzer = cms.EDFilter("HcalRecHitsValidation",
    outputFile = cms.untracked.string('HcalRecHitsValidationNoise.root'),
    eventype = cms.untracked.string('single'),
    mc = cms.untracked.string('yes'),
    sign = cms.untracked.string('*'),
    hcalselector = cms.untracked.string('noise'),
    ecalselector = cms.untracked.string('no')
)

process.simHcalDigis.hbhe.level = -10000
process.simHcalDigis.ho.level = -10000
process.simHcalDigis.hf.level = -10000

process.p = cms.Path(process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.horeco*process.hfreco*process.hcalRecoAnalyzer)
