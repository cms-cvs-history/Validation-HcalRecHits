// Commands executed in a GLOBAL scope, e.g. created hitograms aren't erased...
{

   TCanvas *myc = new TCanvas("myc","",800,600);
      
   TFile f1("~/Validation/173_on_simhits_173/CaloTowersValidationHO.root");
   TFile f2("~/Validation/180_pre5_on_simhits_180_pre5/CaloTowersValidationHO.root");

   
   // service variables
   //
   const int Nhist1 = 2;
   const int Nhist2 = 2;
   const int Nprof  = 2;
   const int Nprof1 = 1;

   TH1F* f1_hist1[Nhist1];
   TH1F* f2_hist1[Nhist1];

   TH2F*     f1_hist2[Nhist2];
   TProfile* f1_histp[Nprof];

   TH2F*     f2_hist2[Nhist2];
   TProfile* f2_histp[Nprof];
 
   TProfile* f1_prof[Nprof1];
   TProfile* f2_prof[Nprof1];


   char *label1[Nhist1];
   char *label2[Nhist2];
   char *labelp[Nhist2];

   label1[0] = &"HcalRecHitTask_number_of_rechits_above_1GeV_HO.gif";
   label1[1] = &"HcalRecHitTask_sum_of_rechits_energy_in_cone_HO.gif";

   label2[0] = &"HcalRecHitTask_energy_rechits_vs_simhits_HO.gif";
   label2[1] = &"HcalRecHitTask_timing_vs_energy_HO.gif";

   labelp[0] = &"HcalRecHitTask_En_rechits_cone_profile_vs_eta_HO.gif";

   f1->cd("DQMData/HcalRecHitTask");
   gDirectory->pwd();
   f1_hist1[0] = HcalRecHitTask_number_of_rechits_above_1GeV_HO;
   f1_hist1[1] = HcalRecHitTask_sum_of_rechits_energy_in_cone_HO;

   f1_hist2[0] = HcalRecHitTask_energy_rechits_vs_simhits_HO;
   f1_histp[0] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HO; 
   f1_hist2[1] = HcalRecHitTask_timing_vs_energy_HO;

   f1_prof[0] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth4;

   f2->cd("DQMData/HcalRecHitTask");
   gDirectory->pwd();
   f2_hist1[0] = HcalRecHitTask_number_of_rechits_above_1GeV_HO;
   f2_hist1[1] = HcalRecHitTask_sum_of_rechits_energy_in_cone_HO;

   f2_hist2[0] = HcalRecHitTask_energy_rechits_vs_simhits_HO;
   f2_histp[0] = HcalRecHitTask_energy_rechits_vs_simhits_profile_HO; 
   f2_hist2[1] = HcalRecHitTask_timing_vs_energy_HO;

   f2_prof[0] = HcalRecHitTask_En_rechits_cone_profile_vs_ieta_depth4;


   f1_hist1[0]->GetXaxis()->SetTitle("HO N_{rechits} > 1 GeV");
   f1_hist1[1]->GetXaxis()->SetTitle("HO hcal energy in cone (GeV)");

   f1_hist2[0]->GetXaxis()->SetTitle("HO RecHits energy vs SimHits energy (GeV)");
   f1_hist2[1]->GetXaxis()->SetTitle("HO timing vs energy");

   f1_prof[0]->GetXaxis()->SetTitle("HO mean energy vs eta");

   // f1_hist[0]->SetMaximum(600.);

   // f1_hist[2]->GetXaxis()->SetRangeUser(0.,1200.);
   // f1_hist[7]->GetXaxis()->SetRangeUser(0.,160.);
   // hist1->GetXaxis()->SetNdivisions(-21);
   // hist1->GetYaxis()->SetNdivisions(-1003);



   //  1D-histo

   for (int i = 0; i < Nhist1; i++){

    f1_hist1[i]->SetStats(kFALSE);   
    f2_hist1[i]->SetStats(kFALSE); 
    
    f1_hist1[i]->SetTitle("");
    f2_hist1[i]->SetTitle("");

    f1_hist1[i]->SetLineWidth(2); 
    f2_hist1[i]->SetLineWidth(3); 
    
    // diffferent histo colors and styles
    f1_hist1[i]->SetLineColor(41);
    f1_hist1[i]->SetLineStyle(1); 
    
    f2_hist1[i]->SetLineColor(42);
    f2_hist1[i]->SetLineStyle(2);  


     //     if(i == 0 ) {
       TLegend *leg = new TLegend(0.68, 0.82, 0.98, 0.97, "","brNDC");
       //     }
       //     else {
       //       TLegend *leg = new TLegend(0.08, 0.6, 0.38, 0.85, "","brNDC");
       //     }

     leg->SetBorderSize(2);
     //  leg->SetFillColor(51); // see new color definition above
     leg->SetFillStyle(1001); //
     leg->AddEntry(f1_hist1[i],"CMSSW_170","l");
     leg->AddEntry(f2_hist1[i],"CMSSW_180","l");

     gPad->SetLogy(1);

     f1_hist1[i]->Draw("hist");   
     f2_hist1[i]->Draw("hist same");   

     leg->Draw();   
     
     myc->SaveAs(label1[i]);
   }     

   gPad->SetLogy(0);


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
    f1_hist2[i]->SetMarkerSize(0.2);  
    if(i == 0) f1_hist2[i]->SetMarkerSize(0.02);  


    f2_hist2[i]->SetLineColor(3);
    f2_hist2[i]->SetLineWidth(3); 
    f2_hist2[i]->SetMarkerColor(42);
    f2_hist2[i]->SetMarkerStyle(20);
    f2_hist2[i]->SetMarkerSize(0.2);  
    if(i == 0) f2_hist2[i]->SetMarkerSize(0.02);  

    f1_hist2[i]->Draw("P");   
    f2_hist2[i]->Draw("PSAME");   

    if(i == 0) { // rechits vs simhits 
      f1_histp[i]->SetLineColor(2);
      f1_histp[i]->SetLineStyle(1);     
      f1_histp[i]->SetLineWidth(2); 
      
      f1_histp[i]->Draw("e same");
      
      f2_histp[i]->SetLineColor(3);
      f2_histp[i]->SetLineStyle(1);     
      f2_histp[i]->SetLineWidth(2);
 
      f2_histp[i]->Draw("e same");
    }
 
    TLegend *leg = new TLegend(0.38, 0.82, 0.68, 0.97, "","brNDC");    
     leg->SetBorderSize(2);
     leg->SetFillStyle(1001); 
     leg->AddEntry(f1_hist2[i],"CMSSW_170","l");
     leg->AddEntry(f2_hist2[i],"CMSSW_180","l");

     leg->Draw();   
     
     myc->SaveAs(label2[i]);

  }

   myc->SetGrid();

   //  Profiles
   for (int i = 0; i < Nprof1; i++){   // NB !!! - single profile

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


   // close ROOT files
   //
   f1.Close() ;  
   f2.Close() ;
   
   return ;  
     
}
