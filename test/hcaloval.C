
#include <iostream.h>
#include "TFile.h"
#include "TTree.h"
#include "TText.h"

void hcaloval(const char* run = "HB", const char* noise = "noise", const char* drawhist = "none"){
  gROOT ->Reset();
  if (drawhist == "ps"){
    TCanvas *hcal = new TCanvas("Hcal","Hcal",0,0,707,500 );
    TString figure;
    figure = "figure";
    figure += run;
    figure += ".ps";
    ps = new TPostScript(figure , -112);
    ps->Range(29.7 , 21.0);
  }

  char name[50] ;
  char det[10] = run;
 
  TString PathToRef = "../data/";
  TString PathToRef = "NEWFILE/";
  TString rfilename;
  //  rfilename = PathToRef+ "HcalRecHitValidation" +run + noise + "_ref.root";
   rfilename = PathToRef+ "HcalRecHitValidation" +run + noise + ".root"; 

  TString sfilename= "";
  sfilename = sfilename +  "HcalRecHitValidation" +run + noise + ".root";


  delete gROOT->GetListOfFiles()->FindObject(rfilename);
  delete gROOT->GetListOfFiles()->FindObject(sfilename);

  // TText* te = new TText();
  // te->SetTextSize(0.1);
  TFile * rfile = new TFile(rfilename);
  TFile * sfile = new TFile(sfilename);

  rfile->cd("DQMData/HcalRecHitTask");
  gDirectory->ls();

  sfile->cd("DQMData/HcalRecHitTask");
  gDirectory->ls();

  Char_t histo[200];

  gStyle->SetOptStat("n");

  gROOT->ProcessLine(".x HistoCompare.C");
  HistoCompare * myPV = new HistoCompare();
  TString hname;

  TH2* meOld2;
  TH2* meNew2;
    
    hname = "DQMData/HcalRecHitTask/HcalRecHitTask_energy_RecHits_vs_SimHits_";
    hname = hname + run + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld2  );  

    sfile->GetObject(hname ,  meNew2 );
    myPV->PVCompute(meOld2 ,meNew2 , "gif",noise);


    TH1* meOld;
    hname = "DQMData/HcalRecHitTask/HcalRecHitTask_Eta_of_RecHits_";
    hname = hname + run + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  );
 
    TH1* meNew;
    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif", noise);


    hname = "DQMData/HcalRecHitTask/HcalRecHitTask_Phi_of_RecHits_"; 
    hname = hname + run + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  ); 

    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif",noise);

    if( run == "HB" || run == "HE"){
    hname = "DQMData/HcalRecHitTask/HcalRecHitTask_energy_Hcal_vs_Ecal_";
    hname = hname + run + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  );  

    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif",noise);
    }
    
    hname = "DQMData/HcalRecHitTask/HcalRecHitTask_energy_RecHits_vs_SimHits_profile_";
    hname = hname + run + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  );  

    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif",noise);
  

  

  hname = "DQMData/HcalRecHitTask/HcalRecHitTask_energy_ecal+hcal_";
  hname = hname + run + ";1";
  cout << "Processing: " <<  hname << endl;
  rfile->GetObject(hname  , meOld  ); 

  sfile->GetObject(hname ,  meNew );
  myPV->PVCompute(meOld ,meNew , "gif",noise);

 if (run != "HE"){
  hname = "DQMData/HcalRecHitTask/HcalRecHitTask_energy_ecal+hcal_in_cone_";
  hname = hname + run + ";1";
  cout << "Processing: " <<  hname << endl;
  rfile->GetObject(hname  , meOld  ); 

  sfile->GetObject(hname ,  meNew );
  myPV->PVCompute(meOld ,meNew , "gif",noise);
 }

  hname = "DQMData/HcalRecHitTask/HcalRecHitTask_number_of_EcalRecHits_in_cone_";
  hname = hname + run + ";1";
  cout << "Processing: " <<  hname << endl;
  rfile->GetObject(hname  , meOld  ); 

  sfile->GetObject(hname ,  meNew );
  myPV->PVCompute(meOld ,meNew , "gif",noise);

  hname = "DQMData/HcalRecHitTask/HcalRecHitTask_number_of_HcalRecHits_above_1GeV_";
  hname = hname + run + ";1";
  cout << "Processing: " <<  hname << endl;
  rfile->GetObject(hname  , meOld  ); 

  sfile->GetObject(hname ,  meNew );
  myPV->PVCompute(meOld ,meNew , "gif",noise);
 
  if (run != "HO"){
    hname = "DQMData/HcalRecHitTask/HcalRecHitTask_sum_of_RecHits_energy_";
 
    hname = hname + run + ";1";
    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  ); 

    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif",noise);
  

    hname = "DQMData/HcalRecHitTask/HcalRecHitTask_sum_of_RecHits_in_cone_";
    hname = hname + run + ";1";

    cout << "Processing: " <<  hname << endl;
    rfile->GetObject(hname  , meOld  ); 
    cout << "dfdd" << endl;
    sfile->GetObject(hname ,  meNew );
    myPV->PVCompute(meOld ,meNew , "gif",noise);

  }
} 

  
