import FWCore.ParameterSet.Config as cms

process = cms.Process("HCALRECHITSVALIDATION")
process.load("Validation.HcalRecHits.HcalRecHitsValidation_cfi")
process.load("Configuration.StandardSequences.GeometryHCAL_cff")

process.PoolSource.fileNames = ['file:/afs/cern.ch/cms/data/CMSSW/Validation/HcalDigis/data/2_0_0/simhits_noise.root']

process.hcalRecoAnalyzer = cms.EDFilter("HcalRecHitsValidation",
    outputFile = cms.untracked.string('HcalRecHitsValidationNoise.root'),
    eventype = cms.untracked.string('single'),
    mc = cms.untracked.string('yes'),
    sign = cms.untracked.string('*'),
    hcalselector = cms.untracked.string('noise'),
    ecalselector = cms.untracked.string('no')
)

process.simHcalDigis.HBlevel = -1000
process.simHcalDigis.HElevel = -1000
process.simHcalDigis.HOlevel = -1000
process.simHcalDigis.HFlevel = -1000

process.hbhereco.digiLabel = 'simHcalDigis'
process.horeco.digiLabel = 'simHcalDigis'
process.hfreco.digiLabel = 'simHcalDigis'

process.p = cms.Path(process.mix*process.simHcalUnsuppressedDigis*process.simHcalDigis*process.hbhereco*process.horeco*process.hfreco*process.hcalRecoAnalyzer)
