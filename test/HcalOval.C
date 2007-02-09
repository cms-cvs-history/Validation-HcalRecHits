#include <iostream>
// comparison of digi histograms with reference ones.
//  root -b -q hcaloval.C\(\"HB\"\) - just for PV comparison.
//  root -b -q hcaloval.C\(\"HB\",\"gif\"\) - PV comparison and creation of gif for each histo
//  root -b -q hcaloval.C\(\"HB\",\"ps\"\) - PV comparison and creation of ps file for each subdetector

#include "TFile.h"
#include "TTree.h"
#include "TText.h"
#include "TStyle.h"
#include "TPostScript.h"
#include "TString.h"

class HcalOval
{
public:
  HcalOval(const char* runtype, const char* drawhisto="none", bool kNoise = 0, string path2ref = "../data/", string path2data ="");
  ~HcalOval();

  void process(string name, string subdet);
  void runStandard();
  void runAll();


private:
  string run;
  string drawhist;
  string path2ref;
  string path2data;
  bool isNoise;
  TFile * rfile;
  TFile * sfile;
  TCanvas * canvas;
  TPostScript * ps;
  bool isNoise;
};


HcalOval::HcalOval(const char* runtype, const char* drawhisto, bool kNoise,string path2ref, string path2data )
: run(runtype),
  drawhist(drawhisto),
  isNoise(kNoise),
  rfile(0),
  sfile(0),
  canvas(0),
  ps(0)
{
  gROOT->Reset();
  if(drawhist == "ps"){
    canvas = new TCanvas("Hcal","Hcal",0,0,707,500 );
    string figure = "figure";
    figure += run;
    figure += ".ps";
    ps = new TPostScript(figure.c_str() , -112);
    ps->Range(29.7 , 21.0);
  }

  string PathToRef = "../data/";
  string rfilename;
  
  rfilename = path2ref+ "HcalRecHitValidation" +run + "_ref.root";
  string sfilename;
  sfilename = path2data + "HcalRecHitValidation" +run + ".root";
  if (isNoise)
    {
      rfilename = PathToRef+ "HcalRecHitValidation" +run + "noise_ref.root";
      string sfilename= "";
      sfilename = sfilename +  "HcalRecHitValidation" +run + "noise.root";
    }

  cout << "Reference file : " << rfilename << endl;
  cout << "New file : " << sfilename << endl;
  delete gROOT->GetListOfFiles()->FindObject(rfilename.c_str());
  delete gROOT->GetListOfFiles()->FindObject(sfilename.c_str());

  // TText* te = new TText();
  // te->SetTextSize(0.1);
  rfile = new TFile(rfilename.c_str());
  sfile = new TFile(sfilename.c_str());
  rfile->cd("DQMData/HcalRecHitTask");
  gDirectory->ls();

  sfile->cd("DQMData/HcalRecHitTask");
  gDirectory->ls();

  gStyle->SetOptStat("n");

  gROOT->ProcessLine(".x HistoCompare.C");

  runAll();

}

HcalOval::~HcalOval()
{
  if (drawhist == "ps") ps->Close();
}


void HcalOval::process(string histname, string subdet)
{
  TH1 * oldHist;
  TH1 * newHist;
  string tname = histname + "_"+ subdet + ";1";

  std::cout << "PROCESS " << tname << std::endl;
   
  rfile->GetObject(tname.c_str(), oldHist);
  sfile->GetObject(tname.c_str(), newHist); 

  HistoCompare comp;
  char * addname = "";
  
  if (isNoise) addname = "_noise";

  comp.PVCompute(oldHist, newHist, drawhist.c_str(), addname);

  if (drawhist == "ps") 
  { 
    canvas->Update(); 
    ps->NewPage();
  }
}


void HcalOval::runNoise()
{
  string histname = "DQMData/HcalRecHiTask/HcalRecHitTask_sum_over_digis(fC)";
  process(histname, "noise_HB");
  process(histname, "noise_HE");
  process(histname, "noise_HF");
  process(histname, "noise_HO");
  histname = "DQMData/HcalRecHitTask/HcalRecHitTask_pedestal";
  process(histname, "HB");
  process(histname, "HE");
  process(histname, "HF");
  process(histname, "HO");

}


void HcalOval::runStandard()
{
  if (isNoise){
    //   process("DQMData/HcalRecHitTask/HcalRecHitTask_eta_of_rechits", run);
    // process("DQMData/HcalRecHitTask/HcalRecHitTask_phi_of_rechits", run);
    process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_ecal_plus_hcal", run);
    process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_ecal_plus_hcal_in_cone", run);
    //process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_of_rechits", run);
    process("DQMData/HcalRecHitTask/HcalRecHitTask_number_of_rechits_above_1GeV", run);
    //process("DQMData/HcalRecHitTask/HcalRecHitTask_number_of_rechits", run);
    process("DQMData/HcalRecHitTask/HcalRecHitTask_number_of_rechits_in_cone", run);
    process("DQMData/HcalRecHitTask/HcalRecHitTask_sum_of_rechits_energy", run);
    process("DQMData/HcalRecHitTask/HcalRecHitTask_sum_of_rechits_energy_in_cone", run);
    process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_rechits_vs_simhits_profile", run);
  } 
  else
    {
      process("DQMData/HcalRecHitTask/HcalRecHitTask_eta_of_rechits", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_phi_of_rechits", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_ecal_plus_hcal", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_ecal_plus_hcal_in_cone", run);
      // process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_of_rechits", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_number_of_rechits_above_1GeV", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_number_of_rechits", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_number_of_rechits_in_cone", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_sum_of_rechits_energy", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_sum_of_rechits_energy_in_cone", run);
      process("DQMData/HcalRecHitTask/HcalRecHitTask_energy_rechits_vs_simhits_profile", run);
    }
}

 

void HcalOval::runAll()
{

    runStandard();

}


