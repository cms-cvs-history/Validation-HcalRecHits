// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{

   TCanvas *myc = new TCanvas("myc","",800,600);
      
   TFile f1("~/Validation/170_on_simhits_170/CaloTowersValidationALL.root");
   TFile f2("~/Validation/180_pre5_on_simhits_170/CaloTowersValidationALL.root");

   
   // service variables
   //
   const int Nhist1  = 1; // just dummy 
   const int Nhist2  = 6;
   const int Nhist2p = Nhist2; // profile hist analogous to 2D
   const int Nprof   = 4;

   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];

   TH2F*     f1_hist2[Nhist2];
   TH2F*     f2_hist2[Nhist2];
   TProfile* f1_histp[Nhist2p];
   TProfile* f2_histp[Nhist2p];

   TProfile* f1_prof[Nprof];
   TProfile* f2_prof[Nprof];

   char *label1[Nhist1];
   char *label2[Nhist2];
   char *labelp[Nprof];


   //   label1[0] = &"HcalRecHitTask_energy_in_cone_HF_gamma.gif";

   label2[0] = &"HcalRecHitTask_energy_rechits_vs_simhits_HB.gif";
   label2[1] = &"HcalRecHitTask_energy_rechits_vs_simhits_HE.gif";
   label2[2] = &"HcalRecHitTask_energy_rechits_vs_simhits_HO.gif";
   label2[3] = &"HcalRecHitTask_energy_rechits_vs_simhits_HF.gif";
   label2[4] = &"HcalRecHitTask_energy_rechits_vs_simhits_HFL.gif";
   label2[5] = &"HcalRecHitTask_energy_rechits_vs_simhits_HFS.gif";

   labelp[0] = &"HcalRecHitTask_En_rechits_cone_profile_vs_eta_depth1.gif";
   labelp[1] = &"HcalRecHitTask_En_rechits_cone_profile_vs_eta_depth2.gif";
   labelp[2] = &"HcalRecHitTask_En_rechits_cone_profile_vs_eta_depth3.gif";
   labelp[3] = &"HcalRecHitTask_En_rechits_cone_profile_vs_eta_depth4.gif";


   f1->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f1_hist2[0] = HcalRecHitTask_energy_rechits_vs_simhits_HB;
   f1_hist2[1] = HcalRecHitTask_energy_rechits_vs_simhits_HE;
   f1_hist2[2] = HcalRecHitTask_energy_rechits_vs_simhits_HO;
   f1_hist2[3] = HcalRecHitTask_energy_rechits_vs_simhits_HF;
   f1_hist2[4] = HcalRecHitTask_energy_rechits_vs_simhits_HFL;
   f1_hist2[5] = HcalRecHitTask_energy_rechits_vs_simhits_HFS;

   f1_histp[0] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HB;
   f1_histp[1] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HE;
   f1_histp[2] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HO;
   f1_histp[3] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HF;
   f1_histp[4] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HFL;
   f1_histp[5] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HFS;

   f1_prof[0] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth1;
   f1_prof[1] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth2;
   f1_prof[2] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth3;
   f1_prof[3] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth4;

   f2->cd("DQMData/HcalRecHitsV/HcalRecHitTask");
   gDirectory->pwd();
   f2_hist2[0] = HcalRecHitTask_energy_rechits_vs_simhits_HB;
   f2_hist2[1] = HcalRecHitTask_energy_rechits_vs_simhits_HE;
   f2_hist2[2] = HcalRecHitTask_energy_rechits_vs_simhits_HO;
   f2_hist2[3] = HcalRecHitTask_energy_rechits_vs_simhits_HF;
   f2_hist2[4] = HcalRecHitTask_energy_rechits_vs_simhits_HFL;
   f2_hist2[5] = HcalRecHitTask_energy_rechits_vs_simhits_HFS;

   f2_histp[0] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HB;
   f2_histp[1] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HE;
   f2_histp[2] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HO;
   f2_histp[3] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HF;
   f2_histp[4] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HFL;
   f2_histp[5] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HFS;

   f2_prof[0] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth1;
   f2_prof[1] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth2;
   f2_prof[2] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth3;
   f2_prof[3] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth4;

   //
   f1_hist2[0]->GetXaxis()->SetTitle("HB RecHits energy vs SimHits energy (GeV)");
   f1_hist2[1]->GetXaxis()->SetTitle("HE RecHits energy vs SimHits energy (GeV)");
   f1_hist2[2]->GetXaxis()->SetTitle("HO RecHits energy vs SimHits energy (GeV)");
   f1_hist2[3]->GetXaxis()->SetTitle("HF RecHits energy vs SimHits energy (GeV)");
   f1_hist2[4]->GetXaxis()->SetTitle("HFL RecHits energy vs SimHits energy (GeV)");
   f1_hist2[5]->GetXaxis()->SetTitle("HFS RecHits energy vs SimHits energy (GeV)");

   f1_prof[0]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) depth1");
   f1_prof[1]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) depth2");
   f1_prof[2]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) depth3");
   f1_prof[3]->GetXaxis()->SetTitle("Mean energy vs ieta (GeV) depth4");


   //
   f1_prof[0]->SetMaximum(40.);
   f1_prof[1]->SetMaximum(20.);
   f1_prof[2]->SetMaximum(10.);
   f1_prof[3]->SetMaximum(3.);

   f1_hist2[0]->GetXaxis()->SetRangeUser(0.,0.6);
   f1_hist2[1]->GetXaxis()->SetRangeUser(0.,0.6);
   f1_hist2[2]->GetXaxis()->SetRangeUser(0.,0.4);
   f1_hist2[3]->GetXaxis()->SetRangeUser(0.,30.);
   f1_hist2[4]->GetXaxis()->SetRangeUser(0.,20.);
   f1_hist2[5]->GetXaxis()->SetRangeUser(0.,20.);

   f1_hist2[0]->GetYaxis()->SetRangeUser(0.,100.);
   f1_hist2[1]->GetYaxis()->SetRangeUser(0.,100.);
   f1_hist2[2]->GetYaxis()->SetRangeUser(0.,100);
   f1_hist2[3]->GetYaxis()->SetRangeUser(0.,120.);
   f1_hist2[4]->GetYaxis()->SetRangeUser(0.,100.);
   f1_hist2[5]->GetYaxis()->SetRangeUser(0.,100.);

   // f1_hist[2]->GetXaxis()->SetRangeUser(0.,1200.);
   // f1_hist[7]->GetXaxis()->SetRangeUser(0.,160.);
   // hist1->GetXaxis()->SetNdivisions(-21);
   // hist1->GetYaxis()->SetNdivisions(-1003);


   //  Profiles
  for (int i = 0; i < Nprof; i++){

    f1_prof[i]->SetStats(kFALSE);   
    f2_prof[i]->SetStats(kFALSE); 
    
    f1_prof[i]->SetTitle("");
    f2_prof[i]->SetTitle("");


    f1_prof[i]->SetLineColor(41);
    f1_prof[i]->SetLineStyle(1);     
    f1_prof[i]->SetLineWidth(1); 
    f1_prof[i]->SetMarkerColor(41);
    f1_prof[i]->SetMarkerStyle(21);
    f1_prof[i]->SetMarkerSize(0.8);  

    f2_prof[i]->SetLineColor(42);
    f2_prof[i]->SetLineStyle(1);  
    f2_prof[i]->SetLineWidth(1); 
    f2_prof[i]->SetMarkerColor(42);
    f2_prof[i]->SetMarkerStyle(22);
    f2_prof[i]->SetMarkerSize(1.0);  

    myc->SetGrid();

    f1_prof[i]->Draw("hist pl");   
    f2_prof[i]->Draw("hist pl same");   

    TLegend *leg = new TLegend(0.68, 0.82, 0.98, 0.97, "","brNDC");    
     leg->SetBorderSize(2);
     leg->SetFillStyle(1001); 
     leg->AddEntry(f1_prof[i],"CMSSW_170","pl");
     leg->AddEntry(f2_prof[i],"CMSSW_180","pl");

     leg->Draw("");   
     
     myc->SaveAs(labelp[i]);

  }


   //  2D-histo
  for (int i = 0; i < Nhist2; i++){

    f1_hist2[i]->SetStats(kFALSE);   
    f2_hist2[i]->SetStats(kFALSE); 
    
    f1_hist2[i]->SetTitle("");
    f2_hist2[i]->SetTitle("");

    f1_hist2[i]->SetLineColor(2);
    f1_hist2[i]->SetLineWidth(2); 
    f1_hist2[i]->SetMarkerColor(41);
    f1_hist2[i]->SetMarkerStyle(20);
    f1_hist2[i]->SetMarkerSize(0.02);  

    f2_hist2[i]->SetLineColor(3);
    f2_hist2[i]->SetLineWidth(3); 
    f2_hist2[i]->SetMarkerColor(42);
    f2_hist2[i]->SetMarkerStyle(20);
    f2_hist2[i]->SetMarkerSize(0.02);  

    f1_hist2[i]->Draw("P");   
    f2_hist2[i]->Draw("PSAME");   

    // rechits vs simhits 
      f1_histp[i]->SetLineColor(2);
      f1_histp[i]->SetLineStyle(1);     
      f1_histp[i]->SetLineWidth(2); 
      
      f1_histp[i]->Draw("e same");
      
      f2_histp[i]->SetLineColor(3);
      f2_histp[i]->SetLineStyle(1);     
      f2_histp[i]->SetLineWidth(2);
 
      f2_histp[i]->Draw("e same");
    
 
    TLegend *leg = new TLegend(0.38, 0.82, 0.68, 0.97, "","brNDC");    
     leg->SetBorderSize(2);
     leg->SetFillStyle(1001); 
     leg->AddEntry(f1_hist2[i],"CMSSW_173","l");
     leg->AddEntry(f2_hist2[i],"CMSSW_180","l");

     leg->Draw();   
     
     myc->SaveAs(label2[i]);

  }

   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
     
}
